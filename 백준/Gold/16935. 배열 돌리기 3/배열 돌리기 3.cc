#include <bits/stdc++.h>

#define PII pair<int,int>

typedef long long ll;
using namespace std;

int n, m, r;
int H, W;
int arr[101][101], temp[101][101];

void copyArr(int h, int w) {
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            arr[i][j] = temp[i][j];
        }
    }
}

void upFlip(int h, int w) {
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            temp[i][j] = arr[h-1-i][j];
        }
    }
    copyArr(h, w);
}

void leftFlip(int h, int w) {
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            temp[i][j] = arr[i][w - 1 - j];
        }
    }
    copyArr(h, w);
}

void rRotate(int h, int w) {
    for (int i = 0; i < w; i++) {
        for (int j = 0; j < h; j++) {
            temp[i][j] = arr[h - 1 - j][i];
        }
    }
    copyArr(w, h);
}

void lRotate(int h, int w) {
    for (int i = 0; i < w; i++) {
        for (int j = 0; j < h; j++) {
            temp[i][j] = arr[j][w-1-i];
        }
    }
    copyArr(w, h);
}

void nextSubarr(int h, int w) {
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (i < h / 2 && j < w / 2) {
                temp[i][j + w / 2] = arr[i][j];
            }
            else if (i >= h / 2 && j < w / 2) {
                temp[i - h / 2][j] = arr[i][j];
            }
            else if (i < h / 2 && j >= w / 2) {
                temp[i + h / 2][j] = arr[i][j];
            }
            else {
                temp[i][j - w / 2] = arr[i][j];
            }
        }
    }
    copyArr(h, w);
}

void prevSubarr(int h, int w) {
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (i < h / 2 && j < w / 2) {
                temp[i + h / 2][j] = arr[i][j];
            }
            else if (i >= h / 2 && j < w / 2) {
                temp[i][j + w / 2] = arr[i][j];
            }
            else if (i < h / 2 && j >= w / 2) {
                temp[i][j - w / 2] = arr[i][j];
            }
            else {
                temp[i - h / 2][j] = arr[i][j];
            }
        }
    }
    copyArr(h, w);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> r;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    H = n;
    W = m;
    int op;
    for (int i = 0; i < r; i++) {
        cin >> op;
        switch (op) {
            case 1:
                upFlip(H, W);
                break;
            case 2:
                leftFlip(H, W);
                break;
            case 3:
                rRotate(H, W);
                swap(H, W);
                break;
            case 4:
                lRotate(H, W);
                swap(H, W);
                break;
            case 5:
                nextSubarr(H, W);
                break;
            case 6:
                prevSubarr(H, W);
                break;
        }
    }

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cout << arr[i][j] << " ";
        }
        cout << '\n';
    }

    return 0;
}