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
void find_min_path(typeX &x); //Нахождение оптимального пути



void input_arr(typeX& x) //Заполнение исходного массива 
{
	int ch;
	cout << "Ввведите 1 - заполнение с клавиатуры или 2 - случайные цифры: ";
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
		    case 2: x.X[i][j] = rand() % 10; break;
		    default:
			    break;
		    }
	    }
    }
}

void output_arr(typeX& x) //Вывод значений массива X
{
	std::cout << "Результат игры:\n";
	for (int i = 0; i < x.n; i++){
        for(int j = 0; j < x.m; j++){
	        std::cout << x.X[i][j] << " ";
        }
        cout<<endl;
	}
}


void find_min_path(typeX &x) { //Нахождение оптимального пути
    // инициализируем массив dp и заполняем его нулями
    int **dp = new int*[x.n];
    for (int i = 0; i < x.n; i++) {
        dp[i] = new int[x.m];
        memset(dp[i], 0, sizeof(int) * x.m);
    }
    // вычисляем значения в массиве dp
    for (int i = 0; i < x.n; i++) {
        for (int j = 0; j < x.m; j++) {
            if (i == 0 && j == 0) {
                dp[i][j] = x.X[i][j];
            } else if (i == 0) {
                dp[i][j] = dp[i][j - 1] + x.X[i][j];
            } else if (j == 0) {
                dp[i][j] = dp[i - 1][j] + x.X[i][j];
            } else {
                dp[i][j] = x.X[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    // вычисляем минимальную сумму на пути
    int min_sum = dp[x.n - 1][x.m - 1];
    // находим путь, который соответствует минимальной сумме
    int *path = new int[x.n + x.m - 1];
    int k = x.n + x.m - 2;
    int i = x.n - 1;
    int j = x.m - 1;
    while (i > 0 || j > 0) {
        path[k--] = i * x.m + j;
        if (i == 0) {
            j--;
        } else if (j == 0) {
            i--;
        } else if (dp[i - 1][j] < dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }
    path[k] = 0;
    // выводим результаты
    cout << "Minimal path sum: " << min_sum << endl;
    cout << "Minimal path: ";
    for (int k = 0; k < x.n + x.m - 1; k++) {
        cout << "(" << path[k] / x.m << ", " << path[k] % x.m << ") ";
    }
    cout << endl;
    // освобождаем выделенную память
    for (int i = 0; i < x.n; i++) {
        delete[] dp[i];
    }
    delete[] dp;
    delete[] path;
}