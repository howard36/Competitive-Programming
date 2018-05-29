#include <cstdio>
#include <algorithm>
using namespace std;
int A[1000006], N;

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", &A[i]);
	int s = 0, e = N - 1, move = 1, count = 0;
	while (s <= e)
	{
		if (A[s] - max(A[s+1],A[e]) > A[e] - max(A[s], A[e-1]))
		{
			if (move & 1)
				count += A[s];
			++s;
		}
		else
		{
			if (move & 1)
				count += A[e];
			--e;
		}
		++move;
	}
	printf("%d", count);
    return 0;
}