#pragma once
#include<iostream>
using namespace std;

class Pair
{
public:
	int first;
	double second;
public:


	Pair() { first = 0; second = 0; }
	Pair(int first, double second) { this->first = first; this->second = second; }
	Pair(const Pair& other) { this->first = other.first; this->second = other.second; }
	~Pair() {};
	int GetInt() { return this->first; }
	double GetDouble() { return this->second; }
	void SetInt(int first) { this->first = first; }
	void SetDouble(double second) { this->second = second; }
	Pair& operator=(const Pair& p);
	bool operator> (const Pair& other);
	bool operator< (const Pair& other);
	Pair operator+(const Pair& p);
	Pair operator /(const int& n);
	Pair operator/(const Pair& p);
	friend istream& operator>>(istream& in, Pair& p);
	friend ostream& operator<<(ostream& out, const Pair& p);
};