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
    int n = 0;
    int m = 0;
	typeitem **X = nullptr;
	typeX(int n1, int m1) {
		n = n1;
        m = m1; 
        X = (typeitem**)malloc(n * sizeof(typeitem*));
        for (int i = 0; i < m; i++) {
            X[i] = (typeitem*)malloc(m * sizeof(int));
        }
	}
	typeX() { n = 0; m = 0;}
};

void input_arr(typeX& x); //Заполнение исходного массива 
void output_arr(typeX& x); //Вывод значений массива X
bool Test(typeX& x); // Определить, делится ли число на каждую цифру 



void input_arr(typeX& x) //Заполнение исходного массива 
{
	int ch;
	cout << "Ввведите 1 - заполнение с клавиатуры или 2 - случайный исход игры: ";
	cin >> ch;
	srand(time(NULL));
	for (int i = 0; i < x.n; i++){
        for(int j = 0; j<x.n; j++){
		    switch (ch)
		    {
		    case 1: cout << "X[" << i << "]["<<j<<"] = ";
                if(cin >> x.X[i][j] && x.X[i][j] == 1 || x.X[i][j] == 0){
                    break;
                }
                else{
                    cout<<"Введено неверное значение"<<endl;
                    break;
                }
		    case 2: x.X[i][j] = rand() % 2; break;
		    default:
			    break;
		    }
	    }
    }
}

void output_arr(typeX& x) //Вывод значений массива X
{
	cout << "Результат игры:\n";
	for (int i = 0; i < x.n; i++){
        for(int j = 0; j < x.m; j++){
	        cout << "X[" << i << "]["<<j<<"] = " << x.X[i][j] << endl;
        }
	}
}

bool Test(typeX& x){
// Проверка наличия цепочки из 5 крестиков
    for (int i = 0; i < x.n; i++) {
        for (int j = 0; j < x.m; j++) {
            if (x.X[i][j] == 1) {
                // Проверка по горизонтали
                if (j <= x.m - 5 && x.X[i][j+1] == 1 && x.X[i][j+2] == 1
                        && x.X[i][j+3] == 1 && x.X[i][j+4] == 1) {
                    return true;
                }
                // Проверка по вертикали
                if (i <= x.n - 5 && x.X[i+1][j] == 1 && x.X[i+2][j] == 1
                        && x.X[i+3][j] == 1 && x.X[i+4][j] == 1) {
                    return true;
                }
                // Проверка по диагонали (слева направо)
                if (i <= x.n - 5 && j <= x.m - 5 && x.X[i+1][j+1] == 1
                        && x.X[i+2][j+2] == 1 && x.X[i+3][j+3] == 1
                        && x.X[i+4][j+4] == 1) {
                    return true;
                }
                // Проверка по диагонали (справа налево)
                if (i <= x.n - 5 && j >= 4 && x.X[i+1][j-1] == 1
                        && x.X[i+2][j-2] == 1 && x.X[i+3][j-3] == 1
                        && x.X[i+4][j-4] == 1) {
                    return true;
                }
                else{
                    return false;
                }
            }
        }
    }
}