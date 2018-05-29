#include <cstdio>
#include <cstring>

bool A[100000], B[100000];

int main()
{
	long long N, T;
	scanf("%d %lld ", &N, &T);
	for (int i = 0; i < N; i++)
		A[i] = (getchar() == '1');
	for (int log = 0; T > 0; T >>= 1, log++)
		if (T & 1)
		{
			for (int i = 0; i < N; i++)
				B[i] = A[(i + (1LL << log)) % N] ^ A[(((i - (1LL << log)) % N) + N) % N];
			memcpy(A, B, N * sizeof(A[0]));
		}
	for (int i = 0; i < N; i++)
		printf("%d", A[i] ? 1 : 0);
    return 0;
}