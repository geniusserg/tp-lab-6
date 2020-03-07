#pragma once 
class WorkTime {
public:
	virtual int getWTsalary(int base, int worktime) = 0;
}; 

class Heading {
public:
	virtual int getHsalary(int count, int budget) = 0;
};

class Project {
public:
	virtual int getPsalary(int budget, float part) = 0;
};
