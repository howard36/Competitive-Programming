#include <string>
#include <iostream>
using namespace std;

int main()
{
	string s;
	cin >> s;
	bool prepend = false;
	for (int i = s.length() - 1; i >= 0; i--)
	{
		if (s[i] > 'm')
		{
			s[i] = 'a';
			if (i == 0)
				prepend = true;
			else if (s[i - 1] != 'z')
			{
				++s[i - 1];
				break;
			}
		}
		else
		{
			s[i] = 'a';
			break;
		}
	}
	if (prepend)
		s = "a" + s;
	cout << s;
    return 0;
}