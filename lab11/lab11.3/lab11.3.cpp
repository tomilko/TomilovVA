#include <iostream>
#include <stack>

using namespace std;

int a, b;

int main()
{
	stack<int> st;
	int n;
	system("chcp 1251 > nul");
	cout << "Введите размер стека: ";
	while (!(cin >> n) || (cin.peek() != '\n') || n <= 0)
	{
		cin.clear();
		system("cls");
		while (cin.get() != '\n');
		{
			cout << "Введите размер стека: ";
		}
	}
	cout << "Ввелите элементы стека: ";
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		st.push(a);
	}

	stack<int> st2;
	for (int i = 0; i < n; i++)
	{
		if (st.top() % 2 == 0)
		{
			st.pop();
		}
		else
		{
			st2.push(st.top());
			st.pop();
		}
	}
	n = st2.size();
	for (int i = 0; i < n; i++)
	{
		st.push(st2.top());
		st2.pop();
	}

	cout << endl << "Стек: ";
	while (!st.empty())
	{
		cout << st.top() << ' ';
		st.pop();
	}

}
