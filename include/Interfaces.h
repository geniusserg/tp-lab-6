class WorkTime {
public:
	virtual int getWTsalary(int base, int worktime);
}; 

class Heading {
public:
	virtual int getHsalary(int inferior);
};

class Project {
public:
	virtual int getPsalary(int budget, float part);
};