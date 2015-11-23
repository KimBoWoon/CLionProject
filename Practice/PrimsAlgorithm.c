//
// Created by bw on 15. 11. 3.
//

#include <stdio.h>

#define SIZE 6
#define INF 999999999

typedef struct edge {
    int start;
    int end;
    int weight;
} Edge;

Edge addEdge(int s, int e, int w);

void prims(int arr[][SIZE]);

int main() {
    int arr[SIZE][SIZE] = {
            0, 0, 0, 0, 0, 0,
            0, 0, 1, 3, INF, INF,
            0, 1, 0, 3, 6, INF,
            0, 3, 3, 0, 4, 2,
            0, INF, 6, 4, 0, 5,
            0, INF, INF, 2, 5, 0
    };

    prims(arr);

    return 0;
}

Edge addEdge(int s, int e, int w) {
    Edge edge = {s, e, w};

    return edge;
}

void prims(int arr[][SIZE]) {
    int nearest[SIZE];
    int distance[SIZE];
    int set[SIZE] = {0, 1};
    Edge e[SIZE] = {0, 0, 0};
    int i;

    for (i = 2; i <= SIZE; i++) {
        nearest[i] = 1;
        distance[i] = arr[1][i];
    }

    while (1) {
        int min = INF;
        int vnear = 0;

        for (i = 1; i < SIZE; i++) {
            if (set[i] == 0)
                break;
        }
        if (i == SIZE)
            break;

        for (i = 2; i < SIZE; i++) {
            if (distance[i] >= 0 && distance[i] < min) {
                min = distance[i];
                vnear = i;
            }
        }

        e[vnear] = addEdge(nearest[vnear], vnear, distance[vnear]);
        set[vnear] = 1;
        distance[vnear] *= -1;
        for (i = 2; i < SIZE; i++) {
            if (arr[i][vnear] < distance[i]) {
                distance[i] = arr[i][vnear];
                nearest[i] = vnear;
            }
        }
    }

    printf("Minimum Spanning Trees\n");
    printf("Prim's Algorithm\n");
    for (i = 1; i < SIZE; i++)
        printf("Start : %d End : %d Weight : %d\n", e[i].start, e[i].end, e[i].weight);
}