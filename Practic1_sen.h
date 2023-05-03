#pragma once
#include <iostream>
#include <ctime>
using namespace std;
typedef int typeitem;
const unsigned int N = 100;
struct typeX
{
	unsigned int n = 0;
	typeitem X[N] = {};
	typeX(int n1) { n = n1; }
	typeX() { n = 0; }

};


void input_arr(typeX& x); //Заполнение исходного массива 
void output_arr(typeX& x); //Вывод значений массива X
void delPosInX(typeX& x); //Удалить элемент в заданной позиции;
void insertX(typeX& x, int pos2, int N_num); //Вставить элемент в заданную позицию
int findMaxEvenIndex(typeX& x); //Найти индекс максимального элемента массива, среди четных чисел массива

