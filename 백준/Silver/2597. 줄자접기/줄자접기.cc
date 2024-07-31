#include <bits/stdc++.h>

#define PII pair<int,int>

using namespace std;
typedef long long ll;

int main() {
	// ios::sync_with_stdio(false);
	// cin.tie(0); cout.tie(0);

	double start = 0.0, end, len;
	double rA, rB, bA, bB, yA, yB;
	cin >> end >> rA >> rB >> bA >> bB >> yA >> yB;

	if (rA != rB) {
		double mid = (rA + rB) / 2;
		len = mid - start;
		if (bA < mid) bA = mid + (mid - bA);
		if (bB < mid) bB = mid + (mid - bB);
		if (yA < mid) yA = mid + (mid - yA);
		if (yB < mid) yB = mid + (mid - yB);

		start = mid;
		end = max(end, mid + len);
	}

	if (bA != bB) {
		double mid = (bA + bB) / 2;
		len = mid - start;
		if (yA < mid) yA = mid + (mid - yA);
		if (yB < mid) yB = mid + (mid - yB);

		start = mid;
		end = max(end, mid + len);
	}

	if (yA != yB) {
		double mid = (yA + yB) / 2;
		len = mid - start;
		start = mid;
		end = max(end, mid + len);
	}


	printf("%.1lf", end - start);


	return 0;
}	