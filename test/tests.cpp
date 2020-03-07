#include "gtest/gtest.h"
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include "Manufacture.h"
using namespace std;
TEST(global, main){
	cout << "start";
	Manufacture HR;
	ofstream file2;
	file2.open("/tmp/in2.txt",ios_base::out); 
	file2 <<  "proj 10000000\n";
	file2.close();
	HR.load_project_data("/tmp/in2.txt");
	ofstream file;
	file.open("/tmp/in.txt",ios_base::out); 
	file <<  "1 RTRT Cleaner 90 90";
	file.close();
	HR.load_data("/tmp/in.txt");
	HR.print_statistic("/tmp/out.txt");
	ifstream res("/tmp/out.txt");
	string test;
	getline(res, test);
	string right;
	right = "1  RTRT  Cleaner  8100";
	EXPECT_STREQ(right.c_str(), test.c_str());
}