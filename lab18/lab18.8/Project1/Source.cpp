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
	cout << "����� ���������� �����������: "; cin >> s;
	str = new Employee[s];
	for (int i = 0; i < s; i++)
	{
		cout << "����� ���, �������, ��������� � �������� ����� ������: ";
		cin >> name >> old >> zp >> dol;
		str[i] = Employee(old, name, zp, dol);
	}

	while (menu == 1 || menu == 2 || menu == 3 || menu == 4)
	{

		cout << endl << endl << "����: \n\t1. �������� ������� � ����� \n\t2. ������� ��������� ������� \n\t3. �������� ���������� �� ������ \n\t4. �������� ���������� ��� ������ \n\t0 �����.";
		cout << endl << "������ ����� ����: "; cin >> menu;

		if (menu == 1)
		{
			Employee* str1;
			str1 = new Employee[s+1];
			for (int i = 0; i < s; i++)
				str1[i] = str[i];
			cout << "����� ���, �������, �������� � ��������� ����� ������: ";
			cin >> name >> old >> zp >> dol;
			str1[s] = Employee(old, name, zp, dol);
			cout << "������� ��������";
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
			cout << "������� ������";
			delete[] str;
			str = str1;
			s--;
		}

		if (menu == 3)
		{
			cout << "����� ����� �������� = "; cin >> num;
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