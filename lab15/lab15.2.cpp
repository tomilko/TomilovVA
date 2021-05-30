#include <iostream>

using namespace std;

int i, j, n, d, co;
string name1;

void HoaraSort(int* left, int* right, string* left_1, string* right_1, string* left_2, string* right_2)
{
    if (left == right) return;
    int* l = left;
    string* l_1 = left_1;
    string* l_2 = left_2;
    int* r = right;
    string* r_1 = right_1;
    string* r_2 = right_2;
    int* pivot = left;
    string* pivot_1 = left_1;
    string* pivot_2 = left_2;
    while (l <= r) {
        if (*l > * pivot && *r <= *pivot)
        {
            swap(*l, *r);
            swap(*l_1, *r_1);
            swap(*l_2, *r_2);
            continue;
        }
        if (*l <= *pivot)
        {
            l++;
            l_1++;
            l_2++;
            continue;
        }
        if (*r > * pivot)
        {
            r_1++;
            r_2++;
            r--;
            continue;
        }
    }
    if (l > right)
    {
        l--;
        l_1--;
        l_2--;
        r--;
        r_1--;
        r_2--;
        swap(*l, *pivot);
        swap(*l_1, *pivot_1);
        swap(*l_2, *pivot_2);
    };
    HoaraSort(left, r, left_1, r_1, left_2, r_2);
    HoaraSort(l, right, l_1, right_1, l_2, right_2);
}

/*void Shell(int start[], string number[], int n) //сортировка Шелла
{
    d = n;
    d = d / 2;
    while (d > 0)
    {
        for (i = 0; i < n - d; i++)
        {
            j = i;
            while (j >= 0 && start[j] > start[j + d])
            {
                co = start[j];
                name1 = number[j];
                start[j] = start[j + d];
                number[j] = number[j + d];
                start[j + d] = co;
                number[j + d] = name1;
                j--;
            }
        }
        d = d / 2;
    }
    for (i = 0; i < n; i++)
        cout << number[i] << "  " << start[i] << endl; //вывод массива
}*/




int main()
{
    system("chcp 1251 > nul");
    setlocale(LC_ALL, "rus");
    int n, i, num;
    n = 0;


    do {
        cout << "Введите количество поездов ";
        cin >> n;
    } while (n < 0);

    string* final = new string[n];
    string* start = new string[n];
    int* number = new int[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Введите город отправления ";
        cin >> start[i];
        cout << "Введите город прибытия ";
        cin >> final[i];
        do {
            cout << "Введите номер поезда ";
            cin >> number[i];
        } while (number[i] < 0);

    }
    for (int i = 0; i < n; i++) {
        cout << "\nГород отправления " << start[i] << endl << "Город прибытия " << final[i] << endl << "Номер поезда " << number[i];
    }
    cout << endl;
    HoaraSort(number, number + n - 1, start, start + n - 1, final, final + n - 1);
    for (int i = 0; i < n; i++) {
        cout << "\nГород отправления " << start[i] << endl << "Город прибытия " << final[i] << endl << "Номер поезда " << number[i] << endl;
    }
}
