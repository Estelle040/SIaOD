#pragma once
#include <iostream>
#include <vector>
#include"string.h"
using namespace std;
typedef unsigned int typeitem;
struct typeX {
	unsigned int n = 0;
	vector<typeitem> X;
	typeX(int n1) {
		n = n1; X.resize(n1);
	}
	typeX() { n = 0; }
};
//Вывод множества
void output_X(typeX s);
//Заполнение множества с клавиатуры
void input_X(typeX& s);
//Формирование массива (множества) из чисел,которые являются степенью двойки
void  newArrayY(typeX s, typeX& Y);
//Проверяка является ли число степенью двойки
bool Test(typeitem x);

//Заполнение множества с клавиатуры
void input_ar(typeX& s)
{
	cout << "Введите " << s.n << " числа:\n";
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
	for (unsigned int i = 0; i < s.n; i++) {
		if (Test(s.X[i]) == true)
		{
			Y.X.push_back(s.X[i]);
		}
	}
	Y.n = Y.X.size();
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
