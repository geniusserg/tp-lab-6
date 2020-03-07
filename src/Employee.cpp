#include "Employee.h"
using namespace std;

void print(ofstream file) {
	string report;
	
	if (worktime < 0) {
			report = + id + "  " + name + "  " + position + "  " + name_project + " -  - " + payment + "\n";
		}
		else {
			report = + id + "  " + name + "  " + position + "  " + name_project + "  " + worktime + "  " + print_base + "  " + payment + "\n";
		}	
	}
	
	if (file.is_open())
	{
		file << report;
	}
	
	cout << report;
	
	file.close();
}