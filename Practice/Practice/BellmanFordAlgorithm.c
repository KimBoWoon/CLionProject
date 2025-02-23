//
// Created by bw on 15. 11. 26.
//
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

typedef struct {
	int u, v, w;
} Edge;

int n;
/* the number of nodes */
int e;
/* the number of edges */
Edge edges[1024];
/* large enough for n <= 2^5=32 */
int d[32]; /* d[i] is the minimum distance from node s to node i */

#define INFINITY 10000

void printDist() {
	int i;

	printf("Distances:\n");

	for (i = 0; i < n; ++i)
		printf("to %d\t", i + 1);
	printf("\n");

	for (i = 0; i < n; ++i)
		printf("%d\t", d[i]);

	printf("\n");
}

void bellman_ford(int s) {
	int i, j;

	for (i = 0; i < n; ++i)
		d[i] = INFINITY;

	d[s] = 0;

	for (i = 0; i < n - 1; ++i)
		for (j = 0; j < e; ++j)
			if (d[edges[j].u] + edges[j].w < d[edges[j].v])
				d[edges[j].v] = d[edges[j].u] + edges[j].w;
}

int main(int argc, char *argv[]) {
	int i, j;
	int w;

	FILE *fin = fopen("BellmanFordInput.txt", "r");
	fscanf(fin, "%d", &n);
	e = 0;

	for (i = 0; i < n; ++i)
		for (j = 0; j < n; ++j) {
			fscanf(fin, "%d", &w);
			if (w != 0) {
				edges[e].u = i;
				edges[e].v = j;
				edges[e].w = w;
				++e;
			}
		}
	fclose(fin);

	//    printDist();

	bellman_ford(0);

	printDist();

	return 0;
}