#include <iostream>
#include <queue>

using namespace std;

void print(queue<char> st)
{
	for (int i = 0; i < st.size(); i++)
	{
		cout << st.front() << "\t";
		st.push(st.front());
		st.pop();
	}
	cout << endl;
};

int main()
{
	system("chcp 1251>nul");
	int size;
	cout << "Введите размер очереди\n";
	cin >> size;
	while (size < 1)
	{
		cout << "Ошибка! Введите корректный размер очереди\n";
		cin >> size;
	}
	queue<char> st;
	cout << "Введите элементы очереди\n";
	for (int i = 0; i < size; i++)
	{
		char input;
		cin >> input;
		st.push(input);
	}
	cout << "ОЧЕРЕДЬ:\n";
	print(st);
	bool flag = false;
	cout << "Введите заданный номер: ";
	int key;
	cin >> key;
	int n = st.size();
	for (int i = 0; i < n; i++)
	{
		if (i == key - 2)
		{
			flag = true;
			st.push(st.front());
			st.pop();
			char add;
			cout << "Введите элемент для добавления\n";
			cin >> add;
			st.push(add);
		}
		else
		{
			st.push(st.front());
			st.pop();
		}
	}
	if (flag == false)
		cout << "Требуемый элемент не найден\n";
	cout << "Очередь после добавления:\n";
	print(st);
	return 0;
}
