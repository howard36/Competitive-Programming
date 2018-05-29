#include <cstdio>
#include <utility>
#define pi pair<int, int>
using namespace std;
int sum[750][750][101];
pi edges[500];

int main()
{
	int N, M;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &edges[i].first, &edges[i].second);
		--edges[i].first;
		--edges[i].second;
	}
	int count = 0;
	for (int i = 0; i < (1 << N); i++) {
		bool good = true;
		for (int j = 0; j < M; j++) {
			if ((i&(1 << edges[j].first)) && (i&(1 << edges[j].second))) {
				good = false;
				break;
			}
		}
		if (good)
			++count;
	}
	printf("%d", count);
    return 0;
}