#include "Pair.h"
#include <iostream>
using namespace std;
Pair& Pair::operator=(const Pair& p)
{
	if (&p == this) return *this;
	first = p.first;
	second = p.second;
	return *this;
}

istream& operator>>(istream& in, Pair& p)
{
	cout << "First: "; in >> p.first;
	cout << "Second: "; in >> p.second;
	return in;
};

ostream& operator<<(ostream& out, const Pair& p)
{
	return (out << p.first << " " << p.second);
};

bool Pair::operator>(const Pair& p)
{
	if (first > p.first) return true;
	if (first == p.first && second > p.second) return true;
	return false;
}

bool Pair::operator<(const Pair& p)
{
	if (first < p.first) return true;
	if (first == p.first && second < p.second) return true;
	return false;
}

Pair Pair::operator+(const Pair& p)
{
	int temp1 = first;
	double temp2 = second;
	int temp3 = p.first;
	double temp4 = p.second;
	Pair t;
	t.first = temp1 + temp3;
	t.second = temp2 + temp4;
	return t;
}

Pair Pair::operator/(const int& n)
{
	Pair t;
	t.first = first / n;
	t.second = second / n;
	return t;
}

Pair Pair::operator/(const Pair& p)
{
	Pair t;
	t.first = first / p.first;
	t.second = second / p.second;
	return t;
}