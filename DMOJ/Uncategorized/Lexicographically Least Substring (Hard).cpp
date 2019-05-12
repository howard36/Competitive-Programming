#include <bits/stdc++.h>
using namespace std;
#define pi pair<int, int>

int sa[2000006][26], len[2000006], link[2000006], states, last, longest[2000006];
pi sorted[2000006];

void append(int c) {
	int cur = states++;
	len[cur] = len[last] + 1;
	int p = last;
	last = cur;
	for (; p != -1 && !sa[p][c]; p = link[p])
		sa[p][c] = cur;
	if (p == -1)
		link[cur] = 0;
	else {
		int q = sa[p][c];
		if (len[q] == len[p] + 1)
			link[cur] = q;
		else {
			int clone = states++;
			len[clone] = len[p] + 1;
			link[clone] = link[q];
			link[q] = link[cur] = clone;
			for (int cc = 0; cc < 26; cc++)
				sa[clone][cc] = sa[q][cc];
			for (; p != -1 && sa[p][c] == q; p = link[p])
				sa[p][c] = clone;
		}
	}
}

int main() {
	string s;
	cin >> s;
	states = 1;
	link[0] = -1;
	for (char c : s)
		append(c - 'a');
	for (int i = 0; i < states; i++)
		sorted[i] = pi(len[i], i);
	sort(sorted, sorted + states, greater<pi>());
    for (auto p : sorted){
        int i = p.second;
        longest[i] = 1;
        for (int c = 0; c<26; c++){
            if (sa[i][c])
                longest[i] = max(longest[i], longest[sa[i][c]] + 1);
        }
    }
	int k;
	scanf("%d", &k);
	int cur = 0;
	for (int i = 0; i < k; i++) {
        for (int c = 0; c<26; c++){
            if (sa[cur][c] && longest[sa[cur][c]] >= k-i){
                printf("%c", c+'a');
                cur = sa[cur][c];
                break;
            }
        }
	}
}