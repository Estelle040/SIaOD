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
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

typedef int typeitem;

struct typeX {
    unsigned int n = 0;
    vector<typeitem> X;
    typeX(int n1) {
        n = n1;
        X.resize(n);
    }
    typeX() {
        n = 0;
        X.clear();
    }
};

void input_arr(typeX& x); //Заполнение исходного массива 
void output_arr(typeX& x); //Вывод значений массива X
void delPosInX(typeX& x, int pos1); //Удалить элемент в заданной позиции;
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
        x.X.resize(x.n);
    }
    else {
        std::cout << "Позиция не найдена. Массив не изменится\n";
    }
}

void insertX(typeX& x, int pos2, int N_num) {
    if (pos2 <= x.n) {
        x.n++;
        x.X.resize(x.n);
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