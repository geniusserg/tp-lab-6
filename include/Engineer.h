#pragma once
using namespace std;

#include "Employee.h"
#include "Interfaces.h"
#include "Utils.h"

class Engineer : public Employee, public WorkTime, public Project {
protected:
	Engineer(int id, string name, string position, int worktime, int base, string project, int budget, float part) : Employee(id, name, position) {
		this->base = base;
		this->worktime = worktime;
		this->project = project;
		this->budget = budget;
		this->part = part;
		this->payment = getWTsalary(base, worktime) + getPsalary(budget, part);
	}
	
	int getWTsalary(int base, int worktime) { return utils::getWTsalary(base, worktime); };
	int getPsalary(int budget, float part) { return utils::getPsalary(budget, part); };
	
}; 

class Programmer : public Engineer{
public:
	Programmer(int id, string name, string position, int worktime, int base, string project, int budget, float part): Engineer(id,name,position,worktime,base,project,budget,part){};
{
	
class Tester : public Engineer{
public:
	Tester(int id, string name, string position, int worktime, int base, string project, int budget, float part): Engineer(id,name,position,worktime,base,project,budget,part){};
{	