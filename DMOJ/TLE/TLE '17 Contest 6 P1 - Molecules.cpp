#include <cstdio>
#include <algorithm>
using namespace std;

int freq[30];

int main()
{
	int L; char c;
	scanf("%d", &L);
	for (int i = 0; i < L; i++) {
		scanf(" %c", &c);
		freq[c - 'a']++;
	}
	sort(freq, freq + 26);
	if (freq[0] * 2 > L || L % 2 == 1)
		printf("No");
	else
		printf("Yes");
    return 0;
}