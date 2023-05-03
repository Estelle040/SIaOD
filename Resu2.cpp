#include <iostream>
#include "Resu2.h"

int main()
{
	int n;
	cout << "Введите размер массива a: "; cin >> n;
	if (n > 0 ) {
		typeX a(n), b;
		input_ar(a);
		newArrayY(a, b);
		if (sizeof(b) > 0) {
			cout << "Массив из чисел, являющихся степенью двойки\n";
			output_ar(b);
		}
		else
			cout << "В массиве a нет подходящих чисел\n";
	}
	else
		cout << "n<0"<< "\n";
	return 0;
}