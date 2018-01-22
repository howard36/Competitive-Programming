#include <algorithm>
#include <cstdio>
using namespace std;

bool compare(int x, int y) { return x > y; }

int heights[500];
bool distinctHeights[51];
bool possible[25000] = { 1 };

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) { scanf("%d", &heights[i]); }
	sort(heights, heights + n, compare);

	for (int i = 1; i < n; i++)
		distinctHeights[heights[i]] = true;

	int maxPossible = 0;
	for (int i = 2; i < n; i++)
	{
		for (int j = maxPossible; j >= 0; j--)
			if (possible[j])
				for (int k = 50; k > heights[i]; k--)
					if (distinctHeights[k])
						possible[k - heights[i] + j] = true;
		maxPossible += heights[1] - heights[i];
	}

	for (int i = 0; i <= maxPossible; i++)
		if (possible[i])
			printf("%d ", i);
    return 0;
}