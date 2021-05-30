#include <iostream>
#include <list>
#include <cstdlib>
using namespace std;

typedef list<double> List;

List make_list(int n)
{
    List lst;
    for (int i = 0; i < n; i++)
    {
        double a = double(rand() % 9999) / 50;
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

double srednee(List lst)
{
    double a = 0;
    for (List::iterator i = lst.begin(); i != lst.end(); i++)
        a = a + *i;
    int n = lst.size();
    return a / n;
}

double min(List lst)
{
    List::iterator i = lst.begin();
    double min = *i;
    for (List::iterator i = lst.begin(); i != lst.end(); i++)
        if (*i < min)
            min = *i;
    return min;
}

double max(List lst)
{
    List::iterator i = lst.begin();
    double max = *i;
    for (List::iterator i = lst.begin(); i != lst.end(); i++)
        if (*i > max)
            max = *i;
    return max;
}

List add(List lst)
{
    double mn = min(lst);
    double mx = max(lst);
    for (List::iterator i = lst.begin(); i != lst.end(); i++)
    {
        *i = *i + mn + mx;
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
    while (i != lst.end())
    {
        if (*i > a && *i < b)
        {   
            lst.erase(i++);
        }
        else
        {
            ++i;
        }
    }
    return lst;
}

void main()
{
    setlocale(LC_ALL, "ru");
    try
    {
        list<double> MyList;
        list<double>::iterator it = MyList.begin();
        int n;
        cout << "Введите количество элементов в списке: ";
        cin >> n;
        MyList = make_list(n);
        PrintList(MyList);
        cout << "\t3 задание\n";
        cout << "Среднее арифметическое элементов списка = " << srednee(MyList) << endl;
        MyList.push_back(srednee(MyList));
        PrintList(MyList);
        cout << "\t4 задание\n";
        MyList = dlt(MyList);
        PrintList(MyList);
        cout << "\t5 задание\n";
        cout << "Минимальный элемент = " << min(MyList);
        cout << "\tМаксимальный элемент = " << max(MyList);
        MyList = add(MyList);
        cout << "\nИзмененный список: ";
        PrintList(MyList);
    }
    catch (int)
    {
        cout << "Error!";
    }
}