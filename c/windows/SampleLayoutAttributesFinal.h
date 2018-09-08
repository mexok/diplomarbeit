
#ifndef SampleLayoutFinal_h
#define SampleLayoutFinal_h

typedef struct{
  void * correspondingObject;
  //@set+get
  int widthOfScreen;
} SampleLayoutAttributesFinal;


static void SampleLayoutAttributesFinal_make(SampleLayoutAttributes * attr){
  *attr = (SampleLayoutAttributes){
  };
  SampleLayoutAttr_makAsdf(attr, 43, 23);
}

#include "SampleLayoutAttributesFinal+Generated.h"

#endif
