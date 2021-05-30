#include <iostream>
#include "fraction.h"
using namespace std;
fraction make_fraction(int f, int s)
{
	fraction t;
	t.Init(f, s);
	return t;
}

int main()
{
	//определение переменных А и В
	fraction B;
	B.Read();//ввод полей переменных В
	B.Show();//вывод значений полей переменной В
	double x;
	cout << "\nx="; 
	cin >> x;
	cout << "function(" << x << ")=" << B.first << "*" << x << "+" << B.second << "=" << B.function(x) << endl;
	return 0;
}