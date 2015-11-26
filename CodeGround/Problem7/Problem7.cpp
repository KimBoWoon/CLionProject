//
// Created by bw on 15. 11. 14.
//
#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <string>

using namespace std;

int main() {
    int testCase;
    freopen("input.txt", "r", stdin);

    scanf("%d", &testCase);

    for (int t = 0; t < testCase; t++) {
        int a, b, c;
        string result = "";

        scanf("%d %d %d", &a, &b, &c);

        for (int i = 0; i < c; i++) {
            int n, k;
            scanf("%d %d", &n, &k);


        }

        printf("Case #%d\n%s", t + 1, result);
    }
}