#include <iostream>
#include <list>
#include <iterator>
using namespace std;
list<char> stroka;

struct List
{
	char str;
	List* next;
	List* prev;
};

void input(int n)
{
	char t;
	for (int i = 0; i < n; i++)
	{
		cin >> t;
		stroka.push_back(t);
	}
}

void add()
{
	int k;
	cout << "Введите номер элемента после которого необходимо добавить: ";
	cin >> k;
	list<char> ::iterator it;
	it = stroka.begin();
	advance(it, k);
	char t;
	list<char> additlist;
	cout << "Введите новый элемент ";
	cin >> t;
	additlist.push_back(t);
	stroka.insert(it, additlist.begin(), additlist.end());
}

int main()
{
	system("chcp 1251 > nul");
	int size;
	cout << "Введите размер списка: ";
	while (!(cin >> size) || (cin.peek() != '\n') || size <= 0)
	{
		cin.clear();
		system("cls");
		while (cin.get() != '\n');
		{
			cout << "Введите размер списка: ";
		}
	}
	input(size);
	add();
	cout << "Список: " << endl;
	copy(stroka.begin(), stroka.end(), ostream_iterator<char>(cout, " "));
	return 0;
}
