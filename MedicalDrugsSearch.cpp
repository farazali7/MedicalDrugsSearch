/*
 * MedicalDrugsSearch.cpp
 *
 *  Created on: Dec. 20, 2018
 *      Author: Faraz
 */



#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

#include "LinkedList.h"
#include "LinkedList.cpp"
#include "Drug.h"

using namespace std;


int main() {
	LinkedList drugList;

	const string filePath = "RXQT1503-10.txt";

	ifstream drugFile(filePath);
	string line;
	while (getline(drugFile, line)) {
		Drug d;
		d.parseFileLine(line);
		drugList.AddLast(d);
	}

	LinkedList::Node* currNode = drugList.head;

	while (currNode->Next != NULL) {
		cout << currNode->Data->Print() << endl;
		currNode = currNode->Next;
	}


	cout << "done." << endl;

	return 0;
}
