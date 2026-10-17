
/*
 * BasePlusCommissionEmployee.h
 *
 *  Created on: Sep 25, 2025
 *      Author: umroot
 */

#ifndef BASEPLUSCOMMISSIONEMPLOYEE_H_
#define BASEPLUSCOMMISSIONEMPLOYEE_H_

#include "commission.h"
#include <string>
using namespace std;
class BasePlusCommissionEmployee : public CommissionEmployee{
	/* the following attributes are protected data members;
	 *
	 *     std::string firstName;
	 *     std::string lastName;
	 *     std::string socialSecurityNumber;
	 *     double grossSales;
	 *     double commissionRate;
	 */

public:
	BasePlusCommissionEmployee(
		  const string& firstName,
		  const string& lastName,
		  const string& ssn,
		  double grossSales=0.0,
		  double commissionRate=0.0,
		  double salary=0.0); //number of argumemts is the sum of the base and the derived's total arguments

	//copy constructor;
	BasePlusCommissionEmployee(const BasePlusCommissionEmployee& other);

	//need to declare this function in BasePlusCommissionEmployee
	string toString() const override;

	//function is also in commision .h
	double earnings() const override;

private:
	double baseSalary;


};


#endif /* BASEPLUSCOMMISSIONEMPLOYEE_H_ */
