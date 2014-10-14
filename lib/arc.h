/*
 * arc.h
 *
 *  Created on: 17/08/2014
 *      Author: ska
 */

#ifndef ARC_H_
#define ARC_H_

#include "node.h"

typedef struct arc {

	int arcCost;
	struct arc *nextArc;
	struct node *nodePointer;

} graphArc;

#endif /* ARC_H_ */
