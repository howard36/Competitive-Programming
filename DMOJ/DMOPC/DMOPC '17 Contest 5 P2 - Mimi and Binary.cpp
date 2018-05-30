#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char arr[100005];
int freq[2][100005];

int main()
{
	int N, Q, x, y, z;
	scanf("%s", arr);
	N = strlen(arr);
	scanf("%d", &Q);
	for (int i = 1; i <= N; i++) {
		freq[(int)(arr[i] == '1')][i]++;
		freq[0][i + 1] = freq[0][i];
		freq[1][i + 1] = freq[1][i];
	}
	for (int i = 0; i < Q; i++) {
		scanf("%d%d%d", &x, &y, &z);
		int ind = lower_bound(freq[z] + 1, freq[z] + N + 1, y + freq[z][x - 1]) - freq[z] - 1;
		if (ind == N)
			ind = -1;
		else
			ind += 1;
		printf("%d\n", ind);
	}
    return 0;
}