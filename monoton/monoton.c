#include<stdio.h>
#include<stdlib.h>

typedef struct Point {
    int x;
    int y;
} Point;

typedef struct CafeInfo {
    int x;
    int y;
    int number;
} CafeInfo;

int ySumSearch(Point *point, int i);

void monotoneWalkway(CafeInfo *cafe, Point *point, int pointNum);

Point *part_y_Sort(Point *point, int i, int ySum);

int compXY(const void *x, const void *y) {
    return ((*(Point *) x).x != (*(Point *) y).x) ?
           (*(Point *) x).x - (*(Point *) y).x :
           (*(Point *) x).y - (*(Point *) y).y;
}

int main(void) {
    FILE *inFile;
    inFile = fopen("input.txt", "r");

    int numTestCases, pointNum, cafeNum;
    int T = 0;
    int i = 0;
    int j = 0;
    Point *point;
    CafeInfo *cafe;
    int *cafe_Question;

    fscanf(inFile, "%d", &numTestCases);

    for (T = 0; T < numTestCases; T++) {
        fscanf(inFile, "%d", &pointNum);
        point = (Point *) malloc(sizeof(Point) * pointNum);
        cafe = (CafeInfo *) malloc(sizeof(CafeInfo) * pointNum);

        for (i = 0; i < pointNum; i++) {
            fscanf(inFile, "%d %d", &point[i].x, &point[i].y);
            //cout << point[i].x << " " << point[i].y<<endl;
        }
        fscanf(inFile, "%d", &cafeNum);
        cafe_Question = (int *) malloc(sizeof(int) * cafeNum);
        for (i = 0; i < cafeNum; i++)
            fscanf(inFile, "%d", &cafe_Question[i]);

        qsort(point, pointNum, sizeof(struct Point), compXY);

        monotoneWalkway(cafe, point, pointNum);

        for (i = 0; i < cafeNum; i++) {

            for (j = 0; j < pointNum; j++) {
                if (cafe_Question[i] == cafe[j].number) {
                    printf("%d %d\n", cafe[j].x, cafe[j].y);
                    break;
                }
            }
        }
    }
    return 0;
}

void monotoneWalkway(CafeInfo *cafe, Point *point, int pointNum) {
    int now_y = 0;
    int cafeNum = 0;
    Point *cafe_ysort;
    int i = 0;
    int j = 0;
    int ySum;
    for (i; i < pointNum; i++) {
        if (point[i].x == point[i + 1].x) {
            ySum = ySumSearch(point, i);
            cafe_ysort = (Point *) malloc(sizeof(Point) * ySum);
            cafe_ysort = part_y_Sort(point, i, ySum);

            if (now_y == cafe_ysort[0].y) {
                for (j = 0; j < ySum; j++) {
                    cafe[cafeNum].x = cafe_ysort[j].x;
                    cafe[cafeNum].y = cafe_ysort[j].y;
                    cafe[cafeNum].number = cafeNum + 1;
                    now_y = cafe_ysort[j].y;
                    cafeNum++;
                }
            }
            else {
                for (j = ySum - 1; j >= 0; j--) {
                    cafe[cafeNum].x = cafe_ysort[j].x;
                    cafe[cafeNum].y = cafe_ysort[j].y;
                    cafe[cafeNum].number = cafeNum + 1;
                    now_y = cafe_ysort[j].y;
                    cafeNum++;
                }
            }
            i = i + ySum - 1;
        }
        else {
            cafe[cafeNum].x = point[i].x;
            cafe[cafeNum].y = point[i].y;
            cafe[cafeNum].number = cafeNum + 1;
            cafeNum++;
            now_y = point[i].y;
        }
    }
}

int ySumSearch(Point *point, int i) {
    int sum = 1;
    while (point[i].x == point[i + 1].x) {
        sum++;
        i++;
    }
    return sum;
}

Point *part_y_Sort(Point *point, int i, int ySum) {
    int a = 0;
    Point *ySort = (Point *) malloc(sizeof(Point) * ySum);
    for (a = 0; a < ySum; a++) {
        ySort[a].x = point[i].x;
        ySort[a].y = point[i].y;
        i++;
    }
    return ySort;
}