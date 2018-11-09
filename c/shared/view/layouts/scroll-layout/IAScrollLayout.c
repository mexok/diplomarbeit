#include "IALibrary.h"
#include "IAScrollLayout.h"
#include "IATouchDelegate.h"
#include "IATouchManager.h"
#include "IAMath.h"

#define CLASSNAME "IAScrollLayout"


static void IAScrollLayout_startScrolling(IAScrollLayout * this, IATouch touch);
static void IAScrollLayout_doScroll(IAScrollLayout * this, IATouch touch);
static void IAScrollLayout_endCurrentScolling(IAScrollLayout * this);

static void draw(const IAScrollLayout *);
static void setRect(IAScrollLayout *, IARect);
static void updateContent(IAScrollLayout *);


static bool IAScrollLayout_wantToUseTouch(IAScrollLayout * this, IATouch touch) {
	IARect rect = IAScrollLayout_getRect(this);
	return IARect_isPointWithin(rect, touch.location);
}

static bool IAScrollLayout_wantToConsumeTouch(IAScrollLayout * this, IATouch touch) {
	return false;
}

static void IAScrollLayout_onTouchBegan(IAScrollLayout * this, size_t numTouches, IATouch touches[numTouches]) {
	for(size_t i = 0; i < numTouches; i++) {
		if (IAScrollLayout_isScrolling(this)) {
			IAScrollLayout_endCurrentScolling(this);
		}
		IAScrollLayout_startScrolling(this, touches[i]);
	}
}

static void IAScrollLayout_onTouchMoved(IAScrollLayout * this, size_t numTouches, IATouch touches[numTouches]) {
	for(size_t i = 0; i < numTouches; i++) {
		if (IAScrollingData_isCurrentTouch(this->scrollingData, touches[i])) {
			IAScrollLayout_doScroll(this, touches[i]);
		}
	}
}

static void IAScrollLayout_onTouchEnded(IAScrollLayout * this, size_t numTouches, IATouch touches[numTouches]) {
	for(size_t i = 0; i < numTouches; i++) {
		if (IAScrollingData_isCurrentTouch(this->scrollingData, touches[i])) {
			IAScrollingData_removeAllOldTouchEvents(this->scrollingData, this->getTime());
			IAScrollLayout_doScroll(this, touches[i]);
			IAScrollLayout_endCurrentScolling(this);
		}
	}
}

static void IAScrollLayout_onTouchCanceled(IAScrollLayout * this) {
	if (IAScrollLayout_isScrolling(this)) {
		IAScrollingData_removeAllOldTouchEvents(this->scrollingData, this->getTime());
		IAScrollLayout_endCurrentScolling(this);
	}
}

