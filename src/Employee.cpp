#include "Employee.h"
#include <string>
using namespace std;

string Employee::print() {
	string report;
	report = to_string(id) + "  " + name + "  " + position + "  " + to_string(payment) + "\n";	
	return report;
};