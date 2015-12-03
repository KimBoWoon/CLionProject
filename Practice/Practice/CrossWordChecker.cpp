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

// 특정 단어장
class Word {
private:
    vector<string> s;
public:
    void addWord(string s) {
        this->s.push_back(s);
    }

    vector<string> getWordVector() {
        return s;
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

char userAnswer[MAX_SIZE][MAX_SIZE];
// user 답안
char inputData[MAX_SIZE][MAX_SIZE];
// input 데이터
// 단어마다 시작 주소를 가지고 있음
vector<Word *> vec(26);

// 매개변수로 넘겨주기 귀찮음
// input 파일
ifstream input("input.txt");
// user 답안
ifstream answer("output.txt");
// 테스트 케이스, 틀린 갯수, 전체 단어 갯수, 틀린 테스트 케이스
int t, wrongCnt = 0, wordCnt = 0, wrongTestCase = 0;
// 접답 비율 계산
double rate = 0;
bool flag1 = true;

int main() {
    int testCase, totalWordCnt = 0;

    input >> totalWordCnt;

    for (int i = 0; i < 26; i++)
        vec[i] = new Word;

    for (size_t i = 0; i < totalWordCnt - 2; i++) {
        string temp;
        input >> temp;
        int ascii = temp[0] - 65;
        vec[ascii]->addWord(temp);
    }

    input >> testCase;

    for (t = 0; t < testCase; t++) {
        int row, col, across, down;

        memset(userAnswer, 0, sizeof(char) * MAX_SIZE * MAX_SIZE);
        memset(inputData, 0, sizeof(char) * MAX_SIZE * MAX_SIZE);

        input >> row >> col;
        dataInput(row, col);
        input >> across >> down;
        wordCnt += across + down;

        acrossWord(across, col);
        downWord(down, row);

        if (!flag1) {
            wrongCnt++;
            flag1 = true;
        }
    }

    rate = ((double) wrongCnt / (double) testCase) * 100;
    cout << 100 - (int) rate << " " << wrongTestCase << endl;

    input.close();
    answer.close();
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
        bool flag = true;
        string str = "", temp = "";
        input >> i >> j;

        // user 답안의 단어를 뽑아옴
        // input 파일의 단어도 뽑아옴
        // 단어가 제대로 매칭되는지 확인하기 위함
        for (int index = 0; ; index++) {
            if (j - 1 + index < col) {
                if (userAnswer[i - 1][j - 1 + index] != '*') {
                    if (!(userAnswer[i - 1][j - 1 + index] >= 'A' && userAnswer[i - 1][j - 1 + index] <= 'Z')) {
                        wrongCnt++;
                        wrongTestCase = t + 1;
                        flag = false;
                        break;
                    }
                    str += userAnswer[i - 1][j - 1 + index];
                    temp += inputData[i - 1][j - 1 + index];
                }
                else
                    break;
            }
            else
                break;
        }
        if (flag && !matchingWord(str, temp)) {
            flag1 = false;
            wrongTestCase = t + 1;
        }
    }
}

// 세로 단어
void downWord(int down, int row) {
    for (int x = 0; x < down; x++) {
        int i, j;
        bool flag = true;
        string str = "", temp = "";
        input >> i >> j;

        // user 답안의 단어를 뽑아옴
        // input 파일의 단어도 뽑아옴
        // 단어가 제대로 매칭되는지 확인하기 위함
        for (int index = 0; ; index++) {
            if (i - 1 + index < row) {
                if (userAnswer[i - 1 + index][j - 1] != '*') {
                    if (!(userAnswer[i - 1 + index][j - 1] >= 'A' && userAnswer[i - 1 + index][j - 1] <= 'Z')) {
                        wrongCnt++;
                        wrongTestCase = t + 1;
                        flag = false;
                        break;
                    }
                    str += userAnswer[i - 1 + index][j - 1];
                    temp += inputData[i - 1 + index][j - 1];
                }
                else
                    break;
            }
            else
                break;
        }
        if (flag && !matchingWord(str, temp)) {
            flag1 = false;
            wrongTestCase = t + 1;
        }
    }
}

// 단어 매칭 확인
bool matchingWord(string word, string inputWord) {
    vector<string> arr = vec[word[0] - 65]->getWordVector();
    size_t start = 0, end = arr.size() - 1, index;

    // 단어가 제대로 사용됐는지 확인
    for (index = 0; index < inputWord.size(); index++) {
        if (inputWord[index] == '_')
            continue;
        else if (inputWord[index] != word[index])
            return false;
    }

    if (index != inputWord.size())
        return false;

    // 이진탐색으로 사전에 단어가 있는지 검색
    while (start <= end) {
        size_t mid = (start + end) / 2;

        if (arr[mid] == word)
            return true;
        else {
            if (arr[mid] < word)
                start = mid + 1;
            else if (arr[mid] > word)
                end = mid - 1;
        }
    }
    return false;
}