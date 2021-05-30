#include <iostream>
#include <list>
#include <cstdlib>
#include "Pair.h"
using namespace std;

typedef list<Pair>List;

List make_list(int n)
{
    List lst;
    for (int i = 0; i < n; i++)
    {
        Pair a;
        a.first = rand() % 999;
        a.second = double(rand() % 999) / 10;
        lst.push_back(a);
    }
    return lst;
}

void PrintList(List lst)
{
    for (List::const_iterator i = lst.begin(); i != lst.end(); i++)
        cout << *i << "   ";
    cout << endl;
}

List srednee(List lst)
{
    int sfrst = 0;
    double sscnd = 0;
    for (List::iterator i = lst.begin(); i != lst.end(); i++)
    {
        sscnd = sscnd + (*i).second;
        sfrst = sfrst + (*i).first;
    }
    int n = lst.size();
    Pair a;
    a.first = sfrst / n;
    a.second = sscnd / n;
    cout << "Среднее арифметическое значение элементов first= " << a.first << " , second= " << a.second << ".\n";
    lst.push_back(a);
    return lst;
}

Pair min(List lst)
{
    List::iterator i = lst.begin();
    Pair min = *i;
    for (List::iterator i = lst.begin(); i != lst.end(); i++)
        if (*i < min)
            min = *i;
    return min;
}

Pair max(List lst)
{

    List::iterator i = lst.begin();
    Pair max = *i;
    for (List::iterator i = lst.begin(); i != lst.end(); i++)
        if (*i > max)
            max = *i;
    return max;
}

List add(List lst)
{
    for (List::iterator i = lst.begin(); i != lst.end(); i++)
    {
        *i = *i + min(lst) + max(lst);
    }
    return lst;
}

List dlt(List lst)
{
    double a, b;
    cout << "Введите границы диапазона для поиска.\n Введите левую границу: ";
    cin >> a;
    cout << " Введите правую границу: ";
    cin >> b;
    List::iterator i = lst.begin();
    int k = lst.size();
    while (i != lst.end())
    {
        if (((*i).first > a && (*i).first < b) || (*i).second > a && (*i).second < b)
        {
            lst.erase(i++);
            k--;
        }
        else
        {
            ++i;
        }
    }
    if (k == 0) { cout << "Пустой список"; List lst; exit; }
    else return lst;
}

void main()
{
    setlocale(LC_ALL, "RU");
    try
    {
        list<Pair> MyList;
        list<Pair>::iterator it = MyList.begin();
        int n;
        cout << "Введите количество элементов в списке: ";
        cin >> n;
        MyList = make_list(n);
        PrintList(MyList);
        MyList = srednee(MyList);
        cout << "Список после добавления элемента со САЗ в конец:\n";
        PrintList(MyList);
        MyList = dlt(MyList);
        cout << "Список после удаления элементов из заданного диапазона:\n";
        PrintList(MyList);
        cout << "Минимальный элемент списка= " << min(MyList) << " , максимальный = " << max(MyList) << endl;
        MyList = add(MyList);
        cout << "Список после добавления значения минимального и максимального элемента к каждому в списке:\n";
        PrintList(MyList);
    }
    catch (int)
    {
        cout << "Error!";
    }
}