#include <iostream>
#include <vector>

using namespace std;

void print_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void print_vector(vector<int>& vec) {
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout << endl;
}

int max_even_index(int arr[], int size) {
    int max_index = -1;
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 == 0 && (max_index == -1 || arr[i] > arr[max_index])) {
            max_index = i;
        }
    }
    return max_index;
}

int max_even_index_v(vector<int>& vec) {
    int max_index = -1;
    for (int i = 0; i < vec.size(); i++) {
        if (vec[i] % 2 == 0 && (max_index == -1 || vec[i] > vec[max_index])) {
            max_index = i;
        }
    }
    return max_index;
}

void insert_after_max(int arr[], int size, int new_elem) {
    int max_index = max_even_index(arr, size);
    if (max_index == -1) {
        return;
    }
    for (int i = size - 1; i > max_index; i--) {
        arr[i] = arr[i - 1];
    }
    arr[max_index + 1] = new_elem;
}

void insert_after_max_d(int*& arr, int& size, int new_elem) {
    int max_index = max_even_index(arr, size);
    if (max_index == -1) {
        cout << "No even elements found" << endl;
        return;
    }
    size++;
    arr = (int*)realloc(arr, size * sizeof(int));
    for (int i = size - 1; i > max_index + 1; i--) {
        arr[i] = arr[i - 1];
    }
    arr[max_index + 1] = new_elem;
}

void insert_after_max_v(vector<int>& vec, int new_elem) {
    int max_index = max_even_index_v(vec);
    if (max_index == -1) {
        return;
    }
    vec.insert(vec.begin() + max_index + 1, new_elem);
}

void remove_before_max(int arr[], int size) {
    int max_index = max_even_index(arr, size);
    if (max_index == -1) {
        return;
    }
    for (int i = max_index - 1; i >= 0; i--) {
        arr[i + 1] = arr[i];
    }
    arr[0] = 0;
}

