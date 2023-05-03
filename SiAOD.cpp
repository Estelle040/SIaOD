#include <iostream>
#include "ATDststicArray.h"

int main(){
    setlocale(LC_ALL, "rus");
    int n, num;
    typeX a;
    while(1){
        cout<<"Menu\n";
        cout<<"1.Заполнить множество\n";
        cout<<"2.Вывести множество\n";
        cout<<"3.Найти значение в множестве\n";
        cout<<"Выберете операцию и введите её номер: ";
        cin >> num;
        switch (num)
        {
        case 1:
            cout<<"Введите n<" << N <<endl;
            cin >> n;
            if(n<0 || n > n){
                cout<<"Введено n < 0 || n > N" << endl;
                return 0;
            }
            input_array(a,n);
            cout<<a.n<<endl;
            break;
        case 2:
            if (a.n > 0)
                output_array(a);
            else
                cout << "Множество не заплнено\n";
            break;
        case 3:
            if (a.n > 0){
                int key;
                cout << "Введите значение для поиска: ";
                cin >> key;
                int x = search(a, key);
                if (x >= 0)cout << "Индекс найденного значения =" << x << endl;
                else
                    cout << "Значение не найдено  =" <<  endl;
                }
            else
                cout << "Множество не заплнено\n";
            break;
        case 4: exit(1);
    }
}
}