#include <iostream>
#include "fraction.h"
using namespace std;
//���������� ������ ��� ������������� ����� ���������
void fraction::Init(double F, double S)
{
	first = F; second = S;
}
//���������� ������ ��� ������ �������� ����� ���������
void fraction::Read()
{
	cout << "first? - "; cin >> first;
	cout << "second? - "; cin >> second;
}
//���������� ������ ��� ������ �������� ����� ���������
void fraction::Show()
{
	cout << "\nfirst=" << first;
	cout << "\nsecond=" << second;
	cout << "\n";
}
//Ax+B
double fraction::function(double x)
{
	return (first*x+second);
}