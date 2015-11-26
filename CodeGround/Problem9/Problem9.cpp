#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

class Point {
private:
	int x, y;
public:
	Point() {}
	Point(int x, int y) : x(x), y(y) {}

	void setX(int x) {
		this->x = x;
	}
	void setY(int y) {
		this->y = y;
	}
	int getX() {
		return x;
	}
	int getY() {
		return y;
	}
};

bool comp(Point &x, Point &y) {
	return (x.getX() == y.getX()) ? x.getY() < y.getY() : x.getX() > y.getX();
}
int main() {
	int testCase;
	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);

	scanf("%d", &testCase);

	for (int t = 0; t < testCase; t++) {
		int size, cnt = 0;
		vector<Point> v;

		scanf("%d", &size);

		for (int i = 0; i < size; i++) {
			int x, y;
			scanf("%d %d", &x, &y);
			Point p(x, y);
			v.push_back(p);
		}
		sort(v.begin(), v.end(), comp);

		for (int i = 0; i < v.size(); i++) {
			if (v[i].getX() >= v[v.size() - 1].getX() && v[i].getY() <= v[v.size() - 1].getY()) {
				cnt++;
				//printf("%d %d\n", v[i].getX(), v[i].getY());
			}
		}

		printf("Case #%d\n%d\n", t + 1, cnt);
	}
	return 0;
}