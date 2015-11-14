//
// Created by bw on 15. 11. 9.
//

#include <iostream>

using namespace std;

int main() {
    int card[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};

    for (int i = 0; i < 10; i++) {
        int s, e;
        cin >> s >> e;
        for (;s < e;s++, e--) {
            int temp = card[s];
            card[s] = card[e];
            card[e] = temp;
        }
    }
    for (int i = 1; i < 21; i++)
        cout << card[i] << " ";
    cout << endl;
}