//#include <iostream>
//#include <climits>
//
//using namespace std;
//
//int M;
//int mArr[100005][2];
//
//void qsf(int start, int end) {
//    int pivotPoint = mArr[(start + end) / 2][0];
//    int f = start;
//    int e = end;
//
//    while (f <= e) {
//        while (pivotPoint > mArr[f][0]) f++;
//        while (pivotPoint < mArr[e][0]) e--;
//
//        if (f <= e) {
//            swap(mArr[f][0], mArr[e][0]);
//            swap(mArr[f][1], mArr[e][1]);
//            f++;
//            e--;
//        }
//    }
//
//    if (start < e) qsf(start, e);
//    if (f < end) qsf(f, end);
//}
//
//void qss(int start, int end, bool direc) {
//    int pivotPoint = mArr[(start + end) / 2][1];
//    int f = start;
//    int e = end;
//
//    while (f <= e) {
//        if (direc) {
//            while (pivotPoint > mArr[f][1]) f++;
//            while (pivotPoint < mArr[e][1]) e--;
//        }
//        else {
//            while (pivotPoint < mArr[f][1]) f++;
//            while (pivotPoint > mArr[e][1]) e--;
//        }
//
//        if (f <= e) {
//            swap(mArr[f][1], mArr[e][1]);
//            f++;
//            e--;
//        }
//    }
//
//    if (start < e) qss(start, e, direc);
//    if (f < end) qss(f, end, direc);
//}
//
//int main() {
//    int T;
//
//    freopen("input.txt", "r", stdin);
//
//    scanf("%d", &T);
//
//    while (T--) {
//        scanf("%d", &M);
//
//        for (int i = 0; i < M; i++)
//            scanf("%d %d", &mArr[i][0], &mArr[i][1]);
//
//        qsf(0, M - 1);
//
//        int pprevY = 0;
//        int recentX = 0;
//        int recentY = 0;
//        int sortStartX = 0;
//        int maximum = INT_MIN;
//        int minimum = INT_MAX;
//
//        for (int i = 0; i < M; i++) {
//            if (mArr[i][0] == recentX) {
//                if (maximum < mArr[i][1])
//                    maximum = mArr[i][1];
//                if (minimum > mArr[i][1])
//                    minimum = mArr[i][1];
//            }
//            else {
//                if (pprevY == minimum) {
//                    qss(sortStartX, i - 1, true);
//                    pprevY = maximum;
//                    minimum = maximum = mArr[i][1];
//                }
//                else if (pprevY == maximum) {
//                    qss(sortStartX, i - 1, false);
//                    pprevY = minimum;
//                    maximum = minimum = mArr[i][1];
//                }
//
//                sortStartX = i;
//                recentX = mArr[i][0];
//            }
//        }
//
//        if (pprevY == minimum) {
//            qss(sortStartX, M - 1, true);
//        }
//        else if (pprevY == maximum) {
//            qss(sortStartX, M - 1, false);
//        }
//
//        for (int i = 0; i < M; i++) {
//            cout << mArr[i][0] << " " << mArr[i][1] << endl;
//        }
//
//        int K;
//        int input;
//
//        scanf("%d", &K);
//
//        for (int i = 0; i < K; i++) {
//            scanf("%d", &input);
//            printf("%d %d\n", mArr[input - 1][0], mArr[input - 1][1]);
//        }
//    }
//
//    return 0;
//}
//#include <stdio.h>
//#include <queue>
//#include <vector>
//#include <string.h>
//#include <algorithm>
//#include <iostream>
//
//using namespace std;
//
//vector<int> y_coord[100001];
//int ans[100001][2];
//
//int main() {
//    int tc;
//
//    freopen("input.txt", "r", stdin);
//
//    scanf("%d", &tc);
//
//    while (tc--) {
//        int N, Q, x, y;
//        scanf("%d", &N);
//
//        for (int i = 0; i < N; i++) {
//            scanf("%d %d", &x, &y);
//            y_coord[x].push_back(y);
//        }
//
//        int idx = 0, cur_y = 0;
//        for (int i = 0; i <= 100000 && idx < N; i++) {
//            int size = y_coord[i].size();
//            if (!size)
//                continue;
//
//            sort(y_coord[i].begin(), y_coord[i].end());
//            if (cur_y <= y_coord[i][0]) {
//                for (int j = 0; j < size; j++) {
//                    ans[idx][0] = i;
//                    ans[idx][1] = y_coord[i][j];
//                    idx++;
//                }
//                cur_y = y_coord[i][size - 1];
//            }
//            else {
//                for (int j = size - 1; j >= 0; j--) {
//                    ans[idx][0] = i;
//                    ans[idx][1] = y_coord[i][j];
//                    idx++;
//                }
//                cur_y = y_coord[i][0];
//            }
//            y_coord[i].clear();
//        }
//
//        scanf("%d", &Q);
//        while (Q--) {
//            int q;
//            scanf("%d", &q);
//            printf("%d %d\n", ans[q - 1][0], ans[q - 1][1]);
//        }
//    }
//    return 0;
//}
//#include <iostream>
//#include <cstdlib>
//#include <string.h>
//
//using namespace std;
//
//#define MAXN 100005
//
//int T, N, M;
//
//struct Z {
//    int x, y, o;
//} A[MAXN];
//
//int compXY(const void *x, const void *y) {
//    return ((*(Z *) x).x != (*(Z *) y).x) ?
//           (*(Z *) x).x - (*(Z *) y).x :
//           (*(Z *) x).y - (*(Z *) y).y;
//}
//
//int compN(const void *x, const void *y) {
//    return (*(Z *) x).n - (*(Z *) y).n;
//}
//
//int main() {
//
//    freopen("input.txt", "r", stdin);
//
//    for (scanf("%d", &T); T--;) {
//        scanf("%d", &N);
//        memset(A, 0, sizeof(Z) * MAXN);
//        for (int i = 1; i <= N; i++)
//            scanf("%d%d", &A[i].x, &A[i].y);
//
//        sort(A + 1, A + N + 1, compXY);
//
////        for (int i = 1; i <= N; i++)
////            cout << A[i].x << " " << A[i].y << " " << A[i].o << endl;
////        cout << endl;
//
//        int last_y = 0, o = 1;
//        for (int i = 1; i <= N; i++) {
//            int t = i;
//            for (int j = i + 1; j <= N; j++) {
//                if (A[j].x == A[i].x)
//                    t = j;
//                else
//                    break;
//            }
//            if (A[i].y >= last_y) {
//                for (int j = i; j <= t; j++)
//                    A[j].o = o++;
//                last_y = A[t].y;
//            }
//            else {
//                for (int j = t; j >= i; j--)
//                    A[j].o = o++;
//                last_y = A[i].y;
//            }
//            i = t;
//        }
//
//        sort(A + 1, A + N + 1, compN);
//
////        for (int i = 1; i <= N; i++)
////            cout << A[i].x << " " << A[i].y << " " << A[i].o << endl;
////        cout << endl;
//
//        for (scanf("%d", &M); M--;) {
//            int n;
//            scanf("%d", &n);
//            printf("%d %d\n", A[n].x, A[n].y);
//        }
//    }
//}
#include <iostream>
#include <cstdlib>
#include <string.h>
#include <cstdio>
#include <algorithm>

