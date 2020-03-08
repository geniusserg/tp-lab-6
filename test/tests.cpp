#include "gtest/gtest.h"
#include<iostream>
#include <fstream>
#include<string>
#include<vector>
#include "personal.cpp"
#include "engineer.cpp"
#include "manager.cpp"
#define protected public
using namespace std;

vector<Employee*> main_action(const std::string& filename){
	vector <Employee *> workers;
	vector <string> projects;
	vector <int> funds;
	int id;
	string name;
	int worktime;
	string position;
	int rate;
	int overtime;
	string project;
	int fund;
	double part;
	int people;
	ifstream fin(filename);
	ifstream proj("project.txt");
	int i = 0;
	while (!proj.eof()){	
			proj >> project;
			projects.push_back(project);
			proj >> fund;
			funds.push_back(fund);
			cout << projects[i] << "  " << funds[i] << endl;
			i++;
	}
	fund = 0;
	int num=0;
	while (fin >> id>> name>> position>> worktime) {
		num++;
		if (position == "Cleaner"){
			fin >> rate;
			workers.push_back(new Cleaner(id, name, worktime, rate));
		}
		if (position == "Driver"){
			fin >> rate;
			fin >> overtime;
			workers.push_back(new Driver(id, name, worktime, rate,overtime));
		}
		if (position == "Programmer"){
			fin >> rate;
			fin >> project;
			fin >> part;
			for (int j = 0; j < 2;j++)
			if (project == projects[j]){
				fund=funds[j];
				break;
			}
			workers.push_back(new Programmer(id, name, worktime, rate, part,fund));
		}
		if (position == "Tester"){
			fin >> rate;
			fin >> project;
			fin >> part;
			for (int j = 0; j < i; j++)
			if (project == projects[j]){
				fund = funds[j];
				break;
			}
			workers.push_back(new Tester(id, name, worktime, rate, part, fund));
		}
		if (position == "TeamLeader"){
			fin >> rate;
			fin >> project;
			fin >> part;
			fin >> people;
			for (int j = 0; j < i; j++)
			if (project == projects[j]){
				fund = funds[j];
				break;
			}
			workers.push_back(new TeamLeader(id, name, worktime, rate, part, fund,people));
		}
		if (position == "Manager"){
			fin >> project;
			fin >> part;
			for (int j = 0; j < i; j++)
			if (project == projects[j]){
				fund = funds[j];
				break;
			}
			workers.push_back(new Manager(id, name, worktime, part, fund));
		}
		if (position == "ProjectManager"){
			fin >> project;
			fin >> part;
			fin >> people;
			for (int j = 0; j < i; j++)
			if (project == projects[j]){
				fund = funds[j];
				break;
			}
			workers.push_back(new ProjectManager(id, name, worktime, part, fund, people));
		}
		if (position == "SeniorManager"){
			fin >> project;
			fin >> part;
			fin >> people;
			for (int j = 0; j < i; j++)
			if (project == projects[j]){
				fund = funds[j];
				break;
			}
			workers.push_back(new SeniorManager(id, name, worktime, part, fund, people));
		}
	}

	for (int j = 0; j < num; j++){
		cout << workers[j]->getName() << "   " << workers[j]->getPayment() << endl;
	}
	
	return workers;
};

TEST (file, read){
	ifstream fin("employees.txt");
	fin << "103 Dorsey Programmer 150 300 SERIOS 0.1";
	vector<Employee*> emp = main_action();
	cout << emp[0]->getName();
	cout << emp[0]->id;
}