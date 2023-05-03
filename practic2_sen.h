#if defined(_WIN32) || defined(__WIN32__) || defined(WIN32)
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6308)
#endif
#include <iostream>
#include"stdlib.h"
#include"string.h"
using namespace std;
typedef int typeitem;
struct typeX {
    unsigned int n = 0;
    typeitem* X = NULL;
    typeX(int n1) {
        n = n1;
        X = (typeitem*)malloc(n * sizeof(typeitem));
    }
    typeX() {
        n = 0;
        X = NULL;
    }
    ~typeX() {
        free(X);
    }
};

void input_ar(typeX& x); //Заполнение исходного массива 
void output_ar(typeX& x); //Вывод значений массива X
void delPosInX(typeX& x); //Удалить элемент в заданной позиции;
void insertX(typeX& x, int pos2, int N_num); //Вставить элемент в заданную позицию
int maxIndex(typeX s); //Найти индекс максимального элемента массива, среди четных чисел массива

void input_arr(typeX& x) {
    int ch;
    cout << "Введите 1 - заполнение с клавиатуры или 2 - заполнение случайными числами: ";
    cin >> ch;
    srand(time(NULL));
    for (int i = 0; i < x.n; i++) {
        switch (ch) {
        case 1: 
            cout << "X[" << i << "] = "; 
            cin >> x.X[i]; 
            break;
        case 2: 
            x.X[i] = 1 + rand() % 100; 
            break;
        default:
            break;
        }
    }
}

void output_arr(typeX& x) {
    cout << "Массив из " << x.n << " чисел:\n";
    for (int i = 0; i < x.n; i++) {
        cout << "X[" << i << "] = " << x.X[i] << endl;
    }
}

void delPosInX(typeX& x, int pos1) {
    if (pos1 < x.n) {
        x.n--;
        for (int i = pos1; i < x.n; i++) {
            x.X[i] = x.X[i + 1];
        }
        x.X = (typeitem*)realloc(x.X, x.n * sizeof(typeitem));
    }
    else {
        cout << "Позиция не найдена. Массив не изменится\n";
    }
}

void insertX(typeX& x, int pos2, int N_num) {
    if (pos2 <= x.n) {
        x.n++;
        x.X = (typeitem*)realloc(x.X, x.n * sizeof(typeitem));
        for (int i = x.n - 1; i > pos2; i--) {
            x.X[i] = x.X[i - 1];
        }
        x.X[pos2 + 1] = N_num;
    }
    else {
        cout << "Значение не соответствует условию задачи. Массив не изменится\n";
    }
}

int maxIndex(typeX s) {
    int max = -1;
    int index = -1;

    for (int i = 0; i < s.n; i++) {
        if (s.X[i] % 2 == 0 && s.X[i] > max) {
            max = s.X[i];
            index = i;
        }
    }

    return index;
}

