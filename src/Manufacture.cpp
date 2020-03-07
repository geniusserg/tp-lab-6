#include "Manufacture.h"
#include <vector>
#include <fstream>
#include <iostream>
using namespace std;

void Manufacture::print_statistic(string filename){
	ofstream file;
	file.open(filename,ios_base::out);
	cout << "SALARY STATISTIC FOR EMPLOYEES." <<endl;
	cout << "ID | NAME | POSITION | SALARY" << endl;
	for (Employee*& emp: employee){
		file << emp->print();
		cout << emp->print();
	}
	file.close();
}

int Manufacture::load_project_data(string filename){
	ifstream file;
	file.open(filename,ios_base::in);
	string project;
	int budget;
	if (file.is_open()) {
		while (!file.eof()) {
			file >> project;
			file >> budget;
			bool found = false;
			for (ProjectStruct*& iproject: projects){
				if (iproject->name == project){
					found = true;
				}
			}
			if (!found){
				projects.push_back( new ProjectStruct(project, budget));
			}
		}
	}
	
	return 0;
}

int Manufacture::getBudget( string project){
	for (ProjectStruct*& iproject : projects){
		if (iproject->name == project){
			return iproject->budget;
		}
	}
	return 0;
}

int Manufacture::getCount(string project, string position){
	int count = 0;
	for (Employee*& iemp : employee){
		if (iemp->project == project && iemp->position == position){
			count += 1;
		}
	}
	return count;
}

int Manufacture::getCount(string project){
	int count = 0;
	for (Employee*& iemp : employee){
		if (iemp->project == project){
			count += 1;
		}
	}
	return count;
}

int Manufacture::getCount(){
	int count = 0;
	for (Employee*& iemp : employee){
		if (iemp->position != "Cleaner" && iemp->position != "Driver" && iemp->position != "SeniorManager"){
			count += 1;
		}
	}
	return count;
}

int Manufacture::getWholeBudget(){
	int sum = 0;
	for (ProjectStruct*& iproject : projects){
		sum += iproject->budget;
	}
	return sum;
}


int Manufacture::load_data(string filename){
	ifstream file;
	file.open(filename,ios_base::in);

	int id;
	string name;
	string position;
	int worktime;
	string project;
	int part;
	int base;

	if (file.is_open()) {
		while (!file.eof()) {
			file >> id >> name >> position;
			if (position == "Cleaner") {
				file >> base >> worktime;
				employee.push_back(new Cleaner(id,name,position,worktime,base));
			}
			if (position == "Driver") {
				file >> base >> worktime;
				employee.push_back(new Driver(id,name,position,worktime,base));
			}
			if (position == "Programmer") {
				file >> base >> worktime >> project >> part;
				employee.push_back(new Programmer(id,name,position,worktime,base,project, getBudget( project),part));
			}
			if (position == "Tester") {
				file >> base >> worktime >> project >> part;
				employee.push_back(new Tester( id, name, position, worktime, base , project, getBudget( project), part));
			}
			if (position == "ProjectManager") {
				file >> project >> part;
				employee.push_back(new ProjectManager(id,name,position, project, getBudget(project), getCount(project), part));
			}
			if (position == "DeveloperTeamLeader") {
				file >> base >> worktime >> project >> part;
				employee.push_back(new TeamLeader(id,name,position, worktime, base, project, getBudget( project) ,part, getCount(project, "Programmer")));
			}
			if (position == "TestingTeamLeader") {
				file >> base >> worktime >> project >> part;
				employee.push_back(new TeamLeader(id,name,position, worktime, base, project, getBudget( project) ,part, getCount(project, "Tester")));
			}
			if (position == "SeniorManager") {
				employee.push_back(new SeniorManager(id,name,position,project,getWholeBudget(), getCount()));
			}
		}
	}
	
	return 0;
}