#include <bits/stdc++.h>

#define PII pair<int,int>
#define PIII pair<int,PII>

using namespace std;
typedef long long ll;

int arr[201];
bool hasRobot[201];
int N, K, zeroCnt = 0;
int s, e;

void rotate() {
    s = (s + 2 * N - 1) % (2 * N);
    e = (e + 2 * N - 1) % (2 * N);
    if (hasRobot[e]) hasRobot[e] = false;
}

void moveRobots() {
    if (e < s) {
        for (int i = e-1; i >= 0; i--) {
            if (hasRobot[i] && !hasRobot[i + 1] && arr[i+1] > 0) {
                hasRobot[i] = false;
                if (--arr[i + 1] == 0) zeroCnt++;
                hasRobot[i + 1] = true;
            }
        }

        if (hasRobot[2*N-1] && !hasRobot[0] && arr[0] > 0) {
            hasRobot[2*N-1] = false;
            if (--arr[0] == 0) zeroCnt++;
            hasRobot[0] = true;
        }


        for (int i = 2 * N - 2; i >= s+1; i--) {
            if (hasRobot[i] && !hasRobot[i + 1] && arr[i + 1] > 0) {
                hasRobot[i] = false;
                if (--arr[i + 1] == 0) zeroCnt++;
                hasRobot[i + 1] = true;
            }
        }
    }
    else {
        for (int i = e-1; i >= s; i--) {
            if (hasRobot[i] && !hasRobot[i + 1] && arr[i + 1] > 0) {
                hasRobot[i] = false;
                if (--arr[i + 1] == 0) zeroCnt++;
                hasRobot[i + 1] = true;
            }
        }
    }
    hasRobot[e] = false;
}

void putNewRobot() {
    if (arr[s] > 0) {
        if (--arr[s] == 0) zeroCnt++;
        hasRobot[s] = true;
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> K;
    for (int i = 0; i < 2 * N; i++) cin >> arr[i];
    s = 0, e = N - 1;
    int t = 0;

    while (zeroCnt < K) {
        t++;
        rotate();
        moveRobots();
        putNewRobot();
    }

    cout << t;
   
    return 0;
}