using namespace std;

#define MAXN 100005

int T, N, M;

struct Z {
    int x, y, o;
} A[MAXN];

int compXY(const void *x, const void *y) {
    return ((*(Z *) x).x != (*(Z *) y).x) ?
           (*(Z *) x).x - (*(Z *) y).x :
           (*(Z *) x).y - (*(Z *) y).y;
}

int compN(const void *x, const void *y) {
    return (*(Z *) x).o - (*(Z *) y).o;
}

int main() {

    freopen("input.txt", "r", stdin);

    for (scanf("%d", &T); T--;) {
        scanf("%d", &N);
        memset(A, 0, sizeof(Z) * MAXN);
        for (int i = 1; i <= N; i++)
            scanf("%d%d", &A[i].x, &A[i].y);

        qsort(A, N + 1, sizeof(Z), compXY);

//        for (int i = 1; i <= N; i++)
//            cout << A[i].x << " " << A[i].y << " " << A[i].o << endl;
//        cout << endl;

        int last_y = 0, o = 1;
        for (int i = 1; i <= N; i++) {
            int t = i;
            for (int j = i + 1; j <= N; j++) {
                if (A[j].x == A[i].x)
                    t = j;
                else
                    break;
            }
            if (A[i].y >= last_y) {
                for (int j = i; j <= t; j++)
                    A[j].o = o++;
                last_y = A[t].y;
            }
            else {
                for (int j = t; j >= i; j--)
                    A[j].o = o++;
                last_y = A[i].y;
            }
            i = t;
        }

        qsort(A, N + 1, sizeof(Z), compN);

//        for (int i = 1; i <= N; i++)
//            cout << A[i].x << " " << A[i].y << " " << A[i].o << endl;
//        cout << endl;

        for (scanf("%d", &M); M--;) {
            int n;
            scanf("%d", &n);
            printf("%d %d\n", A[n].x, A[n].y);
        }
    }
}