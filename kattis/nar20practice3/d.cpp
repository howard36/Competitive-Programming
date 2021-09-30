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
typedef pair<ll,ll> pl;
typedef pair<pl,ll> ppl;
typedef pair<ld,ld> pd;
typedef complex<ld> cd;

ppl edges[1000006];
ll dist[100005], rem[100005], path[100005];
priority_queue<pl> pq;
vector<pl> adj[100005];


int main() { FAST
	int n, m;
    cin >> n >> m;
    for (int i = 0; i<m; i++) {
        ll a, b, w;
        cin >> a >> b >> w;
        edges[i] = ppl(pl(a,b), w);
        adj[a].pb(pl(b,w));
        adj[b].pb(pl(a,w));
    }
    for (int i = 0; i<n; i++) {
        dist[i] = 1e18;
    }
    dist[1] = 0;
    pq.push(pl(0,1));
    while (!pq.empty()) {
        pl p = pq.top(); pq.pop();
        ll v = p.s;
        if (-p.f > dist[v])
            continue;
        for (pl q : adj[v]) {
            ll w = q.f;
            if (dist[v] + q.s < dist[w]) {
                dist[w] = dist[v] + q.s;
                pq.push(pl(-dist[w], w));
                rem[w] = v;
            }
        }
    }

    for (int i = 0; i<n; i++) {
        dist[i] = 1e18;
    }
    dist[0] = 0;
    pq.push(pl(0,0));
    while (!pq.empty()) {
        pl p = pq.top(); pq.pop();
        ll v = p.s;
        if (v == 1)
            break;
        if (-p.f > dist[v])
            continue;
        for (pl q : adj[v]) {
            ll w = q.f;
            if (w == rem[v])
                continue;
            if (dist[v] + q.s < dist[w]) {
                dist[w] = dist[v] + q.s;
                pq.push(pl(-dist[w], w));
                path[w] = v;
            }
        }
    }
    if (dist[1] == 1e18) {
        finish("impossible");
    }
    vector<int> ans;
    for (int v = 1; v != 0; v = path[v]) {
        ans.pb(v);
    }
    ans.pb(0);
    reverse(ans.begin(), ans.end());
    cout << sz(ans) << " ";
    for (int i : ans) {
        cout << i << " ";
    }
    cout << endl;
}
