﻿#include <iostream>

using namespace std;
struct List
{
	int str;
	List* next;
};

List* input(int size)
{
	if (size <= 0)
	{
		cout << "Список не может быть создан";
		return 0;
	}
	List* first, * p;
	first = NULL;
	cout << "Введите 1 элемент: ";
	p = new List;
	cin>> p->str;
	first = p;
	for (int i = 2; i <= size; i++)
	{
		List* h = new List;
		p->next = h;
		p = p->next;
		cout << "Введите " << i << " элемент: ";
		cin >> p->str;
	}
	p->next = NULL;
	return first;
}

void del(List* first)
{
	List* p = first;
	while (p->next != NULL)
	{

		if ((p->next->str) % 2 == 0)
		{
			List* q = p->next;
			p->next = p->next->next;
			delete q;
		}
		else p = p->next;
	}
}

void output(List* first)
{
	if (first == NULL)
	{
		cout << "Список пуст";
	}
	else
	{
		List* p = first;
		while (p != NULL)
		{
			cout << p->str << " ";
			p = p->next;
		}
		cout << endl;
	}
}
int main()
{
	system("chcp 1251 > nul");
	int size, k;
	cout << "Введите размер списка: ";
	while (!(cin >> size ) || (cin.peek() != '\n') || size <= 0)
	{
		cin.clear();
		system("cls");
		while (cin.get() != '\n');
		{
			cout << "Введите размер списка: ";
		}
	}
	List* list = input(size);
	cout << "Измененный список: " << endl;
	del(list);
	output(list);
}