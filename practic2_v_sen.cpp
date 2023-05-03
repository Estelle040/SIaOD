#include <iostream>
#include "practic2_v_sen.h"


int main()
{
	setlocale(0, "");

	int n;
	cout << "Введите количество элементов множества n: ";
	cin >> n;
	typeX s(n);
		int t;
		input_arr(s);
		cout << "Меню:\nВведите 1,  чтобы вывести исходный массив;\n" <<
			"Введите 2, чтобы найти индекс максимального элемента массива, среди четных чисел массива;\nВведите 3, чтобы вставить новый элемент в массив после элемента с максимальным значением среди черных чисел массива.;\n" <<
			"Введите 4, чтобы удалить элемент массива, расположенный перед элементом, с максимальным значением среди черных чисел массива.;\nВведите 5, чтобы завершить программу." << endl;
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
				output_arr(s);
				break;
			case 2:
				cout << "Задание 1. Индекс максимального элемента массива, среди четных чисел массива = " << maxIndex(s) << endl;
				break;
			case 3:
				int u;
				cout << "Введите новое значение для массива:" << endl;
				while (!(cin >> u)) {
					cin.clear();
					while (cin.get() != '\n');
					cout << "Введены некорректные данные! Повторите попытку!" << endl;
				}
				if (maxIndex(s) != -1) {
					/*cout << "Задание 2. Массив с элементом, добавленным после числа, которое делится на цифры: ";*/
					insertX(s, maxIndex(s) + 1, u);
					break;
				}
			case 4:
					/*cout << "Задание 3. Массив без элемента, стоящего перед совершенным числом: ";*/
					delPosInX(s, maxIndex(s) - 1);
					break;
			case 5:
				s.~typeX();
				F = false;
				return 0;
			default:
				cout << "Введено неверное значение!" << endl;
				break;
			}
		}
	return 0;
}

