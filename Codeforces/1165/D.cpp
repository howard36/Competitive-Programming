#include <bits/stdc++.h>
using namespace std;

int mindiv[1000006], freq[340005];
vector<int> primes;

int main() {
	int t;
	scanf("%d", &t);
    memset(mindiv, -1, sizeof mindiv);
	for (int i = 2; i < 1000006; i++) {
		if (mindiv[i] == -1) {
            mindiv[i] = primes.size();
            primes.push_back(i);
		}
        for (int j = 0; j<=mindiv[i]; j++){
            mindiv[i*primes[j]] = j;
        }
	}
	while (t--) {
        memset(freq, 0, sizeof freq);
		int n;
        scanf("%d", &n);
        for (int i = 0; i<n; i++){
            int d;
            scanf("%d", &d);
            int p = -1, e = 0;
            while (d > 1) {
                if (mindiv[d] != p){
                    p == mindiv[d];
                    e = 1;
                }
                else 
                    e++;
                freq[p] = max(freq[p], e);
                d /= primes[mindiv[d]];
            }
        }
	}
}