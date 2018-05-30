#include <cstdio>

int main()
{
	int N;
	bool vowel = false;
	char c;
	scanf("%d %c", &N, &c);
	printf("%c", c);
	for (int i = 1; i < N; i++) {
		if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y')
			vowel = true;
		scanf("%c", &c);
		if (vowel && (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y'))
			continue;
		else {
			vowel = false;
			printf("%c", c);
		}
	}
}
