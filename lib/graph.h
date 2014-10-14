/*
 * graph.h
 *
 *  Created on: 21/06/2014
 *      Author: ska
 */

#ifndef GRAPH_H_
#define GRAPH_H_

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#include "arc.h"
#include "node.h"

void build(graphNode **epacesso) {

	FILE *f;

	char c, fileName[10];
	int i, find;
	graphArc *arc_a, *arc_b;
	graphNode *node_a, *node_b;

	c = '\0';
	i = 0;
	fileName[0] = '\0';

	arc_a = NULL;
	arc_b = NULL;
	node_a = NULL;
	node_b = NULL;

	*epacesso = NULL;

	/*
	 * user prompt
	 */
	do {

		printf("ENTER A FILENAME: ");
		scanf("%[^\n]s", fileName);
		getchar();

		f = fopen(fileName, "r");

		if (!f)
			printf("'%s' not exist\n", fileName);

	} while (!f);

	/*
	 * list build
	 */
	while ((c = getc(f)) != 10) {

		if ((c != 13) && (c != 32)) {

			insertNode(&(*epacesso), c);
			printf("%c", c);

		}

	}

	printf("\n");

	/*
	 * graph build
	 */
	do {

		find = 0;
		node_a = *epacesso;

		fscanf(f, "%c", &c);
		fscanf(f, "%i", &i);

		/*
		 * node build
		 */
		while ((node_a != NULL) && !find) {

			if (node_a->nodeLabel == c) {

				node_a->nodeValue = i;
				find = 1;

			} else
				node_a = node_a->nextNode;

		}

		/*
		 * arc build
		 */
		while (((c = getc(f)) != 10) && (c != 13) && (c != EOF)) {

			fscanf(f, "%c", &c);
			fscanf(f, "%d", &i);

			if (c != 32)
				insertArc(node_a, &(*epacesso), c, i);

		}


	} while ((c = getc(f)) != EOF);

	fclose (f);

	node_a = *epacesso;

	while (node_a != NULL) {

		printf("%c ", node_a->nodeLabel);
		printf("%d ", node_a->nodeValue);

		arc_a = node_a->arcList;

		while (arc_a != NULL) {

			printf("%c ", arc_a->nodePointer->nodeLabel);
			printf("%d ", arc_a->arcCost);

			arc_a = arc_a->nextArc;

		}

		node_a = node_a->nextNode;
		printf("\n");

	}

}

void insertArc(graphNode *node, graphNode **epacesso, char label, int cost) {

	graphArc *arc_a, *arc_b;
	graphNode *node_a;

	node_a = *epacesso;

	while ((node_a != NULL) && (node_a->nodeLabel != label))
		node_a = node_a->nextNode;

	arc_a = malloc(sizeof(graphArc));
	arc_a->arcCost = cost;
	arc_a->nextArc = NULL;
	arc_a->nodePointer = node_a;

	if (node->arcList == NULL)
		node->arcList = arc_a;

	else {

		arc_b = node->arcList;

		while (arc_b->nextArc != NULL)
			arc_b = arc_b->nextArc;

		arc_b->nextArc = arc_a;

	}

}

void insertNode(graphNode **epacesso, char label) {

	graphNode *node_a, *node_b;

	node_a = malloc(sizeof(graphNode));
	node_a->arcList = NULL;
	node_a->nodeLabel = label;
	node_a->nodeValue = NULL;
	node_a->nextNode = NULL;

	if (*epacesso == NULL)
		*epacesso = node_a;

	else {

		node_b = *epacesso;

		while (node_b->nextNode != NULL)
			node_b = node_b->nextNode;

		node_b->nextNode = node_a;

	}

}

#endif /* GRAPH_H_ */
