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

void prims(int arr[][SIZE], Edge selectEdge[SIZE]);

void edgePrint(Edge selectEdge[SIZE]);

int main() {
	int arr[SIZE][SIZE] = {
		0, 0, 0, 0, 0, 0,
		0, 0, 1, 3, INF, INF,
		0, 1, 0, 3, 6, INF,
		0, 3, 3, 0, 4, 2,
		0, INF, 6, 4, 0, 5,
		0, INF, INF, 2, 5, 0
	};
	Edge selectEdge[SIZE] = { 0, 0, 0 };

	prims(arr, selectEdge);
	edgePrint(selectEdge);

	return 0;
}

void prims(int arr[][SIZE], Edge selectEdge[SIZE]) {
	int nearest[SIZE];
	int distance[SIZE];
	int i, selectVertexCnt = 0;

	for (i = 2; i <= SIZE; i++) {
		nearest[i] = 1;
		distance[i] = arr[1][i];
	}

	while (selectVertexCnt < SIZE) {
		int min = INF;
		int vnear = 0;

		for (i = 2; i < SIZE; i++) {
			if (distance[i] >= 0 && distance[i] < min) {
				min = distance[i];
				vnear = i;
			}
		}

		selectEdge[vnear].start = nearest[vnear];
		selectEdge[vnear].end = vnear;
		selectEdge[vnear].weight = distance[vnear];
		selectVertexCnt++;
		distance[vnear] *= -1;
		for (i = 2; i < SIZE; i++) {
			if (arr[i][vnear] < distance[i]) {
				distance[i] = arr[i][vnear];
				nearest[i] = vnear;
			}
		}
	}
}

void edgePrint(Edge selectEdge[SIZE]) {
	int i;

	printf("Minimum Spanning Trees\n");
	printf("Prim's Algorithm\n");
	for (i = 1; i < SIZE; i++)
		printf("Start : %d End : %d Weight : %d\n", selectEdge[i].start, selectEdge[i].end, selectEdge[i].weight);
}