#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back
#define mp make_pair
#define all(v) v.begin(), v.end()
#define sz(v) (int)v.size()

#define MOO(i, a, b) for(int i=a; i<b; i++)
#define M00(i, a) for(int i=0; i<a; i++)
#define MOOd(i,a,b) for(int i = (b)-1; i >= a; i--)
#define M00d(i,a) for(int i = (a)-1; i>=0; i--)

#define FAST ios::sync_with_stdio(0); cin.tie(0);
#define finish(x) return cout << x << '\n', 0;
#define dbg(x) cerr << ">>> " << #x << " = " << x << "\n";
#define _ << " _ " <<

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef pair<ld,ld> pd;
typedef complex<ld> cd;

int cnt[102][30], l[102], used[102][30];
string s[102];
queue<ll> q[30];

struct Edge
{
    int from, to, capacity, cost;
};

vector<vector<int>> adj, cost, capacity;

const int INF = 1e9;

void shortest_paths(int n, int v0, vector<int>& d, vector<int>& p) {
    d.assign(n, INF);
    d[v0] = 0;
    vector<bool> inq(n, false);
    queue<int> q;
    q.push(v0);
    p.assign(n, -1);

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        inq[u] = false;
        for (int v : adj[u]) {
            if (capacity[u][v] > 0 && d[v] > d[u] + cost[u][v]) {
                d[v] = d[u] + cost[u][v];
                p[v] = u;
                if (!inq[v]) {
                    inq[v] = true;
                    q.push(v);
                }
            }
        }
    }
}

int min_cost_flow(int N, vector<Edge> edges, int K, int s, int t) {
    adj.assign(N, vector<int>());
    cost.assign(N, vector<int>(N, 0));
    capacity.assign(N, vector<int>(N, 0));
    for (Edge e : edges) {
        adj[e.from].push_back(e.to);
        adj[e.to].push_back(e.from);
        cost[e.from][e.to] = e.cost;
        cost[e.to][e.from] = -e.cost;
        capacity[e.from][e.to] = e.capacity;
    }

    int flow = 0;
    int cost = 0;
    vector<int> d, p;
    while (flow < K) {
        shortest_paths(N, s, d, p);
        if (d[t] == INF)
            break;

        // find max flow on that path
        int f = K - flow;
        int cur = t;
        while (cur != s) {
            f = min(f, capacity[p[cur]][cur]);
            cur = p[cur];
        }

        // apply flow
        flow += f;
        cost += f * d[t];
        cur = t;
        while (cur != s) {
            capacity[p[cur]][cur] -= f;
            capacity[cur][p[cur]] += f;
            cur = p[cur];
        }
    }

    if (flow < K)
        return -1;
    else
        return cost;
}

int main() { FAST
	cin >> s[0];
	int n;
	cin >> n;
	for (int i = 1; i<=n; i++) {
		cin >> s[i] >> l[i];
	}
	for (int i = 0; i<=n; i++) {
		for (char c : s[i]) {
			cnt[i][c-'a']++;
		}
	}
	vector<Edge> edges;
	for (int i = 0; i<26; i++) {
		edges.pb(Edge{0, i+1, cnt[0][i], 0});
		for (int j = 1; j<=n; j++) {
			edges.pb(Edge{i+1, j+26, cnt[j][i], 0});
		}
	}
	int N = 28+n;
	for (int i = 1; i<=n; i++) {
		edges.pb(Edge{i+26, N-1, l[i], i});
	}
	finish(min_cost_flow(N, edges, s[0].length(), 0, N-1));
	


	/*
	ll cost = 0;
	for (char c : g) {
		q[c-'a'].push(1e15);
		ll i = q[c-'a'].front();
		q[c-'a'].pop();
		cost += i;
		if (i < 1e15) {
			l[i-1]--;
			used[i-1][c-'a']++;
		} else {
			dbg(2);
			finish(-1);
		}
	}
	for (int i = 0; i<n; i++) {
		for (; l[i]<0; l[i]++) {
			ll bestc = -1, minq = 1e16;
			for (int c = 0; c<26; c++) {
				if (used[i][c] > 0 && q[c].front() < minq) {
					minq = q[c].front();
					bestc = c;
				}
			}
			dbg(i _ bestc _ minq);
			used[i][bestc]--;
			used[minq-1][bestc]++;
			l[minq-1]--;
			cost += minq - (i+1);
			q[bestc].pop();
			if (minq == 1e15) {
				dbg(3);
				finish(-1);
			}
		}
	}
	finish(cost);
	*/
}
