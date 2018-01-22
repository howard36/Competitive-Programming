#include <cstdio>
using namespace std;

#define getchar() (*_pbuf ? *_pbuf++ : (_buf[fread_unlocked(_pbuf = _buf, 1, 16384, stdin)] = 0, *_pbuf++))
char _buf[16385], *_pbuf = _buf;

int read()
{
	int c, o = 0;
	while ((c = getchar()) < '0');
	do o = o * 10 + c - '0';
	while ((c = getchar()) >= '0');
	return o;
}

bool color[10001][10001];

int main()
{
	int n, m, x, y, w, h;
	n = read(); m = read();
	for (int i = 0; i < m; i++)
	{
		x = read(); y = read(); w = read(); h = read();
		color[x][y] ^= 1;
		color[x + w][y] ^= 1;
		color[x][y + h] ^= 1;
		color[x + w][y + h] ^= 1;
	}
	int ans = 0;
	if (color[0][0]) ++ans;
	for (int i = 1; i < n; i++)
	{
		color[0][i] ^= color[0][i - 1];
		color[i][0] ^= color[i - 1][0];
		if (color[0][i]) ++ans;
		if (color[i][0]) ++ans;
	}
	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j < n; j++)
		{
			color[i][j] ^= color[i - 1][j] ^ color[i][j - 1] ^ color[i - 1][j - 1];
			if (color[i][j]) ++ans;
		}
	}
	printf("%d", ans);
    return 0;
}