void IAScrollLayout_init(IAScrollLayout * this, const IAScrollLayoutAttributes * attr) {
	IAOverscrollingBehavior behavior = IAScrollLayoutAttributes_getOverscrollingBehavior(attr);
	float decelerationForScrollingInPixelPerTimeUnitSquared = IAScrollLayoutAttributes_getDecelerationForScrollingInPixelPerTimeUnitSquared(attr);
	*this = (IAScrollLayout) {
			.base = IAObject_make(this),
			.content = IAScrollLayoutAttributes_getContent(attr),
			.contentLength = IAScrollLayoutAttributes_getContentLength(attr),
			.isHorizontal = IAScrollLayoutAttributes_isHorizontal(attr),
			.scrollingData = IAScrollingData_new(decelerationForScrollingInPixelPerTimeUnitSquared),
			.overscrollingHandler = IAOverscrollingHandler_new(behavior),
			.thresholdInPixelForOnScrollBeginCall = IAScrollLayoutAttributes_getThresholdInPixelForOnScrollBeginCall(attr),
			.getTime = IAScrollLayoutAttributes_getGetTimeFunction(attr)
	};
	IADrawableRect_retain(this->content);
	IALayout_init((IALayout *) this, (IADrawable_drawFunction) draw, (IADrawableRect_setRectFunction) setRect, (const IALayoutAttributes *) attr);

	IATouchDelegateAttributes touchDelegateAttr;
	IATouchDelegateAttributes_make(&touchDelegateAttr, this);
	IATouchDelegateAttributes_setWantToUseTouchFunction(&touchDelegateAttr, (bool(*)(void *, IATouch)) IAScrollLayout_wantToUseTouch);
	IATouchDelegateAttributes_setWantToConsumeTouchFunction(&touchDelegateAttr, (bool(*)(void *, IATouch)) IAScrollLayout_wantToConsumeTouch);
	IATouchDelegateAttributes_setOnTouchBeganFunction(&touchDelegateAttr, (void(*)(void *, size_t, IATouch[])) IAScrollLayout_onTouchBegan);
	IATouchDelegateAttributes_setOnTouchMovedFunction(&touchDelegateAttr, (void(*)(void *, size_t, IATouch[])) IAScrollLayout_onTouchMoved);
	IATouchDelegateAttributes_setOnTouchEndedFunction(&touchDelegateAttr, (void(*)(void *, size_t, IATouch[])) IAScrollLayout_onTouchEnded);
	IATouchDelegateAttributes_setOnTouchCanceledFunction(&touchDelegateAttr, (void(*)(void *)) IAScrollLayout_onTouchCanceled);
	IATouchDelegateAttributes_setZOrder(&touchDelegateAttr, IAScrollLayoutAttributes_getZOrder(attr));
	IATouchDelegate_init(&this->touchDelegate, &touchDelegateAttr);

	IAScrollLayoutEvent_init(&this->scrollEvents);
	IA_incrementInitCount();
}

static float IAScrollLayout_getScrollLength(const IAScrollLayout * this){
	IARect currentViewRect = IAScrollLayout_getRect(this);
	float viewLength = this->isHorizontal ? currentViewRect.size.width : currentViewRect.size.height;
	float scrollLength = this->contentLength - viewLength;
	scrollLength = fmaxf(scrollLength, 0.0f);
	return scrollLength;
}

bool IAScrollLayout_isScrollable(const IAScrollLayout * this){
	if (IAScrollLayout_getScrollLength(this) > 0.0f){
		return true;
	}else{
		return false;
	}
}

bool IAScrollLayout_isScrolling(const IAScrollLayout * this) {
	return IAScrollingData_isScrolling(this->scrollingData);
}

static void IAScrollLayout_startScrolling(IAScrollLayout * this, IATouch touch) {
	debugAssert(IAScrollLayout_isScrolling(this) == false);
	this->startTime = this->getTime();
	this->startScrollPos = this->currentScrollPos;
	this->last = touch.location;
	IAScrollingData_startScrolling(this->scrollingData, touch);
	IAScrollingData_appendNewTouchEvent(this->scrollingData, this->currentScrollPos, this->startTime);
}

static void IAScrollLayout_doScroll(IAScrollLayout * this, IATouch touch) {
	IAPoint current = touch.location;
	float scrollPosChange = this->isHorizontal ? this->last.x - current.x : this->last.y - current.y;
	IAOverscrollingHandler_modifyCurrentDragLengthIfNeeded(this->overscrollingHandler, &scrollPosChange);
	this->last = current;

	float scrollLength = IAScrollLayout_getScrollLength(this);
	this->currentScrollPos += scrollPosChange;
	if (this->currentScrollPos > scrollLength) {
		scrollPosChange = this->currentScrollPos - scrollLength;
		this->currentScrollPos = scrollLength;
	} else if (this->currentScrollPos < 0.0f)  {
		scrollPosChange = this->currentScrollPos;
		this->currentScrollPos = 0.0f;
	} else {
		scrollPosChange = 0.0f;
	}

	IAOverscrollingHandler_appendDragLength(this->overscrollingHandler, scrollPosChange);

	IAScrollingData_appendNewTouchEvent(this->scrollingData, this->currentScrollPos, this->getTime());

	updateContent(this);

	if (this->onScrollBeginCalled == false &&
	    fabsf(this->currentScrollPos - this->startScrollPos) > this->thresholdInPixelForOnScrollBeginCall) {
		this->onScrollBeginCalled = true;
		IAScrollLayoutEvent_onScrollBegin(&this->scrollEvents, this);
	}
}