void remove_before_max_d(int*& arr, int& size) {
    int max_index = max_even_index(arr, size);
    if (max_index == -1) {
        cout << "No even elements found" << endl;
        return;
    }
    if (max_index > 0) {
        for (int i = max_index - 1; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        size--;
        arr = (int*)realloc(arr, size * sizeof(int));
    }
}

void remove_before_max_v(vector<int>& vec) {
    int max_index = max_even_index_v(vec);
    if (max_index == -1) {
        return;
    }
    vec.erase(vec.begin(), vec.begin() + max_index);
}

int main() {
    char choice;
    int size = 0;
    int* arr = nullptr;
    vector<int> vec;
    do {
        cout << "Выберите действие:" << endl;
        cout << "1. Создать статический массив." << endl;
        cout << "2. Создать динамический массив" << endl;
        cout << "3. Создать вектор" << endl;
        cout << "4. Вывести массив" << endl;
        cout << "5. Найти индекс максимального элемента массива, среди четных чисел массива." << endl;
        cout << "6. Вставить новый элемент в массив после элемента с максимальным значением среди черных чисел массива" << endl;
        cout << "7. Удалить элемент массива, расположенный перед элементом, с максимальным значением среди черных чисел массива." << endl;
        cout << "8. Выйти" << endl;
        cin >> choice;
        switch (choice) {
            case '1': {
                if (arr != nullptr) {
                    delete[] arr;
                }
                cout << "Введите размер массива: ";
                            cin >> size;
            arr = new int[size];
            for (int i = 0; i < size; i++) {
                cout << "Введите элемент " << i << ": ";
                cin >> arr[i];
            }
            break;
        }
        case '2': {
            if (arr != nullptr) {
                delete[] arr;
            }
            cout << "Введите размер массива: ";
            cin >> size;
            arr = new int[size];
            int* arr = (int*)malloc(size * sizeof(int));
            for (int i = 0; i < size; i++) {
            cout << "Введите элемент " << i+1 << ": ";
            cin >> arr[i];
            }
            break;
        }
        case '3': {
            vec.clear();
            cout << "Введите размер вектора: ";
            cin >> size;
            for (int i = 0; i < size; i++) {
                int elem;
                cout << "Введите элемент " << i << ": ";
                cin >> elem;
                vec.push_back(elem);
            }
            break;
        }
        case '4': {
              if (arr != NULL) {
                    print_array(arr, size);
                } else if (!vec.empty()) {
                    print_vector(vec);
                } else {
                    cout << "No array/vector created" << endl;
                }
                break;
        }
        case '5': {
            int max_index;
            if (arr != nullptr) {
                max_index = max_even_index(arr, size);
            } else {
                max_index = max_even_index_v(vec);
            }
            if (max_index == -1) {
                cout << "Нет четных элементов" << endl;
            } else {
                cout << "Индекс максимального элемента массива, среди четных чисел массива: " << max_index << endl;
            }
            break;
        }
        case '6': {
            int new_elem;
            cout << "Введите новый элемент: ";
            cin >> new_elem;
            if (arr != nullptr) {
                insert_after_max(arr, size, new_elem);
            } else {
                insert_after_max_v(vec, new_elem);
            }
            break;
        }
        case '7': {
            if (arr != nullptr) {
                remove_before_max(arr, size);
            } else {
                remove_before_max_v(vec);
            }
            break;
        }
        case '8': {
            if (arr != nullptr) {
                delete[] arr;
            }
            return 0;
        }
        default: {
            cout << "Недопустимый выбор, попробуйте ещё раз!" << endl;
        }
    }
    } while (true);
    return 0;
}




// #include <iostream>
// #include <vector>

// using namespace std;

// void print_array(int arr[], int size) {
//     for (int i = 0; i < size; i++) {
//         cout << arr[i] << " ";
//     }
//     cout << endl;
// }

// void print_vector(vector<int>& vec) {
//     for (int i = 0; i < vec.size(); i++) {
//         cout << vec[i] << " ";
//     }
//     cout << endl;
// }

// int max_even_index(int arr[], int size) {
//     int max_index = -1;
//     for (int i = 0; i < size; i++) {
//         if (arr[i] % 2 == 0 && (max_index == -1 || arr[i] > arr[max_index])) {
//             max_index = i;
//         }
//     }
//     return max_index;
// }

// int max_even_index(vector<int>& vec) {
//     int max_index = -1;
//     for (int i = 0; i < vec.size(); i++) {
//         if (vec[i] % 2 == 0 && (max_index == -1 || vec[i] > vec[max_index])) {
//             max_index = i;
//         }
//     }
//     return max_index;
// }

// void insert_after_max(int arr[], int size, int new_elem) {
//     int max_index = max_even_index(arr, size);
//     if (max_index == -1) {
//         return;
//     }
//     for (int i = size - 1; i > max_index; i--) {
//         arr[i] = arr[i - 1];
//     }
//     arr[max_index + 1] = new_elem;
// }

// void insert_after_max(vector<int>& vec, int new_elem) {
//     int max_index = max_even_index(vec);
//     if (max_index == -1) {
//         return;
//     }
//     vec.insert(vec.begin() + max_index + 1, new_elem);
// }

// void remove_before_max(int arr[], int size) {
//     int max_index = max_even_index(arr, size);
//     if (max_index == -1) {
//         return;
//     }
//     for (int i = max_index - 1; i >= 0; i--) {
//         arr[i + 1] = arr[i];
//     }
//     arr[0] = 0;
// }

// void remove_before_max(vector<int>& vec) {
//     int max_index = max_even_index(vec);
//     if (max_index == -1) {
//         return;
//     }
//     vec.erase(vec.begin(), vec.begin() + max_index);
// }

// int main() {
//     char choice;
//     int size = 0;
//     int* arr = nullptr;
//     vector<int> vec;
//     do {
//         cout << "Выберите действие:" << endl;
//         cout << "1. Создать статический массив." << endl;
//         cout << "2. Создать динамический массив" << endl;
//         cout << "3. Создать вектор" << endl;
//         cout << "4. Вывести массив" << endl;
//         cout << "5. Найти индекс максимального элемента массива, среди четных чисел массива." << endl;
//         cout << "6. Вставить новый элемент в массив после элемента с максимальным значением среди черных чисел массива" << endl;
//         cout << "7. Удалить элемент массива, расположенный перед элементом, с максимальным значением среди черных чисел массива." << endl;
//         cout << "8. Выйти" << endl;
//         cin >> choice;
//         switch (choice) {
//             case '1': {
//                 if (arr != nullptr) {
//                     delete[] arr;
//                 }
//                 cout << "Введите размер массива: ";
//                             cin >> size;
//             arr = new int[size];
//             for (int i = 0; i < size; i++) {
//                 cout << "Введите элемент " << i << ": ";
//                 cin >> arr[i];
//             }
//             break;
//         }
//         case '2': {
//             if (arr != nullptr) {
//                 delete[] arr;
//             }
//             cout << "Введите размер массива: ";
//             cin >> size;
//             arr = new int[size];
//             for (int i = 0; i < size; i++) {
//                 cout << "Введите элемент " << i << ": ";
//                 cin >> arr[i];
//             }
//             break;
//         }
//         case '3': {
//             vec.clear();
//             cout << "Введите размер вектора: ";
//             cin >> size;
//             for (int i = 0; i < size; i++) {
//                 int elem;
//                 cout << "Введите элемент " << i << ": ";
//                 cin >> elem;
//                 vec.push_back(elem);
//             }
//             break;
//         }
//         case '4': {
//             if (arr != nullptr) {
//                 print_array(arr, size);
//             } else {
//                 print_vector(vec);
//             }
//             break;
//         }
//         case '5': {
//             int max_index;
//             if (arr != nullptr) {
//                 max_index = max_even_index(arr, size);
//             } else {
//                 max_index = max_even_index(vec);
//             }
//             if (max_index == -1) {
//                 cout << "Нет четных элементов" << endl;
//             } else {
//                 cout << "Индекс максимального элемента массива, среди четных чисел массива: " << max_index << endl;
//             }
//             break;
//         }
//         case '6': {
//             int new_elem;
//             cout << "Введите новый элемент: ";
//             cin >> new_elem;
//             if (arr != nullptr) {
//                 insert_after_max(arr, size, new_elem);
//             } else {
//                 insert_after_max(vec, new_elem);
//             }
//             break;
//         }
//         case '7': {
//             if (arr != nullptr) {
//                 remove_before_max(arr, size);
//             } else {
//                 remove_before_max(vec);
//             }
//             break;
//         }
//         case '8': {
//             if (arr != nullptr) {
//                 delete[] arr;
//             }
//             return 0;
//         }
//         default: {
//             cout << "Недопустимый выбор, попробуйте ещё раз!" << endl;
//         }
//     }
//     } while (true);
//     return 0;
// }



