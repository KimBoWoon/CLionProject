//
// Created by bw on 15. 10. 25.
//

#include <iostream>

using namespace std;

int T, N;
int A[501], S[501], D[501][501];

int dy(int s, int e)
{
    if (s >= e)
        return 0;
    if (s + 1 == e)
        return A[s] + A[e];

    int &ret = D[s][e];

    if (ret < 2e9)
        return ret;

    for (int k = s; k < e; k++)
        ret = min(ret, dy(s, k) + dy(k + 1, e) + S[e] - S[s - 1]);

    return ret;
}

int main()
{
    freopen("input.txt", "r", stdin);

    for (scanf("%d", &T); T--;) {
        scanf("%d", &N);
        for (int i = 1; i <= N; i++) {
            scanf("%d", A + i);
            S[i] = S[i - 1] + A[i];
        }
        for (int i = 1; i <= N; i++) {
            for (int j = i; j <= N; j++)
                D[i][j] = (int) 2e9;
        }

        printf("%d\n", dy(1, N));
    }
}