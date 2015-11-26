//
// Created by bw on 15. 11. 24.
//

#include <stdio.h>
#include <stdlib.h>

#define SIZE 6
#define VERTEX_COUNT 5
#define INF 999999999

typedef struct edge {
	int start;
	int end;
	int weight;
} Edge;

void dijkstra(int arr[][SIZE], int touch[SIZE], int length[SIZE], Edge selectEdge[VERTEX_COUNT]);

void edgePrint(int start, int length[SIZE]);

int main() {
	int arr[SIZE][SIZE] = {
		0, 0, 0, 0, 0, 0,
		0, INF, 7, 4, 6, 1,
		0, INF, INF, INF, INF, INF,
		0, INF, 2, INF, 5, INF,
		0, INF, 3, INF, INF, INF,
		0, INF, INF, INF, 1, INF
	};
	int touch[SIZE] = { 0 };
	int length[SIZE] = { 0 };
	Edge selectEdge[VERTEX_COUNT] = { 0, 0, 0 };

	dijkstra(arr, touch, length, selectEdge);
	edgePrint(1, length);

	return 0;
}

void dijkstra(int arr[][SIZE], int touch[SIZE], int length[SIZE], Edge selectEdge[VERTEX_COUNT]) {
	int i, selectVertexCnt = 0;

	for (i = 1; i < SIZE; i++) {
		touch[i] = 1;
		length[i] = arr[1][i];
	}

	while (selectVertexCnt < VERTEX_COUNT) {
		int min = 999999999;
		int vnear = 0;

		for (i = 2; i < SIZE; i++) {
			if (length[i] >= 0 && length[i] < min) {
				min = length[i];
				vnear = i;
			}
		}

		selectEdge[selectVertexCnt].start = touch[vnear];
		selectEdge[selectVertexCnt].end = vnear;
		selectEdge[selectVertexCnt].weight = length[vnear];
		selectVertexCnt++;

		for (i = 2; i < SIZE; i++) {
			if (length[vnear] + arr[vnear][i] < length[i]) {
				length[i] = length[vnear] + arr[vnear][i];
				touch[i] = vnear;
			}
		}
		length[vnear] *= -1;
	}
}

void edgePrint(int start, int length[SIZE]) {
	int i;

	printf("Single-Source Shortest Paths\n");
	printf("Dijkstra's Algorithm\n");
	printf("Start Vertex : %d\n", start);
	for (i = 1; i < SIZE; i++)
		printf("%d : %d\n", i, abs(length[i]));
}