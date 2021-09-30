#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll a[200005], over[200005];
ll B = 500;

int main() {
	ll n, sum = 0;
	scanf("%lld", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
        over[a[i]]++;
        sum += a[i];
	}
    for (int i = 200000; i>=0; i--)
        over[i] += over[i+1];
	sort(a, a + n);
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		if (i > 0 && a[i] == a[i - 1])
			continue;
		if (a[i] < B) {
			ll sub = 0;
			for (int j = 0; j < n; j++)
				sub += a[j] % a[i];
			ans = max(ans, sum - sub);
		}
        else {
            ll cnt = 0;
            for (int j = a[i]; j < 200005; j += a[i])
                cnt += over[j];
            ans = max(ans, cnt * a[i]);
        }
	}
    printf("%lld", ans);
}