static void IAScrollLayout_endCurrentScolling(IAScrollLayout * this) {
	debugAssert(IAScrollLayout_isScrolling(this));

	IAScrollingData_endScrolling(this->scrollingData);

	if (this->onScrollBeginCalled) {
		this->onScrollBeginCalled = false;
		IAScrollLayoutEvent_onScrollEnd(&this->scrollEvents, this);
	}
	this->startTime = this->getTime();
	this->currentTime = this->startTime;
	this->startScrollPos = this->currentScrollPos;
}

void IAScrollLayout_enableScrolling(IAScrollLayout * this, uint64_t currentTime) {
	IATouchManager_registerTouchDelegate(&this->touchDelegate);
	this->currentTime = currentTime;
}

void IAScrollLayout_updateTime(IAScrollLayout * this, uint64_t currentTime) {
	if (IAScrollLayout_isScrolling(this) == false) {
		IAOverscrollingHandler_scrollBack(this->overscrollingHandler, currentTime - this->currentTime);
		float scrollPosDiff = IAScrollingData_getScrollPosDiffInTimeInterval(this->scrollingData, this->currentTime, currentTime);
		this->currentScrollPos += scrollPosDiff;
		float scrollLength = IAScrollLayout_getScrollLength(this);
		if (this->currentScrollPos > scrollLength) {
			this->currentScrollPos = scrollLength;
		} else if (this->currentScrollPos < 0.0f) {
			this->currentScrollPos = 0.0f;
		}
		this->currentTime = currentTime;
		updateContent(this);
	}
}

void IAScrollLayout_disableScrolling(IAScrollLayout * this, uint64_t currentTime) {
	IAScrollLayout_updateTime(this, currentTime);
	IATouchManager_unregisterTouchDelegate(&this->touchDelegate);
}

float IAScrollLayout_getOverscrolling(IAScrollLayout * this) {
	return IAOverscrollingHandler_getAdditionalOffset(this->overscrollingHandler);
}

static void draw(const IAScrollLayout * this){
	IADrawableRect_draw(this->content);
}

static void setRect(IAScrollLayout * this, IARect rect){
	updateContent(this);
}

static void updateContent(IAScrollLayout * this){
	float scrollLength = IAScrollLayout_getScrollLength(this);
	if (this->currentScrollPos > scrollLength){
		this->currentScrollPos = scrollLength;
	}
	IARect contentRect = IAScrollLayout_getRect(this);
	if (this->isHorizontal){
		contentRect.size.width = this->contentLength;
		contentRect.origin.x -= this->currentScrollPos;
		contentRect.origin.y -= IAOverscrollingHandler_getAdditionalOffset(this->overscrollingHandler);
	}else{
		contentRect.size.height = this->contentLength;
		contentRect.origin.y -= this->currentScrollPos;
		contentRect.origin.y -= IAOverscrollingHandler_getAdditionalOffset(this->overscrollingHandler);
	}
	IADrawableRect_setRect(this->content, contentRect);
}

void IAScrollLayout_deinit(IAScrollLayout * this) {
	IADrawableRect_release(this->content);
	IAScrollingData_release(this->scrollingData);
	IAOverscrollingHandler_release(this->overscrollingHandler);
	IATouchDelegate_deinit(&this->touchDelegate);
	IAScrollLayoutEvent_deinit(&this->scrollEvents);
	IALayout_deinit((IALayout *) this);
	IA_decrementInitCount();
}

