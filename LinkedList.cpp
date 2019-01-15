/*
 * LinkedList.cpp
 *
 *  Created on: Dec. 20, 2018
 *      Author: Faraz
 */

#include "LinkedList.h"
#include <iostream>
#include "Drug.h"

using namespace std;


LinkedList::LinkedList() {
	tail = NULL;
	head = NULL;
	count = 0;
}

class LinkedList::Node {
public:
	 Node* Next;
	 Node* getNode() {
		 return Next;
	 }

	 void setNode(Node* x) {
		 Next = x;
	 }

	 Drug* Data;
	 Drug getData() {
		 return *Data;
	 }
	 void setData(Drug y) {
		*Data = y;
	 }

	 Node() {
		Data = NULL;
		Next = NULL;
	 }

	 Node(Drug y) {
		 Data = &y;
		 Next = NULL;
	 }
};

void LinkedList::AddLast(Drug newData) {

	Node newNode(newData);
	Node* oldTail = tail;

	if (head->Next == NULL) {
		head = &newNode;
	}
	else {
		oldTail->Next = &newNode;
		tail = &newNode;
	}

	count++;
}

bool LinkedList::Contains(Drug data) {
	Node* currentNode = head;
	while (currentNode->Next != NULL) {
		if (isTarget(*currentNode->Data)) return true;
	}

	return false;
}


bool LinkedList::isTarget(Drug data) {
	bool result = data.nameContains("SYMBYAX");
	return result;
}

void LinkedList::RemoveFirst() {
	Node previousNode;
	Node* currentNode = head;

	while (currentNode->Next != NULL) {
		if (isTarget(*currentNode->Data)) {
			Node* nextNode = currentNode->Next;

			if (previousNode.Next == NULL) {
				currentNode->Next = NULL;
				head = nextNode;
			}

			else if (nextNode->Next == NULL) {
				previousNode.Next = nextNode;
				tail = &previousNode;

			}

			else if (count == 1) {
				delete head->Next;
				head = NULL;
				delete tail->Next;
				tail = NULL;
			}

			else {
				currentNode->Next = NULL;
				previousNode.Next = nextNode;
			}

			count--;
		}
		previousNode = *currentNode;
		currentNode = currentNode->Next;
	}

}


Drug* LinkedList::toArray() {
	Drug result[count];

	int i = 0;
	Node* currentNode = head;
	while (currentNode->Next != NULL) {
		result[i] = *currentNode->Data;
		i++;
		currentNode = currentNode->Next;
	}

	Drug* first = &result[0];

	return first;
}


