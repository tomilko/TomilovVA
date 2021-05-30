#include <iostream>
#include "fraction.h"
using namespace std;
//реализация метода для инициализации полей структуры
void fraction::Init(double F, double S)
{
	first = F; second = S;
}
//реализация метода для чтения значений полей структуры
void fraction::Read()
{
	cout << "first? - "; cin >> first;
	cout << "second? - "; cin >> second;
}
//реализация метода для вывода значений полей структуры
void fraction::Show()
{
	cout << "\nfirst=" << first;
	cout << "\nsecond=" << second;
	cout << "\n";
}
//Ax+B
double fraction::function(double x)
{
	return (first*x+second);
}