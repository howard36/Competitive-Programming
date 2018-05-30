#include <cstdio>
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
using namespace std;

int rating[11][500001], ps[11][500001];

int main()
{
	int N, Q;
	scan(N); scan(Q);
	int r;
	for (int i = 1; i <= N; i++)
	{
		scan(r);
		rating[r][i]++;
		for (int j = 1; j <= 10; j++)
			ps[j][i] = ps[j][i - 1] + rating[j][i];
	}
	int a, b;
	for (int i = 1; i <= Q; i++)
	{
		scan(a); scan(b);
		for (int j = 10; j > 0; j--)
		{
			if (ps[j][b] - ps[j][a - 1] < ps[j][N])
			{
				printf("%d %d\n", j, ps[j][N] - (ps[j][b] - ps[j][a - 1]));
				break;
			}
		}
	}
    return 0;
}