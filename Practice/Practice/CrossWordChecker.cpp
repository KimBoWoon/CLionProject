//
// Created by bw on 15. 11. 27.
//

#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
#include <functional>
#include <fstream>

#pragma warning(disable:4996)

using namespace std;

#define MAX_SIZE 50

// �ؽ� ü�ο� �ʿ��� ���
class Node {
private:
    string s;
    Node *nextNode;
public:
    Node(string s = "", Node *nextNode = NULL) : s(s) { }
	// �浹�� ���� ��� �ؽ� ü�� ����
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
	// ���� ��带 ������
    Node *getNode() {
        return nextNode;
    }
	// ���� ����� �����͸� ������
    string getData() {
        return s;
    }
	// ���� �ؽ� ü���� ��� �����͸� �����
    void printData() {
        Node *cur = nextNode;
        while (cur != NULL) {
            cout << cur->s << " ";
            cur = cur->nextNode;
        }
        cout << endl;
    }
};
// input���ϰ� user��� ������ �о���� �Լ�
void dataInput(int row, int col);
// ���� �ܾ� �̾Ƴ���
void acrossWord(int across, int col);
// ���� �ܾ� �̾Ƴ���
void downWord(int down, int row);
// �ܾ� ��Ī Ȯ��
bool matchingWord(string word, string inputWord);

char userAnswer[MAX_SIZE][MAX_SIZE];// user ���
char inputData[MAX_SIZE][MAX_SIZE];// input ������
// ����
vector<string> dictionary = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R",
                             "S", "T", "U", "V", "W", "X", "Y", "Z", "RIBS", "RULE", "DRUG", "SERUM", "INDECT",
                             "HOSPITAL", "SURGEON", "ANTIBIOTIC", "SCROLL", "STITCH", "NURSE", "AIDS"};
// �ؽ� ü�ο� �ʿ��� vector
vector<Node *> vec(26);
// �Է� ���ϵ�
// �Ű������� �Ѱ��ֱ� ������
ifstream input("checker.txt");
ifstream answer("userinput.txt");

int main() {
    int testCase;

    //freopen("userinput.txt", "r", stdin);

	input >> testCase;

    while (testCase--) {
        int row, col, across, down;

		memset(userAnswer, 0, sizeof(char) * MAX_SIZE * MAX_SIZE);
		memset(inputData, 0, sizeof(char) * MAX_SIZE * MAX_SIZE);
		
		// �ؽ� ü�� �ʱ�ȭ
        for (int i = 0; i < 26; i++)
            vec[i] = new Node;

		// ������ �ؽ�
        for (size_t i = 0; i < dictionary.size(); i++) {
            int ascii = dictionary[i][0] - 65;
            Node *node = new Node(dictionary[i]);

            vec[ascii]->setNextNode(node);
        }

		// ������
        for (int i = 0; i < 26; i++) {
            vec[i]->printData();
        }

		input >> row >> col;
		dataInput(row, col);
		input >> across >> down;

        acrossWord(across, col);
        cout << "-------------------------" << endl;
        downWord(down, row);
    }
}

void dataInput(int row, int col) {
	// input ���� ������
	for (int x = 0; x < row; x++) {
		for (int y = 0; y < col; y++)
			input >> inputData[x][y];
	}
	// user ��� ������
	for (int x = 0; x < row; x++) {
		for (int y = 0; y < col; y++)
			answer >> userAnswer[x][y];
	}
}
// ���� �ܾ�
void acrossWord(int across, int col) {
    for (int x = 0; x < across; x++) {
        int i, j;
        string str = "", temp = "";
		input >> i >> j;

		// user ����� �ܾ �̾ƿ�
		// input ������ �ܾ �̾ƿ�
		// �ܾ ����� ��Ī�Ǵ��� Ȯ���ϱ� ����
        for (int index = 0; ; index++) {
            if (j - 1 + index < col) {
				if (userAnswer[i - 1][j - 1 + index] != '*') {
					str += userAnswer[i - 1][j - 1 + index];
					temp += inputData[i - 1][j - 1 + index];
				}
                else
                    break;
            }
            else
                break;
        }
		// ��Ī TRUE ��Ī �ȵ� FALSE
        if (matchingWord(str, temp))
            cout << "TRUE" << endl;
        else
            cout << "FALSE" << endl;

        //cout << str << endl;
    }
}
// ���� �ܾ�
void downWord(int down, int row) {
    for (int x = 0; x < down; x++) {
        int i, j;
        string str = "", temp = "";
		input >> i >> j;

		// user ����� �ܾ �̾ƿ�
		// input ������ �ܾ �̾ƿ�
		// �ܾ ����� ��Ī�Ǵ��� Ȯ���ϱ� ����
        for (int index = 0; ; index++) {
            if (i - 1 + index < row) {
				if (userAnswer[i - 1 + index][j - 1] != '*') {
					str += userAnswer[i - 1 + index][j - 1];
					temp += inputData[i - 1 + index][j - 1];
				}
                else
                    break;
            }
            else
                break;
        }
		// ��Ī TRUE ��Ī �ȵ� FALSE
        if (matchingWord(str, temp))
            cout << "TRUE" << endl;
        else
            cout << "FALSE" << endl;

        //cout << str << endl;
    }
}
// �ܾ� ��Ī Ȯ��
bool matchingWord(string word, string inputWord) {
	size_t index = 0;
    Node *cur = vec[word[0] - 65]->getNode();
	string s;

    while (cur != NULL) {
		// ���� �� ������
		while (cur->getData().size() != inputWord.size()) {
			if (cur->getNode() == NULL)
				return false;
			cur = cur->getNode();
		}
		// s = ���� ������
		s = cur->getData();
		// �ϴ� input�� ���ؼ� �ܾ ����� ����ߴ��� Ȯ��
        for (index = 0; index < word.size(); index++) {
			if (inputWord[index] == '_')
                continue;
			else if (inputWord[index] != s[index]) {
                break;
            }
        }
        // �ܾ ����� ��������� user�� �Է��� ���� ���� �����͸� ��
		// �Ѵ� ������ true ��ȯ �ƴϸ� ������ �ݺ�
		if (word.compare(s) == 0 && index == word.size())
			return true;

        cur = cur->getNode();
    }
    return false;
}