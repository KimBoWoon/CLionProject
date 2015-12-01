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

// 해쉬 체인에 필요한 노드
class Node {
private:
    string s;
    Node *nextNode;
public:
    Node(string s = "", Node *nextNode = NULL) : s(s) { }
	// 충돌이 생길 경우 해쉬 체인 생성
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
	// 다음 노드를 가져옴
    Node *getNode() {
        return nextNode;
    }
	// 현재 노드의 데이터를 가져옴
    string getData() {
        return s;
    }
	// 현재 해쉬 체인의 모든 데이터를 출력함
    void printData() {
        Node *cur = nextNode;
        while (cur != NULL) {
            cout << cur->s << " ";
            cur = cur->nextNode;
        }
        cout << endl;
    }
};
// input파일과 user답안 파일을 읽어오는 함수
void dataInput(int row, int col);
// 가로 단어 뽑아내기
void acrossWord(int across, int col);
// 세로 단어 뽑아내기
void downWord(int down, int row);
// 단어 매칭 확인
bool matchingWord(string word, string inputWord);

char userAnswer[MAX_SIZE][MAX_SIZE];// user 답안
char inputData[MAX_SIZE][MAX_SIZE];// input 데이터
// 사전
vector<string> dictionary = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R",
                             "S", "T", "U", "V", "W", "X", "Y", "Z", "RIBS", "RULE", "DRUG", "SERUM", "INDECT",
                             "HOSPITAL", "SURGEON", "ANTIBIOTIC", "SCROLL", "STITCH", "NURSE", "AIDS"};
// 해쉬 체인에 필요한 vector
vector<Node *> vec(26);
// 입력 파일들
// 매개변수로 넘겨주기 귀찮음
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
		
		// 해쉬 체인 초기화
        for (int i = 0; i < 26; i++)
            vec[i] = new Node;

		// 사전을 해쉬
        for (size_t i = 0; i < dictionary.size(); i++) {
            int ascii = dictionary[i][0] - 65;
            Node *node = new Node(dictionary[i]);

            vec[ascii]->setNextNode(node);
        }

		// 디버깅용
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
	// input 파일 데이터
	for (int x = 0; x < row; x++) {
		for (int y = 0; y < col; y++)
			input >> inputData[x][y];
	}
	// user 답안 데이터
	for (int x = 0; x < row; x++) {
		for (int y = 0; y < col; y++)
			answer >> userAnswer[x][y];
	}
}
// 가로 단어
void acrossWord(int across, int col) {
    for (int x = 0; x < across; x++) {
        int i, j;
        string str = "", temp = "";
		input >> i >> j;

		// user 답안의 단어를 뽑아옴
		// input 파일의 단어도 뽑아옴
		// 단어가 제대로 매칭되는지 확인하기 위함
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
		// 매칭 TRUE 매칭 안됨 FALSE
        if (matchingWord(str, temp))
            cout << "TRUE" << endl;
        else
            cout << "FALSE" << endl;

        //cout << str << endl;
    }
}
// 세로 단어
void downWord(int down, int row) {
    for (int x = 0; x < down; x++) {
        int i, j;
        string str = "", temp = "";
		input >> i >> j;

		// user 답안의 단어를 뽑아옴
		// input 파일의 단어도 뽑아옴
		// 단어가 제대로 매칭되는지 확인하기 위함
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
		// 매칭 TRUE 매칭 안됨 FALSE
        if (matchingWord(str, temp))
            cout << "TRUE" << endl;
        else
            cout << "FALSE" << endl;

        //cout << str << endl;
    }
}
// 단어 매칭 확인
bool matchingWord(string word, string inputWord) {
	size_t index = 0;
    Node *cur = vec[word[0] - 65]->getNode();
	string s;

    while (cur != NULL) {
		// 글자 수 맞춰줌
		while (cur->getData().size() != inputWord.size()) {
			if (cur->getNode() == NULL)
				return false;
			cur = cur->getNode();
		}
		// s = 사전 데이터
		s = cur->getData();
		// 일단 input과 비교해서 단어를 제대로 사용했는지 확인
        for (index = 0; index < word.size(); index++) {
			if (inputWord[index] == '_')
                continue;
			else if (inputWord[index] != s[index]) {
                break;
            }
        }
        // 단어를 제대로 사용했으면 user가 입력한 값과 사전 데이터를 비교
		// 둘다 맞으면 true 반환 아니면 로직을 반복
		if (word.compare(s) == 0 && index == word.size())
			return true;

        cur = cur->getNode();
    }
    return false;
}