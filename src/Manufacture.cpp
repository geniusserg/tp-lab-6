#include "Employee.h"
#include "Personal.h"
#incldue "Engineer.h"
#include <vector>
#include <fstream>
#include <iostream>
using namespace std;

void print_statistic(string filename){
	ofstream file;
	file.open(filename,ios_base::out);
	for (Employee emp&: employees){
		emp.print();
	}
}

int load_data(string filename){
	ofstream file;
	file.open(filename,ios_base::in);

	int id;
	string name;
	string position;
	int worktime;
	string project;
	float part;
	int budget;
	int inferior;

	if (file.is_open()) {
		while (!file.eof()) {
			file >> id;
			file >> name;
			file >> position;

			if (position == "Cleaner") {
				file >> base >> worktime;
				employee.push_back(new Cleaner(id,name,position,worktime,base));
			}
			if (position == "Driver") {
				file >> base >> worktime;
				employee.push_back(new Driver(id,name,position,worktime,base));
			}
			if (position == "Programmer") {
				file >> base >> worktime;
				file >> project; file >> budget;file >> part;
				employee.push_back(new Programmer(id,name,position,worktime,base,project,budget,part));
			}
			if (position == "Tester") {
				file >> base >> worktime;
				file >> project;  file >> budget; file >> part;
				employee.push_back(new Tester(id,name,position, worktime, base ,project,budget,part));
			}
			/*
			if (position == "ProjectManager") {
				file >> project; file >> budget; file >> inferior;
				employee.push_back(new ProjectManager(id,name,position, project, budget,inferior));
			}
			if (position == "TeamLeader") {
				file >> base >> worktime;
				file >> project; file >> budget; file >> part; file >> inferior;
				employee.push_back(new TeamLeader(id,name,position, worktime, base, project, budget,part, inferior));
			}
			if (position == "SeniorManager") {
				file >> project; file >> budget; file >> inferior;
				employee.push_back(new SeniorManager(id,name,position, project, budget,inferior ));
			}
			*/
		}
	}
	
	return 0;
}