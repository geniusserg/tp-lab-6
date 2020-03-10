#include "gtest/gtest.h"
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include "Manufacture.h"
#define testprojects "/tmp/in2.txt"
#define testemplyees "/tmp/in.txt"
#define testresults "/tmp/out.txt"
using namespace std;

int write(const string& project, const string& employee){
	ofstream file2;
	file2.open(testprojects,ios_base::out); 
	file2 <<  project;
	file2.close();
	ofstream file;
	file.open(testemplyees,ios_base::out); 
	file <<  employee;
	file.close();
}

string output(){
	ifstream res(testresults);
	string test;
	getline(res, test);
	return test;	
}



TEST(global, main){
	Manufacture HR;
	write ("proj 10000000\n", "1 RTRT Cleaner 90 90\n");
	HR.load_project_data(testprojects);
	HR.load_data(testemplyees);
	HR.print_statistic(testresults);
	string right = "1  RTRT  Cleaner  8100";
	EXPECT_STREQ(right.c_str(), output().c_str());
}