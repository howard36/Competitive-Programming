#include <cstdio>

int arr[1000000];


char convert(int a) {
	if (a == 0)
		return ' ';
	else if (a == 27)
		return '.';
	else if (a == 28)
		return ',';
	else if (a == 29)
		return '!';
	else if (a == 30)
		return '?';
	else
		return 'A' + a - 1;
}

int gcd(int a, int b)
{
	while (b != 0)
	{
		int t = b;
		b = a % b;
		a = t;
	}
	return a;
}

int main()
{
	int N;
	for (int abc = 0; abc < 5; abc++) {
		scanf("%d", &N);
		for (int i = 0; i < N; i++) {
			scanf("%lld", &arr[i]);
		}
		int p = arr[0];
		for (int i = 1; i < N; i++) {
			p = gcd(p, arr[i]);
		}
		for (int d = 2; d*d <= p; d++) {
			while (p%d == 0)
				p /= d;
		}
		for (int i = 0; i < N; i++) {
			arr[i] /= p;
		}
		for (int i = 0; i < N; i++) {
			printf("%c%c", convert((arr[i] / 100) % 100), convert(arr[i] % 100));
		}
		printf("\n");
	}
    return 0;
}