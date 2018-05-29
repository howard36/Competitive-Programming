#include <cstdio>
#include <cstring>
char string[100000];

int main()
{
	scanf("%s", string);
	for (int i = 0; i < strlen(string); i++) {
		char c = string[i];
		if (c == '0')
			c = 'O';
		if (c == '1')
			c = 'l';
		if (c == '3')
			c = 'E';
		if (c == '4')
			c = 'A';
		if (c == '5')
			c = 'S';
		if (c == '6')
			c = 'G';
		if (c == '8')
			c = 'B';
		if (c == '9')
			c = 'g';
		printf("%c", c);
	}
    return 0;
}