#include "Word.h"

vector<string> dictionary;
Word *head;
Word *tail;
char board[MAX_SIZE][MAX_SIZE];

int main() {
    int dictionarySize, testCase;
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

        printBoard(board, row, col);

        while (head != NULL) {
            cout << head->getString() << endl;
            head = head->getNext();
        }
    }
}

bool sizeComp(const string x, const string y) {
    return x.size() < y.size();
}

void inputBoard(char board[][MAX_SIZE], int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++)
            cin >> board[i][j];
    }
}

string selectWord(string str, int x, int y, int branch, int index) {
    for (int i = index + 1; i < dictionary.size(); i++) {
        bool flag = true;
        for (int j = 0; j < dictionary[i].size(); j++) {
            if (str[j] == '_')
                continue;
            if (dictionary[i][j] != str[j]) {
                flag = false;
                break;
            }
        }
        if (flag && str.size() == dictionary[i].size()) {
            if (head == NULL) {
                head = new Word(str, dictionary[i], tail, NULL, x, y, i, branch);
                tail = head;
            }
            else if (tail->getNext() == NULL) {
                Word *newNode = new Word(str, dictionary[i], tail, NULL, x, y, i, branch);
                tail->setNext(newNode);
                tail = newNode;
            }
            return dictionary[i];
        }
    }
    return "!";
}

void backtracking() {
    string s = "";
    tail = tail->getTail();
    
    if (tail->getBranch() == ACROSS) {
        s = selectWord(tail->getBasic(), tail->getX(), tail->getY(), tail->getBranch(), tail->getIndex());
        cout << "across " << s << endl;
        if (s == "!")
            backtracking();
        tail->setString(s);
        for (int t = 0; t < s.size(); t++)
            board[tail->getX() - 1][tail->getY() + t - 1] = s[t];
    }
    else if (tail->getBranch() == DOWN) {
        s = selectWord(tail->getBasic(), tail->getX(), tail->getY(), tail->getBranch(), tail->getIndex());
        cout << "down " << s << endl;
        if (s == "!")
            backtracking();
        tail->setString(s);
        for (int t = 0; t < s.size(); t++)
            board[tail->getX() + t - 1][tail->getY() - 1] = s[t];
    }
}

void acrossWord(int across, int col) {
    for (int i = 0; i < across; i++) {
        int x, y;
        string str = "", s = "";
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
        s = selectWord(str, x, y, ACROSS);
//        cout << s << endl;

        if (s == "!")
            backtracking();

        for (int t = 0; t < s.size(); t++)
            board[x - 1][y + t - 1] = s[t];
    }
}

void downWord(int down, int row) {
    for (int i = 0; i < down; i++) {
        int x, y;
        string str = "", s = "";
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
        s = selectWord(str, x, y, DOWN);
//        cout << s << endl;

        if (s == "!")
            backtracking();

        for (int t = 0; t < s.size(); t++)
            board[x + t - 1][y - 1] = s[t];
    }
}

void printBoard(char board[][MAX_SIZE], int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++)
            cout << board[i][j];
        cout << endl;
    }
}