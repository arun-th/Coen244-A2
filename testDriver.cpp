/*
 * testDriver.cpp
 *
 *  Created on: Sep 25, 2025
 *      Author: umroot
 */


#include "commission.h"
#include "BasePlusCommissionEmployee.h"
#include <iostream>

void test(){
	CommissionEmployee cp("abc","def","123",0,0);
	CommissionEmployee other(cp);
	std::cout << cp.toString() << std::endl;

	std::cout << "----------------------------"<<std::endl;

	BasePlusCommissionEmployee bp("ghi","lmn", "456",1,1,5);
	std::cout << bp.toString() << std::endl;


}

int main(){
	test();
}

