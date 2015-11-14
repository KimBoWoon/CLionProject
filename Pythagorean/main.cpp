#include <iostream>
#include <string.h>
#include <climits>

using namespace std;

double score[2001];
double lose[2001];

int main() {
    int testCase;

    freopen("input.txt", "r", stdin);

    cin >> testCase;

    while (testCase--) {
        int team, game;

        cin >> team >> game;

        memset(score, 0, sizeof(double) * 2001);
        memset(lose, 0, sizeof(double) * 2001);

        for (int i = 0; i < game; i++) {
            int a, b, p, q;
            cin >> a >> b >> p >> q;

            score[a] += p;
            score[b] += q;
            lose[a] += q;
            lose[b] += p;
        }

        double max = INT_MIN;
        double min = INT_MAX;
        double Expectation;
        for (int i = 1; i <= team; i++) {
            if (score[i] == 0 && lose[i] == 0)
                Expectation = 0;
            else
                Expectation = (((score[i]) * (score[i])) * 1000 / (((score[i]) * (score[i])) + ((lose[i]) * (lose[i]))));

            if (max < Expectation)
                max = Expectation;
            else if (min > Expectation)
                min = Expectation;
        }
        cout << (int)max << endl << (int)min << endl;
    }
}