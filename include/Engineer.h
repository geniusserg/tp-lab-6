#pragma once
using namespace std;

#include "Employee.h"
#include "Interfaces.h"

class Engineer : public Employee, WorkTime, Project {
protected:
	int budget;
	int part;
	
	Engineer(int id, string name, string position, int worktime, int base, string project, int budget, int part) : Employee(id, name, position) {
		this->base = base;
		this->worktime = worktime;
		this->project = project;
		this->budget = budget;
		this->part = part;
		this->payment = getWTsalary(base, worktime) + getPsalary(budget, part);
	}
	
	int getWTsalary(int base, int worktime) override { return base*worktime; };
	int getPsalary(int budget, float part) override { return (int)(budget*(part/100)); };
	
}; 

class Programmer : public Engineer{
public:
	Programmer(int id, string name, string position, int worktime, int base, string project, int budget, float part): Engineer(id,name,position,worktime,base,project,budget,part){};
};
	
class Tester : public Engineer{
public:
	Tester(int id, string name, string position, int worktime, int base, string project, int budget, float part): Engineer(id,name,position,worktime,base,project,budget,part){};
};

class TeamLeader : public Engineer, Heading{
public:
	TeamLeader(int id, string name, string position,int worktime, int base, string project,	int budget, int part, int count): Engineer(id,name,position,worktime,base,project,budget,part){ this->payment += getHsalary(count, budget); };
	int getHsalary(int count, int budget) override { return  (int)(count*(budget/100));};
};