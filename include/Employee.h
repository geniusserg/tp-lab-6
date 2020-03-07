#pragma once

#include <string>
#include <fstream>
using namespace std;

class Employee {
protected:
	int id;
	string name;
	int worktime;
	int payment;
	string position;
	int base;
	string project;
	
public:
	Employee(int id, string name, string position){
		this->id = id;
		this->name = name;
		this->position = position;
	}	
	// int getSalary(); //NOTE: If salary is obvious (personal, engineer) - it just returns field "payment", used for managers only!
	string print();
	friend class Manufacture;
}; 