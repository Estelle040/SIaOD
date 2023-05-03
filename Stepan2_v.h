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
//Формирование массива (множества) из чисел, цифры которых упорядочены по возрастанию.
void  newArrayY(typeX s, typeX& Y);
//Проверяка упорядочены ли  цифры по возрастанию.
bool Test(typeitem x);

//Заполнение множества с клавиатуры
void input_ar(typeX& s)
{
	cout << "Ввведите 1 - заполнение с клавиатуры или 2 - заполнение случайными числами: ";
	int ch;
	cin >> ch;
	srand(time(NULL));
	for (int i = 0; i < s.n; i++)
	{
		switch (ch)
		{
		case 1: cout << "X[" << i << "] = "; cin >> s.X[i]; break;
		case 2: s.X[i] = 1+ rand() % 100;
				cout <<"X[" <<  i << "] = " << s.X[i]<<endl;
				break;
		default:
			break;
		}
	}
}
//Вывод множества
void output_ar(typeX s)
{
	for (unsigned int i = 0; i < s.n; i++)
		cout << "X[" << i << "]=" << s.X[i] << endl;
}
//Формирование массива (множества) из чисел, цифры которых упорядочены по возрастанию.
void newArrayY(typeX s, typeX& Y) {
	for (unsigned int i = 0; i < s.n; i++) {
		if (Test(s.X[i]) == true && s.X[i]<100)
		{
			Y.X.push_back(s.X[i]);
		}
	}
	Y.n = Y.X.size();
}
//Проверяем  упорядочены ли  цифры по возрастанию.
bool Test(typeitem s) {
	if (s < 10) {
		return true;
	}
	else if(s % 10 >= s / 10){
			return true;
	}
	else{
		return false;
	}
}
