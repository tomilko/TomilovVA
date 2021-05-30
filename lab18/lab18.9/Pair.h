#pragma once
#include <iostream>//библиотека для работы со стандартными потоками 
#include <fstream> //библиотека для работы со файловыми потоками 
#include <string>
using namespace std;
class Pair
{
public:
	Pair();
	Pair(int, double);
	Pair(const Pair&);
	Pair operator =(const Pair&);
	Pair& operator++();
	Pair operator++(int);
	friend bool operator> (Pair& p, Pair& s);
	friend bool operator< (Pair& p, Pair& s);
	friend ostream& operator <<(ostream& out, const Pair& p);
	friend istream& operator>>(istream& in, Pair& p);
	friend fstream& operator>>(fstream& fin, Pair& p);
	friend fstream& operator <<(fstream& fout, const Pair& p);
public:
	~Pair();
	int first;
	double second;
};