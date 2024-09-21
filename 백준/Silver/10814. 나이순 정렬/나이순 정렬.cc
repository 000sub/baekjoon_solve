#include <bits/stdc++.h>

#define PII pair<int,int>
#define PIII pair<int,PII>

using namespace std;
typedef long long ll;

int N;

typedef struct Member {
    int age;
    int idx;
    string name;

    bool operator<(Member& other) {
        if (age == other.age) return idx < other.idx;
        return age < other.age;
    }
} Member;

Member arr[100001];


int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> arr[i].age >> arr[i].name;
        arr[i].idx = i;
    }

    sort(arr, arr + N);
    
    for (int i = 0; i < N; i++) cout << arr[i].age << " " << arr[i].name << '\n';

    return 0;
}