#include <iostream>
#include <string>
#include <string.h>
#include <cstdio>
#include <cstdlib>

using namespace std;

string encoding();

string decoding();

int main() {
    int testCase;

    freopen("input.txt", "r", stdin);

    cin >> testCase;

    while (testCase--) {
        int mode;

        cin >> mode;

        if (mode == 1)
            cout << encoding() << endl;
        else
            cout << decoding() << endl;
    }
}

string encoding() {
    char c, temp[10];
    int cnt = 1;
    string result = "";
    string str;

    cin >> str;
    c = str[0];

    for (int i = 1; i < str.size(); i++) {
        if (c == str[i]) {
            cnt++;
            if (cnt > 255 && str[i + 1] == c) {
                sprintf(temp, "%d%c", 0, c);
                result += temp;
                cnt = 1;
            }
        }
        else {
            sprintf(temp, "%d%c", cnt, c);
            result += temp;
            c = str[i];
            cnt = 1;
        }
    }
    sprintf(temp, "%d%c", cnt, c);
    result += temp;
    return result;
}

string decoding() {
    string str, result = "";
    char number[3] = {0};
    int n, cnt = 0;

    cin >> str;

    for (int i = 0; i < str.size(); i++) {
        if (str[i] >= '0' && str[i] <= '9')
            number[cnt++] += str[i];
        else {
            if (number[0] == '0')
                n = 256;
            else
                n = atoi(number);
            for (int x = 0; x < n; x++)
                result += str[i];
            cnt = 0;
            memset(number, 0, sizeof(char) * 3);
        }
    }
    return result;
}