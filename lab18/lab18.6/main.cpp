#include "List.h"
#include <iostream>
int main()
{
	List a(5);//������� ������ �� 5 ���������, ����������� ������ 
	cout << a << "\n";//������ �������� ��������� ������� 
	cout << "-------------------------------------------\n";
	cin >> a;//����� � ���������� �������� ��������� ������� 
	cout << "-------------------------------------------\n";
	cout << a << "\n";//������ �������� ��������� �������
	cout << "-------------------------------------------\n";
	a[2] = 100;//��������� �������� [] ��������� ����� �������� �������� 
	cout << a << "\n";//������ �������� ��������� �������
	cout << "-------------------------------------------\n";
	List b(10);//������� ������ b �� 10 ���������, ����������� ������ 
	cout << b << "\n";//������ �������� ��������� �������
	cout << "-------------------------------------------\n";
	b = a;//��������� ������� b �������� ������� a 
	cout << b << "\n";//������ �������� ��������� �������
	cout << "-------------------------------------------\n";
	List c(10); //������� ������ c �� 10 ���������, ����������� ������ 
	c = b + 100;//��������� �������� ������� b �� 100 � ��������� ������� c 
	cout << c << "\n";//������ �������� ��������� ������� c
	cout << "-------------------------------------------\n";
	cout << "the length of a=" << a() << endl;//������ ����� ������� a
		//�������������� ��������, ������� ���������� a.first() � ������� ��� 
	cout << "-------------------------------------------\n";
	cout << *(a.first()) << endl;
	cout << "-------------------------------------------\n";
	//���������� ���� Iterator ������������� �� ������ ������� ������� � �
	//������� ������ 
	Iterator i = a.first();
	//������� ���������
	++i;
	//�������������� �������� � ������ ��� �������� 
	cout << *i << endl;
	cout << "-------------------------------------------\n";
	//������� �������� �������� ������� � ������� ���������
	for (i = a.first(); i != a.last(); ++i) cout << *i << endl;
}
