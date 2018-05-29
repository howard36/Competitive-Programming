#include <cstdio>
#include <algorithm>
using namespace std;

int x[100005];

int main()
{
	int N, D, from, to;
	scanf("%d%d", &N, &D);
	for (int i = 1; i <= N; i++)
		scanf("%d", &x[i]);
	int minleftto = 1e9, maxleftfrom = -1e9, minrightfrom = 1e9, maxrightto = -1e9;
	for (int i = 0; i < D; i++) {
		scanf("%d%d", &from, &to);
		from = x[from], to = x[to];
		if (from < to) {
			if (from < minrightfrom)
				minrightfrom = from;
			if (to > maxrightto)
				maxrightto = to;
		}
		else {
			if (from > maxleftfrom)
				maxleftfrom = from;
			if (to < minleftto)
				minleftto = to;
		}
	}
	int ans;
	if (minrightfrom == 1e9)
		ans = maxleftfrom - minleftto;
	else if (minleftto == 1e9)
		ans = maxrightto - minrightfrom;
	else {
		int diff = min(abs(minleftto - minrightfrom), abs(maxleftfrom - maxrightto));
		ans = maxleftfrom - minleftto + maxrightto - minrightfrom + diff;
	}
	printf("%d", ans);
	return 0;
}