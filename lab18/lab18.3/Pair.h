#include <iostream> 
using namespace std;

class Pair
{
	int fir; 
	double sec; 
public:
	Pair() { fir = 0; sec = 0; };
	Pair(int f, int s) { fir = f; sec = s; }
	Pair(const Pair& t) { fir = t.fir; sec = t.sec; }
	~Pair() {};

	int get_fir() { return fir; }
	double get_sec() { return sec; }
	void set_fir(int f) { fir = f; }
	void set_sec(int s) { sec = s; }

	Pair& operator++();
	Pair operator++(int);
	
	//friend bool operator< (Pair& t);
	friend istream& operator>>(istream& in, Pair& t);
	friend ostream& operator<<(ostream& out, const Pair& t);
};