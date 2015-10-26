//컴퓨터공학부 3학년 20113259
//알고리즘 과제 - MonotoneWalkway
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string.h>

using namespace std;

#define MAX 100001

typedef struct position {
    int x, y, n;
} Position;

int compXY(const void *x, const void *y) {
    return ((*(Position *) x).x != (*(Position *) y).x) ?
           (*(Position *) x).x - (*(Position *) y).x :
           (*(Position *) x).y - (*(Position *) y).y;
}

int compN(const void *x, const void *y) {
    return (*(Position *) x).n - (*(Position *) y).n;
}

Position pos[MAX];

int main() {
    int testCase;
    ifstream in;

    in.open("input.txt");

    in >> testCase;

    while (testCase--) {
        int cafeNum, cnt;

        in >> cafeNum;
        memset(pos, 0, sizeof(Position) * MAX);

        for (int i = 0; i < cafeNum; i++)
            in >> pos[i].x >> pos[i].y;

        qsort(pos, cafeNum, sizeof(Position), compXY);

        int preY = 0, n = 0;
        for (int i = 0; i < cafeNum; i++) {
            int end = i;
            for (int x = i + 1; x <= cafeNum; x++) {
                if (pos[i].x == pos[x].x)
                    end = x;
                else
                    break;
            }
            if (pos[i].y >= preY) {
                for (int x = i + 1; x <= end; x++)
                    pos[x].n = n++;
                preY = pos[end].y;
            }
            else {
                for (int x = end + 1; x >= i; x--)
                    pos[x].n = n++;
                preY = pos[i].y;
            }
            i = end;
        }

        qsort(pos, cafeNum, sizeof(Position), compN);

        in >> cnt;
        for (int i = 0; i < cnt; i++) {
            int cafe;
            in >> cafe;
            cout << pos[cafe - 1].x << " " << pos[cafe - 1].y << endl;
        }
    }
}