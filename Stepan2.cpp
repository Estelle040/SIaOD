#include <iostream>
#include "Stepan2.h"

int main()
{
	int n;
	cout << "Введите размер массива A(каждое число должно быть меньше 100): "; cin >> n;
	if (n > 0 ) {
		typeX a(n), b;
		input_ar(a);
		newArrayY(a, b);
		if (sizeof(b) > 0) {
			cout << "Массив из чисел, цифры которых упорядочены по возрастанию:\n";
			output_ar(b);
		}
		else
			cout << "В массиве a нет подходящих чисел\n";
	}
	else
		cout << "n<0"<< "\n";
	return 0;
}