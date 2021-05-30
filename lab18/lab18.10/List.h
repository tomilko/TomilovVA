#pragma once
#include <iostream> 
using namespace std;
const int MAX_SIZE = 30;//максимальный размер вектора
class List
{
	int size;//текущий размер
	int* beg;//указатель на начало динамического массива 
public:
	List() { size = 0; beg = 0; }//конструктор без параметров 
	List(int s);//конструктор с параметром
	List(int s, int* mas);//конструктор с параметром 
	List(const List& v);//конструктор копирования
	~List();//деструктор
	const List& operator=(const List& v);//операция присваивания 
	int operator[](int i);//доступ по индексу
	List operator+(int a);//добавление элемента 
	List operator+(List& v);//добавление элемента
	//дружественные функции ввода-вывода
	friend ostream& operator<<(ostream& out, const List& v);
	friend istream& operator>>(istream& in, List& v);
};