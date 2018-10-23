//
//  SampleView.h
//

#ifndef SampleView_h
#define SampleView_h

#include "IAObject.h"
#include "SampleLayout.h"
#include "IAView.h"

typedef struct {
	//@extend
	IAObject base;
	IAFlowLayout * sampleLayout;
	IAButton * myButton;
	//@getAsRef
	IAView view;
} SampleView;


void SampleView_init(SampleView *);


void SampleView_deinit(SampleView *);

#include "SampleView+Generated.h"

#endif
