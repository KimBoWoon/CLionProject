//
// Created by bw on 15. 10. 25.
//

/*************************************************************************
* *Problem Palindrome
* 국민대학교 전자정보통신대학 컴퓨터공학부 3 학년 *
* 20113310 이 웅 *
* *
*************************************************************************/
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>

using namespace std;
char strSol[10000] = "";
int cnt = 0;

void con(int n, int base) {
    string str = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ!@?";
    if (n >= base)
        con(n / base, base);
    strSol[cnt++] = str[n % base];
}

bool pal(int start, int end) {
    if (start > end)
        return true;
    else if (strSol[start] == strSol[end])
        return pal(++start, --end);
    else if (strSol[start] != strSol[end])
        return false;
}

int main(void) {
    ifstream in;
    in.open("input.txt");
    int testcases;
    in >> testcases;
    int value;
    for (int i = 0; i < testcases; i++) {
        in >> value;
        for (int j = 2; j <= 64; j++) {
            con(value, j);
            cout << strSol << endl;
            if (pal(0, cnt - 1)) {
                cout << 1 << endl;
                break;
            }
            else if (j == 64) {
                cout << 0 << endl;
                break;
            }
            memset(strSol, 0, sizeof(char) * 10000);
            cnt = 0;
        }
    }
}