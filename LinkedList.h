/*
 * LinkedList.h
 *
 *  Created on: Dec. 20, 2018
 *      Author: Faraz
 */

#include "Drug.h"

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

class LinkedList {


public:
	class Node;
	Node* head;
	Node* tail;
	int count;

	LinkedList();
	void AddLast(Drug newData);
	bool isTarget(Drug data);
	Drug* toArray();
	void RemoveFirst();
	bool Contains(Drug data);



};

#endif /* LINKEDLIST_H_ */
