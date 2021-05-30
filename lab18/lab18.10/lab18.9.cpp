#include "List.h"
#include "error.h"
#include <iostream>
using namespace std;
int main()
{
	try
	{
		List x(2);//вектор из двух элементов 
		List y;//пустой вектор 
		cout << x;//печать вектора 
		cout << "Nomer?";
		int i;
		cin >> i;
		//вывод элемента с номером i, если номер больше 2 или меньше 0, то
		//генерируется исключительная ситуация 
		cout << x[i] << endl;
		cin >> x;
		//добавление элемента в вектор, если MAX _SIZE=2, то генерируется
		//исключительная ситуация 
		cout << "\ny=x+3\n";
		y = x + 3;
		cout << y;
		//удалить один элемент из вектора
		cout << "\nx=x+5\n";
		x = x + 5;
		cout << x;
		List z;
		cout << "\nz=x+y\n";
		z = (x + y);
		cout << z;
	}

	catch (error e)
	{
		e.what();
	}

	return 0;
}