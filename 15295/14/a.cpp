#include <bits/stdc++.h>
using namespace std;

int a[102];
double p[100005];

int main() {
	int n, m;
	while (cin >> n) {
		cin >> m;
		for (int i = 0; i<n; i++) {
			string s;
			cin >> s;
			if (s == "10" || s == "J" || s == "Q" || s == "K")
				a[i] = 10;
			else if (s == "A")
				a[i] = 11;
			else
				a[i] = s[0] - '0';
		}
		int pos = 10;
		for (int i = n-2; i>=0; i--) {
			p[pos] = 1;
			pos += a[i];
		}
		p[pos] = 1;
		int N = pos + m;
		for (int i = 11; i<N; i++) {
			if (p[i] == 1)
				continue;
			double s = 0;
			for (int j = 2; j<=11; j++)
				s += p[i-j];
			s += 3*p[i-10];
			p[i] = s/13;
		}
		double ans = 0;
		for (int i = 1; i<= 10; i++)
			ans += p[N-i];
		cout << fixed << setprecision(10) << ans/10 << endl;
		for (int i = 0; i<N; i++)
			p[i] = 0;
	}
}
