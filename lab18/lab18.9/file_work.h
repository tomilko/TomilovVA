#include "Pair.h"
#include <iostream>
#include <fstream>
using namespace std;

static int make_file(const char* f_name)
{
	fstream stream(f_name, ios::out | ios::trunc); //������� ��� ������ 
	if (!stream)
		return -1;//������ �������� �����
	int n;
	Pair p;
	cout << "N?"; cin >> n; for (int i = 0; i < n; i++)
	{
		cin >> p;//���� ��������� ������� �� ������������ ������ 
		stream << p << "\n";//������ ������� � �������� �����
	}
	stream.close();//������� �����
	return n;//������� ���������� ���������� ��������
}

static int print_file(const char* f_name)
{
	fstream stream(f_name, ios::in);//������� ��� ������ 
	if (!stream)
		return -1;//������ �������� �����
	Pair p; int i = 0; while (stream >> p)
	{
		cout << p << "\n"; i++;
	}
	stream.close(); return i;
}

static int del_file(const char* f_name, int k)
{
	fstream temp("temp", ios::out);//������� ��� ������ 
	fstream stream(f_name, ios::in);//������� ��� ������ 
	if (!stream)
		return -1;//������ �������� �����
	int i = 0; Pair p;
	while (stream >> p)//���� ��� ����� ����� ��������� ������ �������
	{
		//���� �������� ������� ����� �����,�� ����� �� ����� 
		if (stream.eof())
			break;
		//���� ����� ������� �� ����� k, �� ���������� ��� �� �������������� ����
		if ((p.first <= k) && (p.second <= k))
			temp << p;
	}
	//������� ����� 
	stream.close();
	temp.close();
	remove(f_name);//������� ������ ���� 
	rename("temp", f_name);// ������������� temp 
	return i;//���������� �����������
}

static int add_end(const char* f_name, Pair p)
{
	fstream stream(f_name, ios::app);//������� ��� ���������� 
	if (!stream)
		return -1;//������ �������� �����
	stream << p; //�������� ����� ������ 
	return 1;
}


static int add_file(const char* f_name, int k, Pair p)

{
	fstream temp("temp", ios::out);//������� ��� ������ 
	fstream stream(f_name, ios::in);//������� ��� ������ 
	if (!stream)
		return -1;//������ �������� �����
	Pair pp;
	int i = 0, l = 0;
	while (stream >> pp)
	{
		if (stream.eof())
			break;
		i++;
		if (i == k)
		{
			temp << pp;
			temp << p;
			i++;
		}
		else temp << pp;
	}
	stream.close();
	temp.close();
	remove(f_name);
	rename("temp", f_name);
	return l;//���������� �����������
}

static int change_file(const char* f_name, int k, int l)
{
	fstream temp("temp", ios::out);//������� ��� ������ 
	fstream stream(f_name, ios::in);//������� ��� ������ 
	if (!stream)
		return -1;//������ �������� �����
	Pair p;
	int i = 0, s = 0;
	while (stream >> p)
	{
		if (stream.eof())
			break;
		i++;
		if ((p.first == k) && (p.second == k))
		{
			p.first += l;
			p.second += l;
			temp << p;

		}
		else if (p.first == k) { p.first += l; temp << p; }
		else if (p.second == k) { p.second += l; temp << p; }
		else { temp << p; }
	}
	stream.close();
	temp.close();
	remove(f_name);
	rename("temp", f_name);
	return i;//���������� ���������� ���������
}