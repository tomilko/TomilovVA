#include "Vector.h"
#include <iostream> 
#include "Money.h"
using namespace std;

void main()
{
	setlocale(0, "Rus");
	/*cout << "\nВведите 5 значений : " << endl;
	Vector<int>A(5, 0);
	cin >> A;
	cout << A << endl;
	Vector <int>B(10, 1);
	cout << B << endl; B = A;
	cout << B << endl; cout << A[2] << endl;
	cout << "size=" << A() << endl;
	cout << B << endl;
	system("pause");
	system("cls");*/
	Money m;
	cin >> m;
	cout << m;
	Money p;
	cin >> p;
	cout << p << endl;
	p = p - m;
	cout << "\nРазность : " << p << endl;
	system("pause");
	system("cls");
	Vector<Money>C(5, m);
	cin >> C;
	cout << C << endl;
	Vector <Money>D(10, m);
	cout << D << endl;
	cout << C[2] << endl;
	cout << "size=" << C() << endl;
	D = C - D;
	cout << "\nРазность : " << D << endl;
}




