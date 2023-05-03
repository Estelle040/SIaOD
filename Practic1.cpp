#include "Practic1.h"
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
    for (long j = i; j < x.n; ++j)
  	{
    	x.X[j] = x.X[j + 1];
  	}
  	x.n--;
  	i--;
  }
  
 }
}

void insertX(typeX& x, int pos2, int N_num) //Вставить элемент в заданную позицию
{
	if (pos2 <= x.n)
	{
		x.n++;
		for (int i = 1; i <= pos2; i++)
		x.X[i] = x.X[i+1];
		x.X[pos2] = N_num;
	}
	else
		cout << "Значение не соответствует условию задачи. Массив не изменится\n";
}

bool Test(int s)  // Проверить, делится ли число на все свои цифры 
{
	if (s < 10) {
		return true;
	}
	else if(s % 10 == 0){
		return false;
	}
	else if(s % (s % 10) == 0 && s % (s / 10) == 0){
		return true;
	}
	else{
		return false;
	}

}

int Perfect(typeX& x) {  // Найти позицию первого числа, которое делится на свои цифры
	int indexPerfect;
	bool Y = true;
	for (int i = 0; i < x.n; i++) {
		if (Test(x.X[i])) {
			indexPerfect = i;
			Y = false;
			return indexPerfect;
		}
	}
	if (Y == true) { cout << "В данном массиве нет подходящих чисел!" << endl; return -1; }
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
			"Введите 2, чтобы найти первое число, делящееся на все свои цифры;\nВведите 3, чтобы добавить элемент после числа, делящегося на все свои цифры;\n" <<
			"Введите 4, чтобы удалить все элементы, делящиеся на 3;\nВведите 5, чтобы завершить программу." << endl;
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
				cout << "Задание 1. Позиция первого числа, делящегося на все свои цифры = " << Perfect(x) << endl;
				break;
			case 3:
				int u;
				cout << "Введите новое значение для массива:" << endl;
				while (!(cin >> u)) {
					cin.clear();
					while (cin.get() != '\n');
					cout << "Введены некорректные данные! Повторите попытку!" << endl;
				}
				if (Perfect(x) != -1) {
					/*cout << "Задание 2. Массив с элементом, добавленным после числа, которое делится на цифры: ";*/
					insertX(x, Perfect(x) + 1, u);
					break;
				}
				else {
					F = false;
					cout << "В данном массиве нет подходящих чисел!" << endl;
					break; }
			case 4:
					/*cout << "Задание 3. Массив без элемента, стоящего перед совершенным числом: ";*/
					delPosInX(x);
					cout<<"Если в массиве были числа делящиеся на 3, они удалились."<<endl;
					break;
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
