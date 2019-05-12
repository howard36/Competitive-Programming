#include <bits/stdc++.h>
#define ll long long
#define pi pair<ll, ll>
#define line pair<pi, pi>
using namespace std;

int x[1003], y[1003];
line lines[1000006];
ll lineCount = 0;

ll gcd(ll a, ll b) {
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

pi reduce(pi m) {
	int y = m.first, x = m.second;
	if (x < 0) {
		x = -x;
		y = -y;
	}
	int d = gcd(x, y);
	return pi(y / d, x / d);
}

pi add(pi a, pi b) {
	return reduce(pi(a.first * b.second + a.second * b.first, a.second * b.second));
}

pi neg(pi a) {
	return pi(-a.first, a.second);
}

pi mult(pi a, pi b) {
	return reduce(pi(a.first * b.first, a.second * b.second));
}

int main() {
    // freopen("data.txt", "r", stdin);
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &x[i], &y[i]);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			pi m = pi(y[i] - y[j], x[i] - x[j]);
			m = reduce(m);
            pi b;
            if (m == pi(1, 0))
                b = pi(x[i], 0);
			else
                b = add(pi(y[i], 1), neg(mult(m, pi(x[i], 1))));
			lines[lineCount++] = line(m, b);
		}
	}
	sort(lines, lines + lineCount);
	lineCount = unique(lines, lines + lineCount) - lines;
	sort(lines, lines+lineCount);
    ll ans = lineCount*(lineCount-1)/2;
    ll count = 1;
    for (int i = 1; i<lineCount; i++){
        if (lines[i].first == lines[i-1].first)
            count++;
        else {
            ans -= count*(count-1)/2;
            count = 1;
        }
    }
	ans -= count * (count - 1) / 2;
	printf("%lld", ans);
}