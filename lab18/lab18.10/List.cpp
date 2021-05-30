#include "List.h"
#include"error.h"
#include <iostream>
using namespace std;
List::List(int s)
{
	//если текущий размер больше максимального, то генерируется исключение 
	if (s > MAX_SIZE) throw error("Vector length more than MAXSIZE\n");
	size = s;
	beg = new int[s]; for (int i = 0; i < size; i++)
		beg[i] = 0;
}
List::List(const List& v)
{
	size = v.size; beg = new int[size];
	for (int i = 0; i < size; i++) beg[i] = v.beg[i];
}
List::~List()
{
	if (beg != 0) delete[]beg;
}
List::List(int s, int* mas)
{
	//если текущий размер больше максимального, то генерируется исключение 
	if (s > MAX_SIZE) throw error("List length more than MAXSIZE\n");
	size = s;
	beg = new int[size]; for (int i = 0; i < size; i++)
		beg[i] = mas[i];
}
const List& List::operator =(const List& v)
{
	if (this == &v)return *this; if (beg != 0) delete[]beg; size = v.size;
	beg = new int[size]; for (int i = 0; i < size; i++)
		beg[i] = v.beg[i]; return*this;
}

ostream& operator<<(ostream& out, const List& v)
{
	if (v.size == 0) out << "Empty\n"; else
	{
		for (int i = 0; i < v.size; i++)
			out << v.beg[i] << " ";
		out << endl;
	}
	return out;
}
istream& operator >>(istream& in, List& v)
{
	for (int i = 0; i < v.size; i++)
	{
		cout << ">"; in >> v.beg[i];
	}
	return in;
}
int List::operator [](int i)
{
	if (i < 0) throw error("index <0");
	if (i >= size) throw error("index>size");
	if (i >= size) throw ("List length more than MAXSIZE\n");
	return beg[i];
}
List List::operator +(int a)
{
	//если при добавлении элемента размер вектора станет больше максимального,
	//то генерируется исключение 
	if (size + 1 == MAX_SIZE) throw error("List length more than MAXSIZE\n");
	List temp(size + 1, beg);
	temp.beg[0] = a;
	for (int i = 1; i < size + 1; i++)
	{
		temp.beg[i] = this->beg[i - 1];
	}
	return temp;
}

List List::operator+(List& v)
{
	int tempsize = this->size + v.size;
	List temp(tempsize, beg);
	for (int i = 0; i < this->size; i++)
	{
		temp.beg[i] = this->beg[i];
	}
	for (int i = this->size; i < tempsize; i++)
	{
		temp.beg[i] = v.beg[i - size];
	}
	return temp;
}