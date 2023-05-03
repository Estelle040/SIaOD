#include <iostream>

using namespace std;
typedef unsigned int typeitem;
const unsigned int N = 100;
//Определение данных АТД задачи
struct typeX {
    unsigned int n = 0;
    typeitem X[N] = {};
    typeX(int n1) { n = n1; }
	typeX() { n = 0; }
};
void input_array(typeX& a, int n);
void output_array(typeX& a);
int search(typeX& a, int x);


void input_array(typeX a, int n)
{
    cout << "vvedite " << n << " numbers \n";
    for (int i = 0; i < n; i++)
        cin >> a.X[i];
    a.n = n;
}

void output_array(typeX a)
{
    cout << "Array iz " << a.n << " numbers";
    for (int i = 0; i < a.n; i++)
        cout << a.X[i] << ' ';
}

int search(typeX a, int x)
{
    for (int i = 0; i < a.n; i++)
        if (a.X[i] == x) return i;
    return -1;
}