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
//Формирование массива (множества) из чисел,которые являются степенью двойки

void newArrayY(typeX s, typeX& Y) {
	Y.n = 0;
	typeitem* tmp;
	Y.X = (typeitem*)malloc(0);
	for (unsigned int i = 0; i < s.n; i++) {
		if (Test(s.X[i]) == true && s.X[i] < 100)
		{	//расширение исходного массива и добавление нового элемента
			if( (Y.X = (typeitem*)realloc(Y.X, (Y.n + 1) * sizeof(typeitem)))!=nullptr)
			{
					Y.X[Y.n] = s.X[i];
					Y.n++;
			}
		}
	}
}
//Проверяка упорядочены ли  цифры по возрастанию.
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