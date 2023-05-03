#include "pr_5.h"
using namespace std;

int main() {
    const int MAX_SESSIONS = 100;
    Session sessions[MAX_SESSIONS];
    int numSessions = 0;

    while (true) {
        cout << "Выберите операцию:" << endl;
        cout << "1. Заполнение записи по сеансу с клавиатуры" << endl;
        cout << "2. Вставить запись по сеансу в таблицу" << endl;
        cout << "3. Удалить записи по заданной дате" << endl;
        cout << "4. Вывести список кинотеатров, в которых можно посмотреть заданный фильм" << endl;
        cout << "5. Вывести таблицу" << endl;
        cout << "6. Выйти" << endl;
        cout << "Выберите номер операции: ";
        int choice;
        cin >> choice;
        cin.ignore(); // чтобы очистить буфер ввода перед следующим вызовом getline
        Session session;
        Session session2;
        string date;
        string movieName;
        switch (choice) {
            case 1:
                fillSession(session);
                sessions[numSessions++] = session;
                break;
            case 2:
                fillSession(session2);
                insertSession(sessions, numSessions, session2);
                break;
            case 3:
                cout << "Введите дату (в формате ДД.ММ.ГГГГ): ";
                getline(cin, date);
                deleteSessionsByDate(sessions, numSessions, date);
                break;
            case 4:
                cout << "Введите название фильма: ";
                getline(cin, movieName);
                listTheatersForMovie(sessions, numSessions, movieName);
                break;
            case 5:
                printSessions(sessions, numSessions);
                break;
            case 6:
                cout << "До свидания!" << endl;
                return 0;
            default:
                cout << "Неверный номер операции. Попробуйте еще раз." << endl;
        }
    }
}
