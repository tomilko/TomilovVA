#include "Pair.h" 
#include <iostream> 
using namespace std;

Pair&Pair::operator++()
{
	++fir; return *this;
}

Pair Pair::operator++(int)
{
	sec++; return *this;
}

istream&operator>>(istream&in, Pair&t)
{
	cout << "fir?"; in >> t.fir; cout << "sec?"; in >> t.sec; return in;
}

ostream&operator<<(ostream&out, const Pair&t)
{

	return (out << t.fir << " : " << t.sec);
}
