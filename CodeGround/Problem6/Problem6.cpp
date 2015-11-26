#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <climits>
#include <string.h>
#include <cmath>

using namespace std;

typedef unsigned long long LLONG;

LLONG arr[100005];

int main() {
    int testCase;
    freopen("input.txt", "r", stdin);

    scanf("%d", &testCase);

    for (int i = 0; i < testCase; i++) {
        int size = 0;
        LLONG d = ULLONG_MAX, cnt = 2;
        scanf("%d", &size);

        memset(arr, 0, sizeof(LLONG) * 100005);

        for (int x = 0; x < size; x++)
            scanf("%lld", &arr[x]);

        for (int x = 0; x < size - 1; x++) {
            if (d > arr[x + 1] - arr[x])
                d = arr[x + 1] - arr[x];
            else if (arr[x + 1] - arr[x] != 0 && d == 0) {
                cnt = 1;
                break;
            }
        }

        int dSqrt = (int) sqrt((double)d);
        for (int x = 2; x <= dSqrt; x++) {
            if (d % x == 0)
                cnt += 2;
        }
        if (dSqrt * dSqrt == d)
            cnt--;
        printf("Case #%d\n%lld\n", i + 1, cnt);
    }
    return 0;
}