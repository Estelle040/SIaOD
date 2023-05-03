#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main()
{
    setlocale(0, "");
    string sentence1, sentence2;
    cout << "Enter first sentence: ";
    getline(cin, sentence1);
    cout << "Enter second sentence: ";
    getline(cin, sentence2);
    int num;
    string commonWords;
    while (1) {
        cout << "Меню\n";
        cout << "1. Вывести предложения;\n";
        cout << "2. Проверить, есть ли одинаковые слова в предложениях;\n";
        cout << "3. Завершение работы.\n";
        cout << "Выберите операцию и введите ее номер: ";
        bool wordStarted = false; // флаг, указывающий, что начато обработка слова
        string word; // текущее слово
        cin >> num;
        switch (num) {
        case 1:
            cout << "First sentence: ";
            cout << sentence1 << endl;
            cout << "Enter second sentence: ";
            cout << sentence2 << endl;;
            break;
        case 2:
            for (int i = 0; i <= sentence1.size(); i++) {
                if (sentence1[i] != ' ' && sentence1[i] != '\0') { // обрабатываем символы текущего слова
                    word += sentence1[i];
                    wordStarted = true;
                }
                else if (wordStarted) { // закончилось текущее слово
                    if (sentence2.find(word) != sentence2.npos) { // если слово встречается во втором предложении
                        commonWords += word;
                        commonWords += ' ';
                    }
                    wordStarted = false;
                    word = "";
                }
            }
            cout << "Common words: " << commonWords << endl;
            if (commonWords.empty()) {
                cout << "No common words" << endl;
            }
            break;
        case 3:
            return 0;
        }
    }
    return 0;
}
