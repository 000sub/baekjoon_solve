#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int arr[1001];
vector<int> v;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n, sum = 0;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		sum += arr[i];
	}
	sum /= 2;

	for (int i = 1; i < n; i+=2) {
		sum -= arr[i];
	}

	v.push_back(sum);

	int temp = sum;
	for (int i = 0; i < n-1; i++) {
		temp = arr[i] - temp;
		v.push_back(temp);
	}

	for (int i : v) cout << i << '\n';




	return 0;
}