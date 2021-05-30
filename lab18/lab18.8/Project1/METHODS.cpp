#include "CLASS.h"
#include <iostream>
#include <string>
using namespace std;

void Employee::GetInfo()
{
	cout << "Имя - " << name << ", возраст - " << old << ", должность - " << dol << ", зарплата - " << zp << endl;
}

