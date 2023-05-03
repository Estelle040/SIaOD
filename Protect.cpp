#include "Protect.h"
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

void delPosInX(typeX& x) //Удалить элемент в заданной позиции
{
 for (int i = 0; i < x.n; i++)
 {
  if(x.X[i] % 3 == 0){
    for (int j = i; j < x.n; ++j)
  	{
    	x.X[j-1] = x.X[j];
  	}
  	x.n--;
  	i--;
  }
  
 }
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
			"Введите 2, чтобы удалить все числа, стоящие перед элементами, делящимися на 3;\nВведите 3, чтобы завершить программу." << endl;
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
					delPosInX(x);
					cout<<"Если в массиве были числа, стоящие перед элементами, делящимися на 3, они удалились."<<endl;
					break;
			case 3:
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
