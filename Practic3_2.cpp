#include <iostream>
#include "Practic3_2.h"
using namespace std;


int main()
{
	setlocale(0, "");
    cout<<"В программе 1 соответствует крестику, а 0 - нолику"<<endl;
	int n,m;
	cout << "Введите количество сторок и столбцов в поле: ";
	cin >> n >> m;
	typeX x(n,m);
	if (n > 0 && m>0)
	{
		int t;
		input_arr(x);
		cout << "Меню:\nВведите 1, чтобы вывести результат игры;\n" <<"Введите 2, чтобы проверить, победили ли крестики;\n" <<
			"Введите 3, чтобы завершить программу." << endl;
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
				if (Test(x) == true) {
                    cout << "Выигрыш крестиков!" << endl;
                } else {
                    cout << "Крестики проиграли." << endl;
                }
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
