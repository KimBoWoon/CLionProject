//컴퓨터공학부 3학년 20113259 김보운
//알고리즘 과제 - Card Game
#include <iostream>
#include <fstream>
#include <string.h>

#define MAX(x, y) (x > y) ? x : y

using namespace std;

int card[1001];
int sum[1001];
int game[1001][1001];

int main() {
    int testCase;
    ifstream cin("input.txt");

    cin >> testCase;

    while (testCase--) {
        int size;

        cin >> size;

        memset(card, 0, sizeof(int) * 1001);
        memset(sum, 0, sizeof(int) * 1001);
        memset(game, 0, sizeof(int) * 1001 * 1001);

        for (int i = 0; i < size; i++) {
            cin >> card[i];
            sum[i + 1] = sum[i] + card[i];
        }
        for (int i = 1; i <= size; i++)
            game[i][i] = card[i - 1];
        for (int x = 1; x < size; x++) {
            for (int y = 1; y <= size - x; y++) {
                int j = y + x;
                game[y][j] = MAX(sum[j] - sum[y - 1] - game[y + 1][j], sum[j] - sum[y - 1] - game[y][j - 1]);
            }
        }
        cout << game[1][size] << endl;
    }
}