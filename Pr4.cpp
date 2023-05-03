#include <iostream>
#include <string.h>

using namespace std;

void splitString(char *str, char **words, int &n) {
    char *p = strtok(str, " ");
    while (p != nullptr) {
        words[n++] = p;
        p = strtok(nullptr, " ");
    }
}

int main()
{
	setlocale(0, "");  
    char sentence1[100], sentence2[100];
    cout << "Enter first sentence: ";
    cin.getline(sentence1, 100);
    cout << "Enter second sentence: ";
    cin.getline(sentence2, 100);
    int num; 
    char *words1[100], *words2[100], *commonWords[100];
    int n1 = 0, n2 = 0, nCommon = 0;
		while (1) {
            cout << "Меню\n";
            cout << "1. Вывести предложения;\n";
            cout << "2. Проверить, есть ли одинаковые слова в предложениях;\n";
            cout << "3. Завершение работы.\n";
            cout << "Выберите операцию и введите ее номер: ";
            cin >> num;
            switch (num) {
            case 1:
                cout << "First sentence: ";
                cout<<sentence1<<endl;
                cout << "Enter second sentence: ";
                cout<<sentence2<<endl;;
                break;
            case 2:
                splitString(sentence1, words1, n1);
                splitString(sentence2, words2, n2);

                for (int i = 0; i < n2; i++) {
                    bool found = false;
                    for (int j = 0; j < n1; j++) {
                        if (strcmp(words2[i], words1[j]) == 0) {
                            found = true;
                            break;
                        }
                    }
                    if (found) {
                        commonWords[nCommon++] = words2[i];
                    }
                }           

                if (nCommon == 0) {
                    cout << "There are no common words in the two sentences." << endl;
                } else {
                    cout << "Common words: ";
                    for (int i = 0; i < nCommon; i++) {
                        cout << commonWords[i] << " ";
                    }
                    cout << endl;
                }
                break;
            case 3: 
                return 0;
            }
        }
	
    return 0;
}
