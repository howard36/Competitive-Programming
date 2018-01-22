#include <cstdio>
#include <vector>
#include <queue>
#define pb push_back
#define mp make_pair
#define pi pair<int,int>
#define pli pair<ll, int>
#define INF 1e15
#define ll long long
using namespace std;

vector<pi> G[100001];
long long dist[100001];
int N, M, a, b, t;
priority_queue<pli> pq;

int main()
{
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++)
	{
		scanf("%d %d %d", &a, &b, &t);
		if (t == 0) t = 1;
		else t = 1000000;
		G[a].pb(mp(b, t));
		G[b].pb(mp(a, t));
	}
	pq.push(mp(0LL, 1));
	for (int i = 2; i <= N; i++)
	{
		dist[i] = INF;
		pq.push(mp(-INF, i));
	}
	while (!pq.empty())
	{
		ll d = -pq.top().first;
		int v = pq.top().second;
		pq.pop();
		for (pi p : G[v])
		{
			int u = p.first;
			int w = p.second;
			ll tempdist = dist[v] + w;
			if (tempdist < dist[u])
			{
				dist[u] = tempdist;
				pq.push(mp(-tempdist, u));
			}
		}
	}

	if (dist[N] == INF)
		printf("-1");
	else
		printf("%d %d", (int) (dist[N] / 1e6), (int) (dist[N] / 1000000 + dist[N] % 1000000));

    return 0;
}