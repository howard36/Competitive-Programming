#include <bits/stdc++.h>
using namespace std;

int main() {
	int R, C, K;
	cin >> R >> C >> K;
	int xlo = 1, xhi = R, ylo = 1, yhi = C;
	while (xlo < xhi || ylo < yhi) {
		int xmid = (xlo + xhi) / 2;
		int ymid = (ylo + yhi) / 2;
		int a, ax, ay;
		cout << "? " << xmid << " " << ymid << endl;
		cin >> a;
		if (xlo < xhi) {
			cout << "? " << xmid + 1 << " " << ymid << endl;
			cin >> ax;
			if (a < ax)
				xhi = xmid;
			else
				xlo = xmid + 1;
		}
		if (ylo < yhi) {
			cout << "? " << xmid << " " << ymid + 1 << endl;
			cin >> ay;
			if (a < ay)
				yhi = ymid;
			else
				ylo = ymid + 1;
		}
	}
	cout << "? " << xlo << " " << ylo << endl;
	int ans;
	cin >> ans;
	cout << "! " << ans << endl;
	return 0;
}