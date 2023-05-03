#include <iostream>
#include "Stepan2_v.h"

int main()
{
	int n;
	cout << "Введите размер массива a(каждое число должно быть меньше 100):"; cin >> n;
	if (n > 0) {
		typeX a(n), b;
		input_ar(a);
		newArrayY(a, b);
		if (b.n > 0) {
			cout << "Массив из чисел, цифры которых упорядочены по возрастанию: \n";
			output_ar(b);
		}
		else
			cout << "Нет подходящих чисел в массиве a.\n";
	}
	else
		cout << "n<0 \n";
	return 0;
}
