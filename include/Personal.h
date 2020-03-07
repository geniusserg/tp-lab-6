#pragma once

#include "Employee.h"
#include "Interfaces.h"
#include <string>
using namespace std;

class Personal : public Employee, WorkTime {
protected:
	int getWTsalary(int base, int worktime) override { return base*worktime; };
	
	Personal(int id, string name, string position, int worktime, int base) : Employee(id, name, position) {
		this->base = base;
		this->worktime = worktime;
		this->payment = getWTsalary(base, worktime);
	}
	
}; 

class Cleaner: public Personal {
public:
	Cleaner(int id, string name, string position, int worktime, int base): Personal(id, name, position, worktime, base){};
};

class Driver: public Personal {
public:
	Driver(int id, string name, string position, int worktime, int base): Personal(id, name, position, worktime, base){};
};

