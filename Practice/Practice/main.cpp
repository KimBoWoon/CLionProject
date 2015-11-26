//
// Created by bw on 15. 11. 9.
//

#include <iostream>

using namespace std;

int main() {
    int coin[] = {1, 10, 25, 50, 63, 100};
    int c = 378;
    int size = sizeof(coin) / sizeof(int);
    int result[100] = {0};

    for (int i = 0; c > 0;) {
        if (c - coin[size - 1] >= 0) {
            result[i] = coin[size - 1];
            c -= coin[size - 1];
            i++;
        }
        else if (size - 1 == 0 && c - coin[size - 1] < 0) {
            cout << "Fail" << endl;
            break;
        }
        else
            size--;
    }
    for (int i = 0; result[i] != 0; i++)
        cout << result[i] << " ";
    cout << endl;
}