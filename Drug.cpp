/*
 * Drug.cpp
 *
 *  Created on: Dec. 20, 2018
 *      Author: Faraz
 */

#include "Drug.h"
#include <stdlib.h>


Drug::Drug() {

}

string Drug::getCode() {
	return code;
}
string Drug::getName() {
	return name;
}
string Drug::getId() {
	return id;
}
double Drug::getSize() {
	return size;
}
string Drug::getUnit() {
	return unit;
}
double Drug::getQuantity() {
	return quantity;
}
double Drug::getLowest() {
	return lowest;
}
double Drug::getIngredientCost() {
	return ingredientCost;
}
int    Drug::getNumTar() {
	return numTar;
}
double Drug::getTotalPaid() {
	return totalPaid;
}
double Drug::getAveragePaid() {
	return averagePaid;
}
int    Drug::getDaysSupply() {
	return daysSupply;
}
int    Drug::getClaimLines() {
	return claimLines;
}

string Drug::trim(string str) {
	size_t first = str.find_first_not_of(' ');
	    if (string::npos == first)
	    {
	        return str;
	    }
	    size_t last = str.find_last_not_of(' ');
	    return str.substr(first, (last - first + 1));
}


Drug Drug::parseFileLine(string line) {

	Drug newDrug;

	newDrug.code = trim(line.substr( 0, 7 ));
	newDrug.name = trim(line.substr( 7, 30 ));
	newDrug.id = trim(line.substr( 37, 13 ));
	string sizeWithUnit = trim(line.substr( 50, 14 ));
	newDrug.size = atof( (sizeWithUnit.substr( 0 , sizeWithUnit.length() - 2 )).c_str() );
	newDrug.unit = sizeWithUnit.substr( sizeWithUnit.length() - 2, 2 );
	newDrug.quantity = atof( (line.substr( 64, 16 )).c_str() );
	newDrug.lowest = atof(( line.substr( 80, 10 )).c_str() );
	newDrug.ingredientCost = atof(( line.substr( 90, 12 )).c_str() );
	newDrug.numTar = stoi( line.substr( 102, 8 ) );
	newDrug.totalPaid = atof(( line.substr( 110, 14 )).c_str() );
	newDrug.averagePaid = atof(( line.substr( 124, 10 )).c_str() );
	newDrug.daysSupply = int (atof(( line.substr( 134, 14 )).c_str()));
	newDrug.claimLines = stoi(( line.substr( 148, 10 ) ));

	return newDrug;

}

void Drug::Print() {
	cout << id << ", " << name << ", " << size << endl;
}

bool Drug::nameContains(string s) {
	return name.find(s);
}
