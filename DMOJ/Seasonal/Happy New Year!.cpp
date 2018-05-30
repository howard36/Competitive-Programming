#include <cstdio>
#include <cmath>

int main()
{
	int h, m, s;
	scanf("%d%d%d", &h, &m, &s);
	h %= 12;
	m %= 720;
	s %= 43200;
	int t = 3600 * h + 60 * m + s;
	t %= 43200;
	int H = 12 - (int)ceil(t / 3600.0);
	int M = 60 - ((int)ceil(t / 60.0) % 60);
	int S = 60 - (t % 60);
	if (M == 60)
		M = 0;
	if (S == 60)
		S = 0;
	if (H < 10)
		printf("0");
	printf("%d:", H);
	if (M < 10)
		printf("0");
	printf("%d:", M);
	if (S < 10)
		printf("0");
	printf("%d", S);
    return 0;
}