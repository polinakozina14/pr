#include <iostream>


using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    int problem, key, mode;

    int num, order;
    unsigned int mask;
    for (int repeat = 0; repeat < 10; ++repeat) {
        cout << "Номер задания: ";
        cin >> problem;
        switch (problem) {
        case 1: 
            cout <<
                "Выделенное кол-во памяти(в байтах) на разные типы данных:\n"
                "int: " << sizeof(int) << "\n" <<
                "short int: " << sizeof(short int) << "\n" <<
                "long int: " << sizeof(long int) << "\n" <<
                "float: " << sizeof(float) << "\n" <<
                "double: " << sizeof(double) << "\n" <<
                "long double: " << sizeof(long double) << "\n" <<
                "char: " << sizeof(char) << "\n" <<
                "bool: " << sizeof(bool) << "\n";
            break;
        case 2:
            cout << "Введите целое число: ";
            cin >> num;
            cout << "Двоичное представление числа " << num << ":\n";
            order = sizeof(int) * 8 - 1;
            mask = 1 << order;
            for (int i = 0; i <= order; i++) {
                cout << ((num & mask) ? 1 : 0);
                mask >>= 1;
                if (!i || !((i + 1) % 8)) {
                    cout << " ";
                }
            }
            cout << "\n";
            while (true) {
                cout << "\nСдвигаем?\n1 - да\n0 - нет\n";
                cin >> key;
                if (key == 0) {
                    break;
                }
                else if (key != 1) {
                    cout << " 1 или 0 ";
                }
                else {
                    mode = 0;
                    for (int i = 0; i < 32; i++) {
                        mask = 1 << i;
                        if ((mask & num) == 0) {
                            if (mode == 1) {
                                num |= mask;
                                mode = 0;
                            }
                        }
                        else {
                            if (mode == 0) {
                                num ^= mask;
                                mode = 1;
                            }
                        }
                    }
                    mask = 1 << 31;
                    cout << "\n";
                    for (int i = 0; i <= order; i++) {
                        cout << (((num & mask) != 0) ? 1 : 0);
                        mask >>= 1;
                        if (!i || !((i + 1) % 8)) {
                            cout << " ";
                        }
                    }
                    cout << "\n";
                }
            }
            break;
        case 3:
            union {
                int numI;
                float numF;
            };
           
            cout << "Введите вещественное число: ";
            cin >> numF;
            cout << "\nДвоичное представление числа " << numF << ":\n";
   
            order = sizeof(numF) * 8 - 1;
            mask = 1 << order;

            for (int i = 0; i <= order; i++) {
                cout << ((numI & mask) ? 1 : 0);
                mask >>= 1;
                if (!i || i == 7 || i == 8) {
                    cout << " ";
                }
            }
            cout << "\n";
            while (true) {
                cout << "\nСдвигаем?\n1 - да\n0 - нет\n";
                cin >> key;
                if (key == 0) {
                    break;
                }
                else if (key != 1) {
                    cout << " 1 или 0 ";
                }
                else {
                    mode = 0;
                    for (int i = 0; i < 32; i++) {
                        mask = 1 << i;
                        if ((mask & numI) == 0) {
                            if (mode == 1) {
                                numI |= mask;
                                mode = 0;
                            }
                        }
                        else {
                            if (mode == 0) {
                                numI ^= mask;
                                mode = 1;
                            }
                        }
                    }
                    mask = 1 << 31;
                    cout << "\n";
                    for (int i = 0; i <= order; i++) {
                        cout << ((numI & mask) ? 1 : 0);
                        mask >>= 1;
                        if (!i) {
                            cout << " ";
                        }

                    }
                    cout << "\n";
                }
            }
            break;
        case 4:
            union {
                double numD;
                int arr[2];
            };
            cout << "Введите вещественное число с повыщенной точностью: ";

            cin >> numD;
            cout << "\nДвоичное представление числа " << numD << ":\n";
            order = sizeof(numD) * 8 - 1;
            mask = 1 << order;

            for (int i = 0; i <= order / 2; i++) {
                cout << ((arr[1] & mask) ? 1 : 0);
                mask >>= 1;
                if (!i || i == 11) {
                    cout << " ";
                }
            }
            mask = 1 << (order - 1);
            for (int i = 0; i < order / 2; ++i) {
                cout << ((arr[0] & mask) ? 1 : 0);
                mask >>= 1;
            }
            cout << "\n";
            while (true) {
                cout << "\nСдвигаем?\n1 - да\n0 - нет\n";
                cin >> key;
                if (key == 0) {
                    break;
                }
                else if (key != 1) {
                    cout << " 1 или 0 ";
                }
                else {
                    mode = 0;
                    for (int i = 0; i < 32; i++) {
                        mask = 1 << i;
                        if ((mask & arr[1]) == 0) {
                            if (mode == 1) {
                                arr[1] |= mask;
                                mode = 0;
                            }
                        }
                        else {
                            if (mode == 0) {
                                arr[1] ^= mask;
                                mode = 1;
                            }
                        }
                    }
                    for (int i = 0; i < 32; i++) {
                        mask = 1 << i;
                        if ((mask & arr[0]) == 0) {
                            if (mode == 1) {
                                arr[0] |= mask;
                                mode = 0;
                            }
                        }
                        else {
                            if (mode == 0) {
                                arr[0] ^= mask;
                                mode = 1;
                            }
                        }
                    }
                    cout << "\n";
                    mask = 1 << 31;
                    for (int i = 0; i <= 31; i++) {
                        cout << ((arr[1] & mask) ? 1 : 0);
                        mask >>= 1;
                        if (!i || i == 11) {
                            cout << " ";
                        }
                    }

                    mask = 1 << 31;
                    cout << " ";

                    for (int i = 0; i <= 31; i++) {
                        cout << ((arr[0] & mask) ? 1 : 0); 
                        mask >>= 1;
                    }
                    cout << "\n";
                }
            }
            break;
        default:
            cout << "Доступно только 4 задания\n";
            break;
       

        }

    }        
}
