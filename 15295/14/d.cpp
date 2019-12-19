#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll a[100005];
ll b[100005];
ll f[1000006];

int main() {
	int c;
	cin >> c;
	while (c--) {
		int d, n;
		cin >> d >> n;
		for (int i = 0; i<n; i++) 
			cin >> a[i];
		for (int i = 0; i<n; i++)
			b[i+1] = b[i] + a[i];
		for (int i = 0; i<d; i++)
			f[i] = 0;
		for (int i = 0; i<=n; i++)
			f[b[i]%d]++;
		ll ans = 0;
		for (int i = 0; i<d; i++)
			ans += f[i]*(f[i]-1)/2;
		cout << ans << endl;
	}
}
