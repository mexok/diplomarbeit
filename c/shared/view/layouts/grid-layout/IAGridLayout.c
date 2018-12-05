//
//  IAGridLayout.c
//


#include <math.h>
#include "IALibrary.h"
#include "IAGridLayout.h"

#define CLASSNAME "IAGridLayout"


static void draw(const IAGridLayout *);
static void setRect(IAGridLayout *, IARect);

void IAGridLayout_init(IAGridLayout *this, const IAGridLayoutAttributes * attr) {
	IALayout_init(
			(IALayout *) this,
			(IADrawable_drawFunction) draw,
			(IADrawableRect_setRectFunction) setRect,
			(const IALayoutAttributes *) attr);
	this->elementCount = IAGridLayoutAttributes_getElementCount(attr);
	this->elements = IA_malloc(sizeof(IAGridLayoutElement) * this->elementCount);
	const IAGridLayoutElement * elements = IAGridLayoutAttributes_getElements(attr);
	for (size_t i = 0; i < this->elementCount; i++) {
		IAGridLayoutElement_initCopy(this->elements + i, elements + i);
	}
	this->gridWidth = IAGridLayoutAttributes_getGridWidth(attr);
	this->gridHeight = IAGridLayoutAttributes_getGridHeight(attr);
	this->spacing = IAGridLayoutAttributes_getSpacing(attr);
	IA_incrementInitCount();
}

static void draw(const IAGridLayout * this){
	for (size_t i = 0; i < this->elementCount; i++) {
		IADrawableRect * content = IAGridLayoutElement_getContent(this->elements + i);
		IADrawableRect_draw(content);
	}
}

static bool isInsideGrid(IAGridLayout * this, size_t offsetX, size_t offsetY, IAGridLayoutElement * element){
	if (offsetX + IAGridLayoutElement_getWidth(element) <= this->gridWidth
		&& offsetY + IAGridLayoutElement_getHeight(element) <= this->gridHeight){
		return true;
	}else{
		return false;
	}
}

static void setRectOfElement(IAGridLayout * this, IARect gridRect, size_t offsetX, size_t offsetY, IAGridLayoutElement * element){
	float cellWidth = gridRect.size.width - (this->gridWidth - 1) * this->spacing;
	cellWidth /= this->gridWidth;
	cellWidth = fmaxf(cellWidth, 0.0f);
	float cellHeight = gridRect.size.height - (this->gridHeight - 1) * this->spacing;
	cellHeight /= this->gridHeight;
	cellHeight = fmaxf(cellHeight, 0.0f);

	float left = gridRect.origin.x;
	float top = gridRect.origin.y;
	left += offsetX * (cellWidth + this->spacing);
	top += offsetY * (cellHeight + this->spacing);

	float right = left + cellWidth;
	float bottom = top + cellHeight;
	right += (IAGridLayoutElement_getWidth(element) - 1) * (cellWidth + this->spacing);
	bottom += (IAGridLayoutElement_getHeight(element) - 1) * (cellHeight + this->spacing);
	IARect rect = IARect_makeWithLeftTopRightBottom(left, top, right, bottom);
	IADrawableRect * content = IAGridLayoutElement_getContent(element);
	IADrawableRect_setRect(content, rect);
}

static void setRect(IAGridLayout * this, IARect rect){
	bool isOccupied[this->gridWidth][this->gridHeight];
	for (size_t x = 0; x < this->gridWidth; x++) {
		for (size_t y = 0; y < this->gridHeight; y++) {
			isOccupied[x][y] = false;
		}
	}
	for (size_t i = 0; i < this->elementCount; i++) {
		IAGridLayoutElement * element = this->elements + i;
		size_t x = IAGridLayoutElement_getOffsetX(element);
		size_t y = IAGridLayoutElement_getOffsetY(element);
		const size_t widthOfGridElement = IAGridLayoutElement_getWidth(element);
		const size_t heightOfGridElement = IAGridLayoutElement_getHeight(element);

		if (x >= this->gridWidth){
			logError("Cannot place element number \"%lld\". Reason: Offset x is too large.", (i + 1));
		}else if (y >= this->gridHeight){
			logError("Cannot place element number \"%lld\". Reason: Offset y is too large.", (i + 1));
		}else{
			bool isSet = false;
			while (isSet == false){
				if (isInsideGrid(this, x, y, element)){
					bool isValid = true;
					for (size_t iIsOccupiedX = x; iIsOccupiedX < x + widthOfGridElement; iIsOccupiedX++) {
						for (size_t iIsOccupiedY = y; iIsOccupiedY < y + heightOfGridElement; iIsOccupiedY++) {
							if (isOccupied[iIsOccupiedX][iIsOccupiedY]){
								isValid = false;
							}
						}
					}
					if (isValid){
						for (size_t iIsOccupiedX = x; iIsOccupiedX < x + widthOfGridElement; iIsOccupiedX++) {
							for (size_t iIsOccupiedY = y; iIsOccupiedY < y + heightOfGridElement; iIsOccupiedY++) {
								isOccupied[iIsOccupiedX][iIsOccupiedY] = true;
							}
						}
						setRectOfElement(this, rect, x, y, element);
						isSet = true;
					}
				}

				x++;
				if (x == this->gridWidth){
					x = 0;
					y++;
					if (y == this->gridHeight){
						logError("Cannot place element number \"%lld\". Reason: Not enough space available in grid.", (i + 1));
						break;
					}
				}
			}
		}
	}
}

float IAGridLayout_getNeededHeight(IAGridLayout * this, float width, float heightToWidthProportionOfSingleCell){
	width -= IAGridLayout_getPaddingLeft(this);
	width -= IAGridLayout_getPaddingRight(this);
	width -= (this->gridWidth - 1) * this->spacing;
	if (width < 0.0f){
		return 0.0f;
	}
	float neededHeight = width * heightToWidthProportionOfSingleCell * this->gridHeight / this->gridWidth;
	neededHeight += IAGridLayout_getPaddingTop(this);
	neededHeight += IAGridLayout_getPaddingBottom(this);
	neededHeight += (this->gridHeight - 1) * this->spacing;
	return neededHeight;
}

void IAGridLayout_deinit(IAGridLayout *this) {
	for (size_t i = 0; i < this->elementCount; i++) {
		IAGridLayoutElement_deinit(this->elements + i);
	}
	IA_free(this->elements);
	IA_decrementInitCount();
	IALayout_deinit((IALayout *) this);
}
