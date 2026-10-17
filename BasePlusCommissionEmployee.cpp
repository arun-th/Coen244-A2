
/*
 * BasePlusCommissionEmployee.cpp
 *
 *  Created on: Sep 25, 2025
 *      Author: umroot
 */


#include "BasePlusCommissionEmployee.h"
#include <iomanip>
#include <iostream>
#include <string>
#include <sstream>
#include <stdexcept>
#include <cmath>
using namespace std;

BasePlusCommissionEmployee::BasePlusCommissionEmployee(
			const string& firstName,
			const string& lastName,
			const string& ssn,
			double grossSales,
			double commissionRate,
			double salary):CommissionEmployee(firstName,lastName,ssn,grossSales,commissionRate),baseSalary(salary) {

	if (!std::isfinite(salary) || salary < 0.0) {
		throw invalid_argument("Base salary must be nonnegative and finite");
	}

}
BasePlusCommissionEmployee::BasePlusCommissionEmployee(const BasePlusCommissionEmployee& other)
:CommissionEmployee(other),baseSalary(other.baseSalary){

}

double BasePlusCommissionEmployee::earnings() const{ //calculate earnings
	return CommissionEmployee::earnings() + baseSalary;
}

string BasePlusCommissionEmployee::toString() const{
	ostringstream output;

	output << "BasePlusCommission employee: " << firstName << " " << lastName
		<< "\nsocial security number: " << socialSecurityNumber
		<< "\ngross sales: " << grossSales
		<< "\ncommission rate: " << commissionRate
		<< "\nbase salary: " << baseSalary
		<< "\nearnings: " << earnings();

	return output.str();

}
