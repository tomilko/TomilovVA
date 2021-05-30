#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

void Vvod (string* arr, int size, int& maxstr)
{
	using namespace std;
	string s;
	int max = 0;
	cout << "Заполните массив строками:" << endl;
	cin.ignore();
	for (int i = 0; i < size; i++)
	{
		getline(cin, s, '\n');

		if (s.length() > max)
		{
			max = s.length();
			maxstr = i;
		}
		arr[i] = s;
	}
}

void Vivod (string* arr, int  size)
{
	for (int i = 0; i < size; i++)
	{
		cout << i+1 << ".\t" << arr[i] << endl;
	}
	cout << " " << endl;
}

void MoveArr(string*& arr, int& size, int maxstr)
{
	for (int i = maxstr + 1; i < size; i++)
	{
		arr[i - 1] = arr[i];
	}
	size--;
}

void CopyArr(string*& arr, int  size)
{
	string* newarr = new string[size];
	for (int i = 0; i < size; i++) 
	{
		newarr[i] = arr[i];
	}
	delete[] arr;
	arr = newarr;
}

int main()
{
	system("color F0");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int maxstr;
	int size=0;
	cout << "Введите количество строк - ";
	while (!(cin >> size) || (cin.peek() != '\n') || size <= 0)
	{
		cin.clear();
		system("cls");
		while (cin.get() != '\n');
		{
			cout << "Введите количество строк - ";
		}
	}
	system("cls");
	string* arr = new string[size];
	if (arr == NULL)
	{
		cout << "Недостаточно свободной памяти!" << endl;
		exit(1); 
	}
	Vvod (arr, size, maxstr);
	system("cls");
	MoveArr(arr, size, maxstr);
	CopyArr(arr, size);
	Vivod (arr, size);
	delete[] arr;
	return 0;
}