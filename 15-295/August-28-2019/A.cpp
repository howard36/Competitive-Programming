#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ll n, d, x, a, g, r;
    scanf("%lld %lld", &n, &d);
    bool pass = true;
    while (n--){
        scanf("%lld %lld %lld %lld", &x, &a, &g, &r);
		// printf("%lld %lld %lld %lld\n", x, a, g, r);
        if (x < a) pass = false;
		else if ((x-a)%(g+r) > g) pass = false;
    }
    if (pass) printf("YES");
    else printf("NO");
}