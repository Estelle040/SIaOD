#include "pr_5v.h"


// Главное меню
int main() {
    while (true) {
        cout << "1. Заполнить запись по сеансу с клавиатуры" << endl;
        cout << "2. Вставить запись по сеансу в таблицу" << endl;
        cout << "3. Удалить записи по заданной дате" << endl;
        cout << "4. Вывести список кинотеатров, в которых можно посмотреть заданный фильм" << endl;
        cout << "5. Вывести всю таблицу" << endl;
        cout << "6. Выйти из программы" << endl;
        
        int choice;
        cout << "Выберите действие: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                addCinema();
                break;
            case 2:
                insertCinema();
                break;
            case 3:
                deleteCinema();
                break;
            case 4:
                searchMovie();
                break;
            case 5:
                printCinemas();
                break;
            case 6:
                return 0;
            default:
                cout << "Некорректный ввод. Попробуйте снова." << endl;
        }
    }
}
