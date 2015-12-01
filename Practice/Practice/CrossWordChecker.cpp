//
// Created by bw on 15. 11. 27.
//

#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

#define MAX_SIZE 50

class Node {
private:
    string s;
    Node *nextNode;
public:
    Node() { }

    Node(string s, Node *nextNode = NULL) : s(s) { }

    void setNextNode(Node *node) {
        if (nextNode == NULL)
            nextNode = node;
        else {
            Node *n = nextNode;
            while (n->nextNode != NULL) {
                n = n->nextNode;
            }
            n->nextNode = node;
        }
    }

    Node *getNode() {
        return nextNode;
    }

    string getData() {
        return s;
    }

    void printData() {
        Node *cur = nextNode;
        while (cur != NULL) {
            cout << cur->s << " ";
            cur = cur->nextNode;
        }
        cout << endl;
    }
};

void input(int row, int col);

void acrossWord(int across, int col);

void downWord(int down, int row);

bool matchingWord(string word);

char board[MAX_SIZE][MAX_SIZE];
vector<string> dictionary = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R",
                             "S", "T", "U", "V", "W", "X", "Y", "Z", "RIBS", "RULE", "DRUG", "SERUM", "INDECT",
                             "HOSPITAL", "SURGEON", "ANTIBIOTIC", "STITCH", "NURSE"};

vector<Node *> vec(26);

int main() {
    int testCase;

    freopen("userinput.txt", "r", stdin);

    cin >> testCase;

    while (testCase--) {
        int row, col, across, down;

        memset(board, 0, sizeof(char) * MAX_SIZE * MAX_SIZE);

        for (int i = 0; i < 26; i++)
            vec[i] = new Node;

        for (int i = 0; i < dictionary.size(); i++) {
            int ascii = dictionary[i][0] - 65;
            Node *node = new Node(dictionary[i]);

            vec[ascii]->setNextNode(node);
        }

        for (int i = 0; i < 26; i++) {
            vec[i]->printData();
        }

        cin >> row >> col;
        input(row, col);
        cin >> across >> down;

        acrossWord(across, col);
        cout << "-------------------------" << endl;
        downWord(down, row);
    }
}

void input(int row, int col) {
    for (int x = 0; x < row; x++) {
        for (int y = 0; y < col; y++)
            cin >> board[x][y];
    }
}

void acrossWord(int across, int col) {
    for (int x = 0; x < across; x++) {
        int i, j;
        string str = "";
        cin >> i >> j;

        for (int index = 0; ; index++) {
            if (j - 1 + index < col) {
                if (board[i - 1][j - 1 + index] != '*')
                    str += board[i - 1][j - 1 + index];
                else
                    break;
            }
            else
                break;
        }
        if (matchingWord(str))
            cout << "TRUE" << endl;
        else
            cout << "FALSE" << endl;

        //cout << str << endl;
    }
}

void downWord(int down, int row) {
    for (int x = 0; x < down; x++) {
        int i, j;
        string str = "";
        cin >> i >> j;

        for (int index = 0; ; index++) {
            if (i - 1 + index < row) {
                if (board[i - 1 + index][j - 1] != '*')
                    str += board[i - 1 + index][j - 1];
                else
                    break;
            }
            else
                break;
        }
        if (matchingWord(str))
            cout << "TRUE" << endl;
        else
            cout << "FALSE" << endl;

        //cout << str << endl;
    }
}

bool matchingWord(string word) {
    int index = 0;
    Node *cur = vec[word[0] - 65]->getNode();

    while (cur != NULL) {
        string s = cur->getData();
        for (index = 0; index < word.size(); index++) {
            if (word[index] == '_')
                continue;
            else if (word[index] != s[index]) {
                break;
            }
        }
        if (index == word.size())
            return true;
        cur = cur->getNode();
    }
    return false;
}