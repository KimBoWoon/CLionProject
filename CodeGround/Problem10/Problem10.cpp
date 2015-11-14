//
// Created by bw on 15. 11. 14.
//

#pragma warning(disable:4996)

#include <cstdio>
#include <iostream>
#include <string.h>

using namespace std;

#define MAXCOST 10001

int loadsize[1001][1001];

int main() {
    freopen("input.txt", "r", stdin);
    setbuf(stdout, NULL);

    int T;
    int test_case;

    scanf("%d", &T);
    for (test_case = 1; test_case <= T; ++test_case) {
        int collegesize, roadsize;
        cin >> collegesize >> roadsize;
        int *collegearray = new int[collegesize + 1];
        memset(collegearray, 0, sizeof(int) * (collegesize + 1));

        for (int i = 0; i <= collegesize; i++) {
            for (int j = 0; j <= collegesize; j++) {
                if (i == j) loadsize[i][j] = 0;
                else loadsize[i][j] = MAXCOST;
            }
        }
        int cola, colb, cost;
        for (int i = 0; i < roadsize; i++) {
            cin >> cola >> colb >> cost;
            loadsize[cola][colb] = cost;
            loadsize[colb][cola] = cost;
        }
        int **visitsize = new int *[collegesize + 1];
        for (int i = 0; i <= collegesize; i++) {
            visitsize[i] = new int[collegesize + 1];
            memset(visitsize[i], 0, sizeof(int) * (collegesize + 1));
        }
        for (int i = 1; i <= collegesize; i++) {
            for (int j = 1; j <= collegesize; j++) {
                if (loadsize[i][j] != 0 && loadsize[i][j] != MAXCOST) {
                    int k = 1;
                    while (k <= collegesize) {
                        if (loadsize[j][k] != 0 && loadsize[j][k] < MAXCOST) {
                            if (loadsize[i][k] > loadsize[i][j] + loadsize[j][k]) {
                                loadsize[i][k] = loadsize[i][j] + loadsize[j][k];
                                loadsize[k][i] = loadsize[i][k];

                                visitsize[i][k] = j;
                                visitsize[k][i] = j;
                            }
                        }
                        k++;
                    }
                }
            }
        }
        /*for (int i = 1; i <= collegesize; i++)
        {
         for (int j = 1; j <= collegesize; j++)
         {
          if (loadsize[i][j] >0 && loadsize[i][j]!=MAXCOST)
           cout << "loadsize[" << i << "][" << j << "] : " << loadsize[i][j] << " "<<visitsize[i][j]<<endl;
         }
        }*/

        printf("Case #%d\n", test_case);
        int count = 0;
        for (int i = 1; i <= collegesize; i++) {
            for (int j = 1; j <= collegesize; j++) {
                collegearray[visitsize[i][j]]++;
            }
        }
        for (int i = 1; i <= collegesize; i++) {
            if (collegearray[i] == 0) count++;
        }
        cout << count << " ";
        for (int i = 1; i <= collegesize; i++) {
            if (collegearray[i] == 0) cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}