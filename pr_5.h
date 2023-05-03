#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

struct Session {
    string theaterName; //название кинотеатра
    string movieName; //название фильма
    string date; //дата показа
    string startTime; // время показа
    float ticketPrice; //цена билета
};

void fillSession(Session& sassion);// Функция для заполнения отдельной записи с клавиатуры
void insertSession(Session sassion[], int& numSessions, Session session); // вставить запись о фильме
void deleteSessionByDate(Session sassion[], int& numSessions, string data); // удалить записи по дате показа
void listTheatersForMovie(Session sassion[], int numSessions, string movieName); // вывести кинотеатры, в котороых можно посмотреть определенный фильм
void printSession(Session sassion[], int numSessions); // вывести таблицу





void fillSession(Session& session) {
    cout << "Введите название кинотеатра: ";
    getline(cin, session.theaterName);

    cout << "Введите название фильма: ";
    getline(cin, session.movieName);

    cout << "Введите дату (в формате ДД.ММ.ГГГГ): ";
    getline(cin, session.date);

    cout << "Введите время начала (в формате ЧЧ:ММ): ";
    getline(cin, session.startTime);

    cout << "Введите стоимость билета: ";
    cin >> session.ticketPrice;
 
}



void printSessions(Session sessions[], int numSessions) {
   const int WIDTH = 25; // Ширина столбцов
   cout << left << setw(WIDTH) << "Sinema" << setw(WIDTH) << "Movie" << setw(WIDTH) << "Date" << setw(WIDTH) << "Time" << setw(WIDTH) << "Price" << endl;
   for (int i = 0; i < numSessions; i++) {
       cout << left << setw(WIDTH) << sessions[i].theaterName << setw(WIDTH) << sessions[i].movieName << setw(WIDTH) << sessions[i].date << setw(WIDTH) << sessions[i].startTime << setw(WIDTH) << sessions[i].ticketPrice << endl;
   }
}

void insertSession(Session sessions[], int& numSessions, Session session) {
    int i;
    for (i = 0; i < numSessions; i++) {
        if (sessions[i].theaterName == session.theaterName) {
            break;
        }
    }

    if (i == numSessions) {
        sessions[numSessions++] = session;
    } else {
        for (int j = numSessions - 1; j >= i; j--) {
            sessions[j+1] = sessions[j];
        }
        sessions[i] = session;
        numSessions++;
    }
}

void deleteSessionsByDate(Session sessions[], int& numSessions, string date) {
    int i = 0;
    while (i < numSessions) {
        if (sessions[i].date == date) {
            for (int j = i; j < numSessions - 1; j++) {
                sessions[j] = sessions[j+1];
            }
            numSessions--;
        } else {
            i++;
        }
    }
}

void listTheatersForMovie(Session sessions[], int numSessions, string movieName) {
    cout << "Кинотеатры, в которых можно посмотреть фильм: " <<movieName << endl;
    bool found = false;
    for (int i = 0; i < numSessions; i++) {
        if (sessions[i].movieName == movieName) {
            cout << sessions[i].theaterName << endl;
            found = true;
        }
        }

    if (!found) {
        cout << "Фильм \"" << movieName << "\" не найден в расписании." << endl;
    }
}