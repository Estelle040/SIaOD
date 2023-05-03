#pragma once
#include <iostream>
#include <vector>
#include"string.h"
using namespace std;
typedef double typeitem;
	
struct typeX {
    int n = 0;
    int b = 0;
    vector<vector<int> > X;
    vector<double> B;
    typeX(int n1, double b1) {
        n = n1;
        b = b1;
        X.resize(n1, vector<int>(n1));
        B.resize(b1);
    }
    typeX() { n = 0; }
};


void input_arr(typeX& x); //Заполнение исходного массива 
void output_arr(typeX& x); //Вывод значений массива X
int Solution(typeX& x); // Определить, делится ли число на каждую цифру 



void input_arr(typeX& x) //Заполнение исходного массива 
{
	int ch;
	cout << "Ввведите 1 - заполнение с клавиатуры или 2 - случайный исход игры: ";
	cin >> ch;
	srand(time(NULL));
	// for (int i = 0; i < x.n; i++){
    //     for(int j = 0; j<x.n; j++){
		    switch (ch)
		    {
		    case 1: 
                cout << "Введите коэффициенты матрицы системы:" << endl;
                for (int i = 0; i < x.n; i++) {
                    for (int j = 0; j < x.n; j++) {
                    cin >> x.X[i][j];
                    }
                }
                cout << "Введите свободные члены:" << endl;
                for (int i = 0; i < x.n; i++) {
                    cin >> x.B[i];
                }
                break;
		    case 2: 
               for (int i = 0; i < x.n; i++) {
                    for (int j = 0; j < x.n; j++) {
                     x.X[i][j] = 1 + rand() % 100; 
                    }
                }
                for (int i = 0; i < x.n; i++) {
                    x.B[i]  = 1 + rand() % 100; 
                }
                break;
		    default:
			    break;
		    }
	    }

void output_arr(typeX& x) //Вывод значений массива X
{
	cout << "Коэффициенты матрицы системы:" << endl;
    for (int i = 0; i < x.n; i++) {
        for (int j = 0; j < x.n; j++) {
            cin >> x.X[i][j];
        }
    }
    cout << "Свободные члены:" << endl;
    for (int i = 0; i < x.n; i++) {
        cin >> x.B[i];
    }
}

int Solution(typeX& x){

    // Прямой ход метода Гаусса
    for (int k = 0; k < x.n; k++) {
        double max_elem = abs(x.X[k][k]);
        int max_row = k;
        for (int i = k + 1; i < x.n; i++) {
            if (abs(x.X[i][k]) > max_elem) {
                max_elem = abs(x.X[i][k]);
                max_row = i;
            }
        }
        for (int j = k; j < x.n; j++) {
            x.X[k][j] = x.X[max_row][j];
        }
            x.B[k] = x.B[max_row];
        for (int i = k + 1; i < x.n; i++) {
            double coeff = -x.X[i][k] / x.X[k][k];
            for (int j = k; j < x.n; j++) {
                x.X[i][j] += coeff * x.X[k][j];
            }
            x.B[i] += coeff * x.B[k];
        }
    }

    // Обратный ход метода Гаусса
    vector<double> s;
    for (int i = x.n - 1; i >= 0; i--) {
        double sum = 0.0;
        for (int j = i + 1; j < x.n; j++) {
            sum += x.X[i][j] * s[j];
        }
        s[i] = (x.B[i] - sum) / x.X[i][i];
    }

    // Выводим решение системы
    cout << "Решение системы:" << endl;
    for (int i = 0; i < x.n; i++) {
        cout << "x" << i + 1 << " = " << s[i] << endl;
    }
}
