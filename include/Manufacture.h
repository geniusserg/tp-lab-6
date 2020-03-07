#pragma once 
#include "Employee.h"
#include "Personal.h"
#include "Engineer.h"
#include "Manager.h"
#include <vector>
#include <string>
using namespace std;

typedef struct ProjectStruct{
	string name;
	int budget;
	ProjectStruct(string _name, int _budget): name(_name), budget(_budget){};
}ProjectStruct;

class Manufacture{
public:
	vector<Employee*> employee;
	vector<ProjectStruct*> projects;
	void print_statistic(string filename);
	int load_data(string filename);
	int load_project_data(string filename);
	int getBudget(string project);
	int getCount(string project, string position);
	int getCount(string project);
	int getCount();
	int getWholeBudget();
};
