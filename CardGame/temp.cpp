//
// Created by bw on 15. 11. 5.
//

#include <bits/stdc++.h>

using namespace std;

int T, N;
int A[1003], S[1003];
int D[1003][1003];

int dy(int s, int e) {
    if (s > e)
        return 0;
    if (s == e)
        return A[s];
    int &ret = D[s][e];
    if (ret >= 0)
        return ret;

    ret = max(S[e] - S[s - 1] - dy(s + 1, e), S[e] - S[s - 1] - dy(s, e - 1));

    return ret;
}

int main() {
    freopen("input.txt", "r", stdin);

    for (scanf("%d", &T); T--;) {
        scanf("%d", &N);
        for (int i = 1; i <= N; i++) {
            scanf("%d", A + i);
            S[i] = S[i - 1] + A[i];
        }

        for (int i = 1; i <= N; i++) {
            for (int j = i; j <= N; j++)
                D[i][j] = -1;
        }

        printf("%d\n", dy(1, N));
        for (int x = 0; x <= N; x++) {
            for (int y = 0; y <= N; y++)
                printf("%d ", D[x][y]);
            printf("\n");
        }
    }
}