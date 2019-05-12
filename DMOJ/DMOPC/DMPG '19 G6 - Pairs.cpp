#include <bits/stdc++.h>
using namespace std;
#define pi pair<int, int>
#define ll long long

const ll mod = 1e9 + 7;
int sa[400005][26], link[400005], len[400005], minlen[400005], cloned[400005], states, last;
ll freq[400005], diff[200005], sumfreq[400005];

void add(int c) {
	int cur = states++;
	len[cur] = len[last] + 1;
	int p = last;
	last = cur;
	for (; p != -1 && !sa[p][c]; p = link[p]) {
		sa[p][c] = cur;
	}
	if (p == -1)
		link[cur] = 0;
	else {
		int q = sa[p][c];
		if (len[q] == len[p] + 1) {
			link[cur] = q;
		}
		else {
			int clone = states++;
			cloned[clone] = 1;
			len[clone] = len[p] + 1;
			link[clone] = link[q];
			for (int c = 0; c < 26; c++) {
				sa[clone][c] = sa[q][c];
			}
			for (; p != -1 && sa[p][c] == q; p = link[p]) {
				sa[p][c] = clone;
			}
			link[q] = link[cur] = clone;
			minlen[clone] = len[link[clone]] + 1;
			minlen[q] = len[link[q]] + 1;
		}
	}
	minlen[cur] = len[link[cur]] + 1;
}

void initFreq() {
	vector<pi> v;
	for (int i = 0; i < states; i++) {
		v.push_back(pi(len[i], i));
		freq[i] = 1 - cloned[i];
	}
	sort(v.rbegin(), v.rend());
	for (int i = 0; i < states; i++) {
		int s = v[i].second;
		if (link[s] != -1)
			freq[link[s]] += freq[s];
	}
}

ll calcSumFreq(int s) {
	if (sumfreq[s])
		return sumfreq[s];
	sumfreq[s] = freq[s];
	for (int i = 0; i < 26; i++) {
		if (sa[s][i])
			sumfreq[s] += calcSumFreq(sa[s][i]);
	}
	sumfreq[s] %= mod;
	return sumfreq[s];
}

int main() {
	ll n;
	scanf("%lld", &n);
	states = 1;
	last = 0;
	link[0] = -1;
	len[0] = minlen[0] = cloned[0] = 0;
	char c;
	for (int i = 0; i < n; i++) {
		scanf(" %c", &c);
		add(c - 'a');
	}
	initFreq();
	calcSumFreq(0);
	for (int i = 0; i < states; i++) {
		ll sum = sumfreq[i];
		ll pairSubstrings = sum * sum % mod;
		for (int j = 0; j < 26; j++) {
			if (sa[i][j])
				pairSubstrings -= sumfreq[sa[i][j]] * sumfreq[sa[i][j]] % mod;
		}
		pairSubstrings %= mod;
		if (i == 0)
			pairSubstrings -= 1LL * (n + 1) * (n + 1) % mod * (n + 1) % mod;
		pairSubstrings %= mod;
		diff[minlen[i]] += pairSubstrings;
		diff[len[i] + 1] -= pairSubstrings;
	}
	ll sum = 0;
	for (int i = 0; i <= n; i++) {
		if (i > 0)
			diff[i] += diff[i - 1];
		diff[i] %= mod;
		if (diff[i] < 0)
			diff[i] += mod;
		sum += diff[i];
		printf("%lld\n", diff[i]);
	}
}