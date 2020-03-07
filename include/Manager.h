#pragma once
using namespace std;

#include "Employee.h"
#include "Interfaces.h"

class Manager : public Employee, Heading, Project {
protected:
	int budget;
	int part;
	
	Manager(int id, string name, string position, string project, int budget, int count, int part) : Employee(id, name, position) {
		this->base = base;
		this->worktime = worktime;
		this->project = project;
		this->budget = budget;
		this->part = part;
		this->payment = getPsalary(budget, part);
	}
	
	int getPsalary(int budget, float part) override { return (int)(budget*(part/100)); };
	int getHsalary(int count, int budget) override { return  (int)(count*(budget*(5/1000)));};
}; 


class ProjectManager : public Manager{
public:
	ProjectManager(int id, string name, string position, string project, int budget, int count, int part): Manager(id,name,position,project,budget,count,part){ this->payment += getHsalary(count, budget); };
};

class SeniorManager : public Manager{
public:
	SeniorManager(int id, string name, string position, string project, int all_budget, int all_count): Manager(id,name,position,project,all_budget,count,part){ this->payment += getHsalary(count, all_budget); };
};