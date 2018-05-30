#include <cstdio>
#include <vector>
using namespace std;
vector<int> recipe[300005];
int use[300005], needed[300005];
bool have[300005];

void add(int p) {
	if (have[p])
		return;
	have[p] = true;
	int t = use[p];
	while (needed[t] < recipe[t].size() && have[recipe[t][needed[t]]])
		++needed[t];
	if (needed[t] == recipe[t].size()) {
		add(t);
	}
}

int main()
{
	int N, M, D, target, numitems, item;
	scanf("%d%d%d", &N, &M, &D);
	for (int i = 0; i < M; ++i) {
		scanf("%d%d", &target, &numitems);
		for (int j = 0; j < numitems; ++j) {
			scanf("%d", &item);
			recipe[target].push_back(item);
			use[item] = target;
		}
	}

	int p;
	for (int d = 1; d <= D; ++d) {
		scanf("%d", &p);
		add(p);
		if (have[1]) {
			printf("%d", d);
			break;
		}
	}
	if (!have[1])
		printf("-1");
    return 0;
}