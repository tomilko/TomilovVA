#include "CLASS.h"
#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Russian");
	int s, old, menu = 4, num = 0;
	float zp;
	string name, dol;
	Employee* str;
	cout << "Введи количество сотрудников: "; cin >> s;
	str = new Employee[s];
	for (int i = 0; i < s; i++)
	{
		cout << "Введи имя, возраст, должность и зарплату через пробел: ";
		cin >> name >> old >> zp >> dol;
		str[i] = Employee(old, name, zp, dol);
	}

	while (menu == 1 || menu == 2 || menu == 3 || menu == 4)
	{

		cout << endl << endl << "Меню: \n\t1. Добавить элемент в конец \n\t2. Удалить последний элемент \n\t3. Получить информацию по номеру \n\t4. Получить информацию про группу \n\t0 Выход.";
		cout << endl << "Выбери пункт меню: "; cin >> menu;

		if (menu == 1)
		{
			Employee* str1;
			str1 = new Employee[s+1];
			for (int i = 0; i < s; i++)
				str1[i] = str[i];
			cout << "Введи имя, возраст, зарплату и должность через пробел: ";
			cin >> name >> old >> zp >> dol;
			str1[s] = Employee(old, name, zp, dol);
			cout << "Элемент добавлен";
			delete[] str;
			str = str1;
			s++;
		}

		if (menu == 2)
		{
			Employee* str1;
			str1 = new Employee[s - 1];
			for (int i = 0; i < s - 1; i++)
				str1[i] = str[i];
			cout << "Элемент удален";
			delete[] str;
			str = str1;
			s--;
		}

		if (menu == 3)
		{
			cout << "Введи номер элемента = "; cin >> num;
			str[num].GetInfo();
		}

		if (menu == 4)
		{
			for (int i = 0; i < s; i++)
			{
				str[i].GetInfo();
			}
		}

		if (menu == 0)
		{
			delete[] str;
			str = 0;
			break;
		}

	}
}