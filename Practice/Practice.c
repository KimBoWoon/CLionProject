//
// Created by bw on 15. 11. 3.
//

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, ans;
    int min = 2100000000;

    do {
        scanf("%d", &n);

        if (min > abs(10 - n)) {
            ans = n;
            min = abs(10 - n);
        }
    } while (n != 0);

    printf("%d\n", ans);
}