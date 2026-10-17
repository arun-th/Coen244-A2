
/*
 * testDriver.cpp
 *
 *  Created on: Sep 25, 2025
 *      Author: umroot
 */

#include "commission.h"
#include "BasePlusCommissionEmployee.h"
#include <iostream>
#include <cassert>
#include <stdexcept>
#include <string>
#include <cmath>
using namespace std;

void testBaseObject(){
	cout << "------------test base object------------" << endl;

	CommissionEmployee commMember("hkl","yui","4567890234",350000,0.35);

	cout << commMember.toString() << endl;
}

void testDerivedObject(){
	cout << "\n------------test derived object------------" << endl;

	BasePlusCommissionEmployee basePlusMember("abc","def","0987654321",250000,0.15,5000);

	cout << basePlusMember.toString() << endl;
}

void testCopyConstructors(){
	cout << "\n------------test copy constructors------------" << endl;

	CommissionEmployee original("hkl","yui","4567890234",350000,0.35);
	CommissionEmployee copy(original);

	assert(copy.getFirstName() == original.getFirstName());
	assert(copy.getGrossSales() == original.getGrossSales());
	assert(copy.earnings() == original.earnings());

	cout << "CommissionEmployee copy test: PASS" << endl;
	cout << copy.toString() << endl;

	BasePlusCommissionEmployee derived("abc","def","0987654321",250000,0.15,5000);
	BasePlusCommissionEmployee derivedCopy(derived);

	assert(derivedCopy.earnings() == derived.earnings());
	assert(derivedCopy.toString() == derived.toString());

	cout << "BasePlusCommissionEmployee copy test: PASS" << endl;
	cout << derivedCopy.toString() << endl;
}

void testInvalidArguments(){
	cout << "\n------------test invalid arguments------------" << endl;

	bool thrown = false;

	try {
		CommissionEmployee bad("a","b","123",-1,0.2);
	}
	catch(const invalid_argument& e) {
		thrown = true;
		cout << "Invalid gross sales: PASS (" << e.what() << ")" << endl;
	}
	assert(thrown);

	thrown = false;

	try {
		CommissionEmployee bad("a","b","123",100,1.0);
	}
	catch(const invalid_argument& e) {
		thrown = true;
		cout << "Invalid commission rate: PASS (" << e.what() << ")" << endl;
	}
	assert(thrown);

	thrown = false;

	try {
		BasePlusCommissionEmployee bad("a","b","123",100,0.2,-100);
	}
	catch(const invalid_argument& e) {
		thrown = true;
		cout << "Invalid base salary: PASS (" << e.what() << ")" << endl;
	}
	assert(thrown);
}

void testFriendAndInheritance(){
	BasePlusCommissionEmployee basePlusMember //derived class
		("abc","def","0987654321",250000,0.15,5000);

	// checkGrossSales accepts the derived object through its base-class reference
	bool result1 = checkGrossSales(basePlusMember, 100000);
	bool result2 = checkGrossSales(basePlusMember, 5000);
	bool result3 = checkGrossSales(basePlusMember, 300000);

	assert(result1 == true);
	assert(result2 == true);
	assert(result3 == false);

	cout << "\ntest friend and inheritance" << endl;
	cout << "Baseline 100000: " << (result1 ? "PASS" : "FAIL") << endl;
	cout << "Baseline 5000: " << (result2 ? "PASS" : "FAIL") << endl;
	cout << "Baseline 300000 (expected false): "
		 << (!result3 ? "PASS" : "FAIL") << endl;
}

int main(){
	testBaseObject();
	testDerivedObject();
	testCopyConstructors();
	testInvalidArguments();
	testFriendAndInheritance();

	return 0;
}
