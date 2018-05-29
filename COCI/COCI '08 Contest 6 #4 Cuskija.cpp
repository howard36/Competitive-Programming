#include <cstdio>
#include <vector>
using namespace std;

vector<int> mod[3];

int main()
{
	int N, x;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &x);
		mod[x % 3].push_back(x);
	}
	if ((mod[0].size() == 0 && mod[1].size() && mod[2].size()) || mod[0].size() > (N + 1) / 2) {
		printf("impossible");
		return 0;
	}
	for (int i = 0; i < N; i++) {
		if (mod[1].size()) {
			if (mod[0].size() > 1) {
				printf("%d ", mod[0].back());
				mod[0].pop_back();
			}
			printf("%d ", mod[1].back());
			mod[1].pop_back();
		}
		else {
			if (mod[0].size()) {
				printf("%d ", mod[0].back());
				mod[0].pop_back();
			}
			if (mod[2].size()) {
				printf("%d ", mod[2].back());
				mod[2].pop_back();
			}
		}
	}
    return 0;
}