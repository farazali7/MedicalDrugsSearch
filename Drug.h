/*
 * Drug.h
 *
 *  Created on: Dec. 20, 2018
 *      Author: Faraz
 */
#include <string>
#include <iostream>

#ifndef DRUG_H_
#define DRUG_H_

#include <string>
#include <iostream>
using namespace std;

class Drug {
private:
	string code;
	string name;
	string id;
	double size;
	string unit;
	double quantity;
	double lowest;
	double ingredientCost;
	int    numTar;
	double totalPaid;
	double averagePaid;
	int    daysSupply;
	int    claimLines;

public:
	string getCode();
	string getName();
	string getId();
	double getSize();
	string getUnit();
	double getQuantity();
	double getLowest();
	double getIngredientCost();
	int    getNumTar();
	double getTotalPaid();
	double getAveragePaid();
	int    getDaysSupply();
	int    getClaimLines();

	Drug();
	Drug parseFileLine(string line);

	string trim(string str);

	void Print();

	bool nameContains(string s);

};

#endif /* DRUG_H_ */
