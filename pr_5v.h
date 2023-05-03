#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

struct Cinema {
    string name;
    string movie;
    string date;
    string time;
    double price;
};

vector<Cinema> cinemas;

// Заполнение записи по сеансу с клавиатуры
void addCinema() {
    Cinema cinema;
    cout << "Введите название кинотеатра: ";
    cin >> cinema.name;
    cout << "Введите название фильма: ";
    cin >> cinema.movie;
    cout << "Введите дату: ";
    cin >> cinema.date;
    cout << "Введите время начала: ";
    cin >> cinema.time;
    cout << "Введите стоимость билета: ";
    cin >> cinema.price;
    cinemas.push_back(cinema);
    cin.ignore(); // чтобы очистить буфер ввода перед следующим вызовом getline
}

// Вставить запись по сеансу в таблицу
void insertCinema() {
    Cinema cinema;
    cout << "Введите название кинотеатра: ";
    cin >> cinema.name;
    cout << "Введите название фильма: ";
    cin >> cinema.movie;
    cout << "Введите дату: ";
    cin >> cinema.date;
    cout << "Введите время начала: ";
    cin >> cinema.time;
    cout << "Введите стоимость билета: ";
    cin >> cinema.price;
    
    int index = 0;
    bool found = false;
    for (size_t i = 0; i < cinemas.size(); i++) {
        if (cinemas[i].name == cinema.name) {
            index = i;
            found = true;
            break;
        }
    }
    if (found) {
        while (index < cinemas.size() && cinemas[index].name == cinema.name) {
            index++;
        }
        cinemas.insert(cinemas.begin() + index, cinema);
    } else {
        cinemas.push_back(cinema);
    }
}

void printCinemas() {
    cout << setw(30) << left << "Cinema" << setw(30) << left << "Movie" << setw(12) << left << "Data" << setw(12) << left << "Time" << setw(10) << left << "Price" << endl;
    for (size_t i = 0; i < cinemas.size(); i++) {
        cout << setw(30) << left << cinemas[i].name << setw(30) << left << cinemas[i].movie << setw(12) << left << cinemas[i].date << setw(12) << left << cinemas[i].time << setw(10) << left << cinemas[i].price << endl;
    }
}


// Удалить записи по заданной дате
void deleteCinema() {
    string date;
    cout << "Введите дату: ";
    cin >> date;
    for (size_t i = 0; i < cinemas.size(); i++) {
        if (cinemas[i].date == date) {
            cinemas.erase(cinemas.begin() + i);
            i--;
        }
    }
}

// Вывести список кинотеатров, в которых можно посмотреть заданный фильм
void searchMovie() {
    string movie;
    cout << "Введите название фильма: ";
    cin >> movie;
    vector<string> cinemasWithMovie;
    for (size_t i = 0; i < cinemas.size(); i++) {
        if (cinemas[i].movie == movie) {
            bool found = false;
            for (size_t j = 0; j < cinemasWithMovie.size(); j++) {
                if (cinemas[i].name == cinemasWithMovie[j]) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                cinemasWithMovie.push_back(cinemas[i].name);
            }
        }
    }
    if (cinemasWithMovie.size() > 0) {
        cout << "Кинотеатры, в которых можно посмотреть фильм " << movie << ":" << endl;
            for (size_t i = 0; i < cinemasWithMovie.size(); i++) {
        cout << cinemasWithMovie[i] << endl;
    }
    } else {
        cout << "Нет кинотеатров, в которых можно посмотреть фильм " << movie << "." << endl;
    }
}

