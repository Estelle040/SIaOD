#if defined(_WIN32) || defined(__WIN32__) || defined(WIN32)
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6308)
#endif
#include <iostream>
#include"stdlib.h"
#include"string.h"
using namespace std;
typedef unsigned int typeitem;
struct typeX {
	unsigned int n = 0;
	typeitem *X = nullptr;
	typeX(int n1) {
		n = n1; X = (typeitem*)malloc(n * sizeof(typeitem));
	}
	typeX() { n = 0; }
};

//Формирование массива (множества) из чисел,которые являются степенью двойки
void  newArrayY(typeX s, typeX& Y);
//Проверяка является ли число степенью двойки
bool Test(typeitem x);
//Заполнение множества с клавиатуры
void input_ar(typeX& s)
{
	cout << "Введите " << s.n << " чисел\n";
	for (unsigned int i = 0; i < s.n; i++)
		cin >> s.X[i];
}
//Вывод множества
void output_ar(typeX s)
{
	for (unsigned int i = 0; i < s.n; i++)
		cout << "X[" << i << "]=" << s.X[i] << endl;
}
//Формирование массива (множества) из чисел,которые являются степенью двойки

void newArrayY(typeX s, typeX& Y) {
	Y.n = 0;
	typeitem* tmp;
	Y.X = (typeitem*)malloc(0);
	for (unsigned int i = 0; i < s.n; i++) {
		if (Test(s.X[i]) == true)
		{	//расширение исходного массива и добавление нового элемента
			if( (Y.X = (typeitem*)realloc(Y.X, (Y.n + 1) * sizeof(typeitem)))!=nullptr)
			{
					Y.X[Y.n] = s.X[i];
					Y.n++;
			}
		}
		else{
			cout<< "В массиве нет подходящих чисел";
			break;
		}
	}
}
//Проверяем является ли число степенью двойки
bool Test(typeitem s) {
	if(s<=0)
    return false; 
    while((s%2)==0)
    {
    if((s/=2)==1)
        return true;
    }
return false;
}