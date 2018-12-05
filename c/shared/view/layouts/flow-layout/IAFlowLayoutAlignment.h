//
// Created by Konstantin on 05.12.2018.
//

#ifndef IAFlowLayoutAlignment_h
#define IAFlowLayoutAlignment_h

typedef enum{
	// The elements will be aligned at the front of the flow layout. Spacing is fix.
	IAFlowLayoutAlignment_front,
	// The elements will be aligned at the center of the flow layout. Spacing is fix.
	IAFlowLayoutAlignment_centered,
	// The elements will be aligned at the rear of the flow layout. Spacing is fix.
	IAFlowLayoutAlignment_rear,
	// The elements will be stretched to fill the hole total length of the flow layout. Spacing is variable.
	IAFlowLayoutAlignment_stretched
} IAFlowLayoutAlignment;

#endif
