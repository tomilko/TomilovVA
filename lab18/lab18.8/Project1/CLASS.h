#include <string>
using namespace std;
class Person
{
public:
	string name;
	int old;

};

class Employee : public Person
{
public:
	float zp;
	string dol;
	Employee()
	{
		old = 0;
		name = " ";
		zp = 0;
		dol = " ";
	}
	Employee(int o, string n, float z, string d)
	{
		old = o;
		name = n;
		zp = z;
		dol = d;
	}

	void GetInfo();
};