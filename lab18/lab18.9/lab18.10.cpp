﻿#include "Pair.h" 
#include <iostream> 
#include <fstream> 
#include "file_work.h"
using namespace std;
void main()
{
	Pair p, p1, p2;
	int k, c;
	char file_name[30]; do
	{	//Меню
		cout << "\n1. Make file";
		cout << "\n2. Print file";
		cout << "\n3. Delete records from file";
		cout << "\n4. Add record to file";
		cout << "\n5. Change record in file";
		cout << "\n0. Exit\n";
		cin >> c;
		switch (c)
		{
		case 1:
			cout << "file name?";
			cin >> file_name;
			k = make_file(file_name);
			if (k < 0)
				cout << "Can't make file";
			break;
		case 2:
			cout << "file name?";
			cin >> file_name;
			k = print_file(file_name);
			if (k == 0)
				cout << "Empty file\n";
			if (k < 0)
				cout << "Can't read file\n";
			break;
		case 3:
			cout << "file name?";
			cin >> file_name;
			int nom;
			cout << "nom?";
			cin >> nom;
			k = del_file(file_name, nom);
			if (k < 0)
				cout << "Can't read file";
			break;
		case 4: {
			int num;
			cout << "file name?";
			cin >> file_name;
			cout << "nom?";
			cin >> nom;
			cout << "num?";
			cin >> num;
			for (int i = 0; i < num; i++) {
				cout << "New pair:";
				Pair p1;
				cin >> p1;
				k = add_file(file_name, nom, p1);
				nom++;
			}
			break;
		}
		case 5:
			int num;
			cout << "file name?";
			cin >> file_name;
			cout << "nom?";
			cin >> nom;
			cout << "num?";
			cin >> num;
			k = change_file(file_name, nom, num);
		}
	} while (c != 0);
}