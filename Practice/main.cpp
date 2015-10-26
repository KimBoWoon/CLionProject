#include <iostream>
#include <string.h>
using namespace std;

int fileMatrix[501][501] = {0};

int main() {
    int testCase;

    freopen("input.txt", "r", stdin);

    cin >> testCase;

    while (testCase--) {
        int size;

        cin >> size;


        for (int i = 0; i < size; i++)
            cin >> fileMatrix[0][i];

        memset(fileMatrix, 0, sizeof(int) * 501 * 501);
    }
    return 0;
}