#include "Pair.h"
#include <iostream>
#include <fstream>
using namespace std;

static int make_file(const char* f_name)
{
	fstream stream(f_name, ios::out | ios::trunc); //открыть для записи 
	if (!stream)
		return -1;//ошибка открытия файла
	int n;
	Pair p;
	cout << "N?"; cin >> n; for (int i = 0; i < n; i++)
	{
		cin >> p;//ввод атрибутов объекта из стандартного потока 
		stream << p << "\n";//запись объекта в файловый поток
	}
	stream.close();//закрыть поток
	return n;//вернуть количество записанных объектов
}

static int print_file(const char* f_name)
{
	fstream stream(f_name, ios::in);//открыть для чтения 
	if (!stream)
		return -1;//ошибка открытия файла
	Pair p; int i = 0; while (stream >> p)
	{
		cout << p << "\n"; i++;
	}
	stream.close(); return i;
}

static int del_file(const char* f_name, int k)
{
	fstream temp("temp", ios::out);//открыть для записи 
	fstream stream(f_name, ios::in);//открыть для чтения 
	if (!stream)
		return -1;//ошибка открытия файла
	int i = 0; Pair p;
	while (stream >> p)//пока нет конца файла выполняем чтение объекта
	{
		//если прочитан признак конца файла,то выход из цикла 
		if (stream.eof())
			break;
		//если номер объекта не равен k, то записываем его во вспомогательый файл
		if ((p.first <= k) && (p.second <= k))
			temp << p;
	}
	//закрыть файлы 
	stream.close();
	temp.close();
	remove(f_name);//удалить старый файл 
	rename("temp", f_name);// переименовать temp 
	return i;//количество прочитанных
}

static int add_end(const char* f_name, Pair p)
{
	fstream stream(f_name, ios::app);//открыть для добавления 
	if (!stream)
		return -1;//ошибка открытия файла
	stream << p; //записать новую запись 
	return 1;
}


static int add_file(const char* f_name, int k, Pair p)

{
	fstream temp("temp", ios::out);//открыть для записи 
	fstream stream(f_name, ios::in);//открыть для чтения 
	if (!stream)
		return -1;//ошибка открытия файла
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
	return l;//количество добавленных
}

static int change_file(const char* f_name, int k, int l)
{
	fstream temp("temp", ios::out);//открыть для записи 
	fstream stream(f_name, ios::in);//открыть для чтения 
	if (!stream)
		return -1;//ошибка открытия файла
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
	return i;//количество измененных элементов
}