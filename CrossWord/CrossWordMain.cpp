#pragma warning(disable:4996)

#include "Word.h"

#define MAX_SIZE 50

vector<string> dictionary;

char board[MAX_SIZE][MAX_SIZE];

bool sizeComp(const string x, const string y) {
    return x.size() < y.size();
}

void inputBoard(char board[][MAX_SIZE], int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++)
            cin >> board[i][j];
    }
}

string selectWord(string str) {
    for (int i = 0; i < dictionary.size(); i++) {
        bool flag = true;
        for (int j = 0; j < dictionary[i].size(); j++) {
            if (str[j] == '_')
                continue;
            if (dictionary[i][j] != str[j]) {
                flag = false;
                break;
            }
        }
        if (flag && str.size() == dictionary[i].size())
            return dictionary[i];
    }
    return "asdf";
}

void acrossWord(int across, int col) {
    for (int i = 0; i < across; i++) {
        int x, y;
        string str = "";
        cin >> x >> y;

        for (int index = 0; ; index++) {
            if (y - 1 + index < col) {
                if (board[x - 1][y - 1 + index] != '*')
                    str += board[x - 1][y - 1 + index];
                else
                    break;
            }
            else
                break;
        }
        string s = selectWord(str);
        cout << s << endl;

//        for (int t = 0; t < s.size(); t++)
//            board[x][y + t] = s[t];
    }
}

void downWord(int down, int row) {
    for (int i = 0; i < down; i++) {
        int x, y;
        string str = "";
        cin >> x >> y;

        for (int index = 0; ; index++) {
            if (x - 1 + index < row) {
                if (board[x - 1 + index][y - 1] != '*')
                    str += board[x - 1 + index][y - 1];
                else
                    break;
            }
            else
                break;
        }
        string s = selectWord(str);
        cout << s << endl;

//        for (int t = 0; t < s.size(); t++)
//            board[x + t][y] = s[t];
    }
}

void printBorad(char board[][MAX_SIZE], int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++)
            cout << board[i][j];
        cout << endl;
    }
}

int main() {
    int dictionarySize, testCase, size = 0;
    freopen("input.txt", "r", stdin);

    cin >> dictionarySize;

    for (int i = 0; i < dictionarySize; i++) {
        string str;
        cin >> str;
        dictionary.push_back(str);
    }

    sort(dictionary.begin(), dictionary.end(), sizeComp);

    cin >> testCase;

    while (testCase--) {
        int row, col, across, down;

        memset(board, 0, sizeof(char) * MAX_SIZE * MAX_SIZE);

        cin >> row >> col;

        inputBoard(board, row, col);

        cin >> across >> down;

        acrossWord(across, col);
        downWord(down, row);

        printBorad(board, row, col);
    }
}