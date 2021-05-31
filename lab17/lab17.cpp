#include <iostream>
#include <list>
#include <fstream>
#include <windows.h>
#include <math.h>
#include <string>
using namespace std;

struct people
{
    string fio;
    string cardnum;
    string summ;
};


int Hash_fun(string s, int n)
{
    int l;
    l = s.size();
    return (l % n);
}


int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    int size = 0;
    int hash;
    people x;
    string user_search;
    int error = 0;
    while (size < 2 || size>100)
    {
        cout << "Введите размер таблицы: ";
        cin >> size;
    }
    const int N = size;
    cin.get();

    people* hash_base = new people[size];
    string* key = new string[size];

    for (int i = 0; i < size; i++)
        key[i] = "Пусто";

    ifstream F1("fio.txt");
    ifstream F2("card.txt");
    ifstream F3("summ.txt");

    for (int i = 0; i < N; i++)
    {
        getline(F1, x.fio);
        getline(F2, x.cardnum);
        getline(F3, x.summ);

        hash = Hash_fun(x.fio, N);

        while (hash >= size || key[size - 1] != "Пусто")
        {
            people* hash_base1 = new people[size * 2];
            string* key_new = new string[size * 2];
            for (int i = 0; i < size; i++)
            {
                hash_base1[i] = hash_base[i];
                key_new[i] = key[i];
            }
            for (int i = size; i < size * 2; i++) key_new[i] = "Пусто";
            delete[] hash_base;
            delete[] key;
            hash_base = hash_base1;
            key = key_new;
            size *= 2;
        }

        if (key[hash] != "Пусто")
        {
            error++;
            while (key[hash] != "Пусто") hash++;
            cout << endl;
        }

        hash_base[hash] = x;
        key[hash] = x.fio;
        cout << "ФИО- " << x.fio << endl;
        cout << "Номер счета- " << x.cardnum << endl;
        cout << "Сумма- " << x.summ << "\n" << endl;

    }

    cout << "Таблица создана. Коллизий: " << error << endl;

    for (int i = 0; i < size; i++)
    {
        cout << i << " -->" << key[i] << endl;
    }

    cout << "Введите запрос\n";
    getline(cin, user_search);
    hash = Hash_fun(user_search, N);
    bool f = true;
    while (hash < size && (f))
    {
        if (key[hash] == user_search)
        {
            cout << "Объект найден:\n";
            cout << "ФИО- " << hash_base[hash].fio << endl;
            cout << "Номер счета- " << hash_base[hash].cardnum << endl;
            cout << "Сумма- " << hash_base[hash].summ << endl;
            f = false;
        }
        if (key[hash] == "Пусто")
        {
            cout << "Неизвестный объект [Пустая ячейка]\n";
            f = false;
        }
        hash++;
    }
    if (hash == size) cout << "Неизвестный объект [Пустая ячейка]\n";
}
