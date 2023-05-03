#include "Resu1.h"
#include <iostream>
#include <string>
using namespace std;

void input_arr(typeX& x) //Заполнение исходного массива 
{
	int ch;
	cout << "Ввведите 1 - заполнение с клавиатуры или 2 - заполнение случайными числами: ";
	cin >> ch;
	srand(time(NULL));
	for (int i = 0; i < x.n; i++)
	{
		switch (ch)
		{
		case 1: cout << "X[" << i << "] = "; cin >> x.X[i]; break;
		case 2: x.X[i] = 1+ rand() % 100; break;
		default:
			break;
		}
	}
}

void output_arr(typeX& x) //Вывод значений массива X
{
	cout << "Массив из " << x.n << " чисел:\n";
	for (int i = 0; i < x.n; i++){
	 cout << "X[" << i << "] = " << x.X[i] << endl;
	}
}

void delPosInX(typeX& x, int pos1) //Удалить элемент в заданной позиции
{
	if (pos1 < x.n)
	{   
        x.n--;
		for (int i = pos1; i < x.n; i++)
		{   
			x.X[i] = x.X[i + 1];
		}
	}
	else
		cout << "Позиция не найдена. Массив не изменится\n";
}


void insertX(typeX& x, int pos2, int N_num) //Вставить элемент в заданную позицию
{
	x.n++;
	for (int i = x.n; i >= pos2; i--)
	x.X[i] = x.X[i - 1];
	x.X[pos2] = N_num;
}
int Search2(typeX& x){  // //Найти позицию первого элемента последовательности
    int h = 0;
    int max = 0;
    int id1=x.X[0];
    for(int i = 0; i <= x.n; i++){
        if(x.X[i] <= x.X[i+1]){
            h += 1;
        }
        else{
            if(h>max){
                id1=i;
                max = h;
            }
            h = 0;
        }

    }
    if(max>1){
        return id1;
    }
    else{
        return -1;
    }
}

int Search1(typeX& x){  //Найти позицию последнего элемента последовательности
    int h = 0;
    int max = 0;
    int id2=x.X[0];
    for(int i = 0; i <= x.n; i++){
        if(x.X[i] <= x.X[i+1]){
            h += 1;
        }
        else{
            if(h>max){
                id2=i-h;
                max = h;
            }
            h = 0;
        }

    }
    if(max>1){
        return id2;
    }
    return 0;
}


int main()
{
	setlocale(0, "");
	int n;
	cout << "Введите количество элементов множества n: ";
	cin >> n;
	typeX x(n);
	if (n > 0 && n < N)
	{
		int t;
		input_arr(x);
		cout << "Меню:\nВведите 1,  чтобы вывести исходный массив;\n" <<
			"Введите 2, чтобы найти Позиция первого и последнего элемента самой длинной возрастающей последовательности;\nВведите 3, чтобы добавить элемент перед первым элементом последовательности;\n" <<
			"Введите 4, чтобы удалить все элементы последовательности;\nВведите 5, чтобы завершить программу." << endl;
		bool F = true;
		while (F) {
			while (!(cin >> t)) {
				cin.clear();
				while (cin.get() != '\n');
				cout << "Введены некорректные данные! Повторите попытку!" << endl;
			}
			switch (t)
			{
			case 1:
				output_arr(x);
				break;
			case 2:
                if (Search2(x) != -1) {
                    cout << "Задание 1. Позиция первого и последнего элемента самой длинной возрастающей последовательности = "<<Search1(x)<<" и "<<Search2(x);
					break;
				}
				else {
					F = false;
					cout << "Нет подходящих последовательностей!" << endl;
					break;
                }
				
                break;
			case 3:
				int u;
				cout << "Введите новое значение для массива:" << endl;
				while (!(cin >> u)) {
					cin.clear();
					while (cin.get() != '\n');
					cout << "Введены некорректные данные! Повторите попытку!" << endl;
				}
				if (Search2(x) != -1) {
					/*cout << "Задание 2. Массив с элементом, добавленным перед первым элементом посддедовательности: ";*/
					insertX(x, Search1(x), u);
					break;
				}
				else {
					F = false;
					cout << "Нет подходящих последовательностей, массив не изменится!" << endl;
					break;
                }
			case 4:
            	/*cout << "Задание 3. Массив без элементов последовательности: ";*/
				if (Search2(x) != -1) {
                    int id1=Search1(x);
                    int id2=Search2(x);
					for(int i=0;i<id2-id1+1;i++){
                        delPosInX(x, id1);
                    }  
				break;
				}
				else {
					F = false;
					cout << "Нет подходящих последовательностей, массив не изменится!" << endl;
					break;
				}

			case 5:
				x.~typeX();
				F = false;
				return 0;
			default:
				cout << "Введено неверное значение!" << endl;
				break;
			}
		}
	}

	return 0;
}
