#include <cstdio>
#include <vector>
#include <set>
#define pi pair<int,int>
#define mp make_pair
using namespace std;

int distances[100001];
set<int> stall[100001];
set<pi> candy[101];

int main()
{
	int N, S, Q;
	scanf("%d %d", &N, &S);
	for (int i = 1; i <= N; i++)
		scanf("%d", &distances[i]);
	int s, a;
	for (int i = 0; i < S; i++)
	{
		scanf("%d %d", &s, &a);
		stall[s].insert(a);
		candy[a].insert(mp(distances[s], s));
	}
	scanf("%d", &Q);
	char c; int x, k;
	for (int i = 0; i < Q; i++)
	{
		scanf(" %c", &c);
		switch (c)
		{
			case 'A':
				scanf("%d %d", &x, &k);
				stall[x].insert(k);
				candy[k].insert(mp(distances[x], x));
				break;
			case 'S':
				scanf("%d %d", &x, &k);
				stall[x].erase(k);
				candy[k].erase(mp(distances[x], x));
				break;
			case 'E':
				scanf("%d %d", &x, &k);
				for (int c : stall[x])
					candy[c].erase(mp(distances[x], x));
				stall[x].clear();
				distances[x] = k;
				break;
			case 'Q':
				scanf("%d", &k);
				if (candy[k].empty())
					printf("-1\n");
				else
					printf("%d\n", (*candy[k].begin()).second);
				break;
		}
	}
    return 0;
}