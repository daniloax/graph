/*
 * struct.h
 *
 *  Created on: 21/06/2014
 *      Author: ska
 */

#ifndef NODE_H_
#define NODE_H_

#include "arc.h"

typedef struct node {

	char nodeLabel;
	int nodeValue;
	struct arc *arcList;
	struct node *nextNode;

} graphNode;

#endif /* NODE_H_ */
