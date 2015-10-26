#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>
#include <cmath>
using namespace std;

int f(int num) {
	for (int i = 2; i < num; i++) {
		int temp = num;
		int n = num % i;

		while (temp > 0) {
			if (temp % i == n)
				temp /= i;
			else
				break;
		}
		if (temp == 0)
			return i;
	}
}
int main() {
	int testCase;

	freopen("input.txt", "r", stdin);

	cin >> testCase;

	for (int p = 1; p <= testCase; p++) {
		int n;

		cin >> n;

		cout << "Case #" << p << endl;
		
		cout << f(n) << endl;
	}
}