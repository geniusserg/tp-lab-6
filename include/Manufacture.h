#include "Employee.h"
#include <vector>
#include <string>
using namespace std;

class Manufacture{
private:
	vector<Employee*> employee;
public:
	void print_statistic(string filename);
	int load_data(string filename);
}
