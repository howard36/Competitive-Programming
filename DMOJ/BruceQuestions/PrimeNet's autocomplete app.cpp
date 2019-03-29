#include <bits/stdc++.h>
using namespace std;

string s;
int idx;

struct node {
	int size;
	int end;
	int next[26];
};

node trie[2000006];
int triesize = 1;

void add(int p, int d) {
	trie[p].size++;
	if (s.size() == d) {
		trie[p].end = idx;
	}
	else {
		// cout << "Adding " << s[d] << " of " << s << " to node " << p << endl;
		int c = s[d] - 'a';
		if (trie[p].next[c] == 0) {
			trie[p].next[c] = triesize;
			triesize++;
		}
		add(trie[p].next[c], d + 1);
	}
}

int find(int p, int d) {
	if (s.size() == d) {
		return p;
	}
	else {
		int c = s[d] - 'a';
		if (trie[p].next[c] == 0) {
			return -1;
		}
		else {
			return find(trie[p].next[c], d + 1);
		}
	}
}

int query(int p, int k) {
    // printf("query(%d %d)\n", p, k);
	if (k == 1 && trie[p].end != 0) {
		return trie[p].end;
	}
	else {
		if (trie[p].end != 0) {
			k--;
		}
		for (int i = 0; i < 26; i++) {
			if (trie[p].next[i] != 0) {
				if (trie[trie[p].next[i]].size >= k) {
					return query(trie[p].next[i], k);
				}
				else {
					k -= trie[trie[p].next[i]].size;
				}
			}
		}
	}
}

int main() {
	// freopen("data.txt", "r", stdin);
	int n, m;
	scanf("%d %d", &n, &m);
	for (idx = 1; idx <= n; idx++) {
		cin >> s;
		add(0, 0);
	}
	int k;
    for (int i = 0; i<triesize; i++){
        // printf("trie[%d].size = %d\n", i, trie[i].size);
    }
	for (int i = 0; i < m; i++) {
		scanf("%d", &k);
		cin >> s;
		int start = find(0, 0);
        // printf("start = %d\n", start);
		if (start == -1 || trie[start].size < k) {
			printf("-1\n");
		}
		else {
			printf("%d\n", query(start, k));
		}
	}
}