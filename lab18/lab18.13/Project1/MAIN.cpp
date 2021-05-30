#include <iostream>
#include "CLASS.h"
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
#include <list>
#include <deque>
#include <map>
#include <windows.h>
#include <string>
using namespace std;
void Money()
{
	int s;
	double el;
	cout << "����� ���������� ���������: "; cin >> s;
	VectorOfMoney Vec(s);
	int menu = 1;

	while (menu == 1 || menu == 2 || menu == 3 || menu == 4)
	{

		cout << "����: \n\t1. ����� ������� � �������� ��� � �����\n\t2. ������� �� ����� \n\t3. � ������� �������� �������� ����� ��������� � �������� \n\t4. ������� ������\n\n\t0. �����";
		cout << endl << "������ ����� ����: "; cin >> menu;
		if (menu == 1)
		{
			Vec.pushback(Vec.FindMin());
			cout << "������� ��������" << endl;
		}

		if (menu == 2)
		{
			cout << "����� �������: "; cin >> el;
			Vec.del(el);
			cout << "������� ������" << endl;
		}

		if (menu == 3)
		{
			Vec.add2(Vec.FindMax(), Vec.FindMin());
			cout << "��������� ���������";
		}

		if (menu == 4)
		{
			Vec.Print();
		}
	}
}

void Queue()
{
	int min = 32000; int max = -32000;
	list<int> l;
	int check = 1, menu = 1;
	cout << "����� �������� �������. 0 - ����� �����" << endl;
	while (check != 0)
	{
		cin >> check;
		if (check != 0)
			l.push_back(check);
		else break;
	}
	list<int>::iterator iter = l.begin();
	while (menu == 1 || menu == 2 || menu == 3 || menu == 4)
	{
		cout << "����: \n\t1. ������� �������\n\t2. ����� ������� � �������� � ����� \n\t3. ����� ������� � ������� \n\t4. � ������� �������� �������� ����� ��������� � �������� \n\n\t0. �����";
		cout << endl << "������ ����� ����: "; cin >> menu;
		if (menu == 1)
		{
			for (int i : l)
				cout << i << " ";
			cout << endl;
		}

		if (menu == 2)
		{
			for (iter = l.begin(); iter != l.end(); iter++)
			{
				if (*iter < min)
					min = *iter;
			}
			l.push_back(min);
			cout << "������� ��������" << endl;
		}

		if (menu == 3)
		{
			int k = 0;
			cout << "����� �������: "; cin >> check;
			for (iter = l.begin(); iter != l.end(); iter++)
			{
				if (check == *iter)
				{
					l.erase(iter);
					break;
				}

			}
			cout << "������� ������" << endl;
		}

		if (menu == 4)
		{
			min = 32000; max = -32000;
			for (iter = l.begin(); iter != l.end(); iter++)
			{
				if (*iter < min)
					min = *iter;
				if (*iter > max)
					max = *iter;
			}

			list<int> l1;
			list<int>::iterator iter1 = l1.begin();
			for (iter = l.begin(); iter != l.end(); iter++)
			{
				l1.push_back(*iter + max + min);
			}
			l.clear();
			for (iter1 = l1.begin(); iter1 != l1.end(); iter1++)
			{
				l.push_back(*iter1);
			}
			cout << "��������� ��������� " << endl;
		}
	}
}

void Dictionary()
{
	int s, k = 0, menu = 1; string ad;
	multimap<int, string> Map;
	cout << "����� ���������� ����: "; cin >> s;
	for (int i = 0; i < s; i++)
	{
		cout << "����� �����: " << endl;
		cin >> ad;
		Map.emplace(i, ad);
	}
	while (menu == 1 || menu == 2 || menu == 3)
	{
		cout << "����: \n\t1. ������� ��� ����� \n\t2. ������� ����� �� ������ \n\t3. �������� ����� \n\n\t0. �����";
		cout << endl << "������ ����� ����: "; cin >> menu;

		if (menu == 1)
		{
			for (auto iter = Map.begin(); iter != Map.end(); iter++)
			{
				cout << iter->first << ") " << iter->second << "\t";
			}
			cout << endl;
		}

		if (menu == 2)
		{
			cout << "����� ����: "; cin >> k;
			Map.erase(k);
			cout << "������� ������" << endl;
			s--;
		}

		if (menu == 3)
		{
			cout << "����� �����: "; cin >> ad;
			Map.emplace(s + 1, ad);
			s++;
			cout << "����� ���������" << endl;
		}
	}

}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Russian");
	int menu = 1;

	while (menu == 1 || menu == 2 || menu == 3)
	{

		cout << "����: \n\t1. Money\n\t2. Queue \n\t3. Map \n\n\t0. �����";
		cout << endl << "������ ����� ����: "; cin >> menu;

		if (menu == 1)
			Money();

		if (menu == 2)
		{
			Queue();
		}

		if (menu == 3)
		{
			Dictionary();
		}
	}
}