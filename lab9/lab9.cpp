#include <fstream>
#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	ifstream f1("file1.txt");
	ofstream f2("file2.txt");
	if (f1.is_open())
	{
		int n1, n2;
		cout << "Введите номер строки N1 - ";
		while (!(cin >> n1) || (cin.peek() != '\n') || n1 <= 0)
		{
			cin.clear();
			system("cls");
			while (cin.get() != '\n');
			{
				cout << "Введите номер строки N1 - ";
			}
		}
		cout << "Введите номер строки N2 - ";
		while (!(cin >> n2) || (cin.peek() != '\n') || n2 <= 0 || n2 <= n1)
		{
			cin.clear();
			system("cls");
			while (cin.get() != '\n');
			{
				cout << "Введите номер строки N1 - " << n1 << endl << "Введите номер строки N2 - ";;
			}
		}
		int k = 0;
		string line;
		while (!f1.eof())
		{
			getline(f1, line);
			k++;
		}
		f1.seekg(0);
		string row;
		for (int i = 1; i <= n1 - 1; i++)
		{
			getline(f1, row);
		}
		string a;
		for (int i = n1 - 1; i < n2; i++)
		{
			getline(f1, row);
			if ((row[0] == 'а') || (row[0] == 'a'))
			{
				f2 << row << endl;
				a = row;
			}
		}
		if ((n2 + 3) <= k)
		{
			for (int i = 0; i < 3; i++)
			{
				getline(f1, row);
			}
			for (int i = n2 + 3; i < k; i++)
			{
				getline(f1, row);
				if ((row[0] == 'а') || (row[0] == 'a'))
				{
					f2 << row << endl;
					a = row;
				}
			}
		}
		int count = 0, i = 0;
		while (i < a.length())
		{
			while (a[i] == ' ') i++;
			while (a[i] != ' ' && a[i] != '\0' && a[i] != '\n') i++;
			count++;
		}
		cout << count;


	}
	else cout << "Не удалось окрыть файл file1.txt" << endl;
	return 0;
}