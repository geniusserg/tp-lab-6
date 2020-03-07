#include "Manufacture.h"
#include <iostream>
using namespace std;

int main(){
	Manufacture HR;
	ofstream file2;
	file2.open("/tmp/in2.txt",ios_base::out); 
	file2 <<  "proj 10000000\n";
	file2.close();
	HR.load_project_data("/tmp/in2.txt");
	
	ofstream file;
	file.open("/tmp/in.txt",ios_base::out); 
	file <<  "1 RTRT Cleaner 90 90\n";
	file <<  "2 RER Driver 67 80\n";
	file <<  "3 WET Programmer 90 90 proj 2\n";
	file <<  "3 WET Tester 90 90 proj 2\n";
	file <<  "4 WETET DeveloperTeamLeader 100 100 proj 10\n";
	file <<  "5 WETET TestingTeamLeader 78 190 proj 10\n";
	file <<  "6 WTY ProjectManager proj 20\n";
	file <<  "6 WTY SeniorManager";
	file.close();
	HR.load_data("/tmp/in.txt");
	HR.print_statistic("/tmp/out.txt");
	cout << endl << HR.getCount();
	return 0;
}