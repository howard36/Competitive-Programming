#include <cstdio>
#include <algorithm>
using namespace std;
using pi = pair<int, int>;

int A[1000];
pi dp[1001][5001];

inline int readDigits(int a, int b)
{
	int ret = 0;
	for (int i = a; i <= b; i++)
		ret = ret * 10 + A[i];
	return ret;
}

int main()
{
	int digits = 0, S;
	char c;
	while ((c = getchar()) != '=')
		A[digits++] = c - '0';
	scanf("%d", &S);
	
	dp[0][0] = pi(0,-1);
	for (int i = digits-1; i >= 0; i--)
	{
		if (A[i] == 0)
		{
			for (int s = 0; s <= S; s++)
				if (dp[digits - i - 1][s].first != 0 || dp[digits - i - 1][s].second != 0)
					dp[digits - i][s] = pi(dp[digits - i - 1][s].first + 1, dp[digits - i - 1][s].second);
			continue;
		}
		for (int d = 1; i + d - 1 < digits && d <= 4; d++)
		{
			int prefix = readDigits(i, i + d - 1);
			int rem = digits - i - d;
			for (int s = 0; s <= S - prefix; s++)
			{
				if (dp[rem][s].first != 0 || dp[rem][s].second != 0)
					if (dp[digits - i][s + prefix].first == 0 || dp[rem][s].second + 1 < dp[digits - i][s + prefix].second)
						dp[digits - i][s + prefix] = pi(d, dp[rem][s].second + 1);
			}
		}
	}

	int d = 0, s = S;
	while (true)
	{
		int x = readDigits(d, d + dp[digits - d][s].first - 1);
		for (int i = d; i < d + dp[digits - d][s].first; i++)
			printf("%d", A[i]);
		d += dp[digits - d][s].first;
		s -= x;
		if (d < digits)
			printf("+");
		else
		{
			printf("=%d", S);
			break;
		}
	}
    return 0;
}