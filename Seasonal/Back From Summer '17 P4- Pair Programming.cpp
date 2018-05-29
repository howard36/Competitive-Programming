#include <iostream>
#include <string>
#define pi pair<int,int>
#define x first
#define y second
#define mp make_pair
#define MIN(a,b) (a<b)?a:b
#define MAX(a,b) (a>b)?a:b
using namespace std;

int sure[100001]; //-1 for unsure, 0 for false, 1 for true
pi dependent[100001]; //the '?' line it depends on, and whether it is the same
pi minmax[100001]; //errors when true, errors when false
int N;

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(0);
	cin >> N;
	char c; int v; string s;
	for (int line = 1; line <= N; line++)
	{
		cin >> c;
		if (c == 'C')
		{
			cin >> s;
			if (s == "AC")
				sure[line] = 1;
			else if (s == "WA")
				sure[line] = 0;
			else
			{
				sure[line] = -1;
				dependent[line] = mp(line, 1);
				minmax[line].y = 1;
			}
		}
		else
		{
			cin >> v >> s;
			if (s == "?")
			{
				sure[line] = -1;
				dependent[line] = mp(line, 1);
				minmax[line].y = 1;
			}
			else
			{
				if (s == "AC")
				{
					dependent[line].y = 1;
					sure[line] = sure[v];
				}
				else
				{
					dependent[line].y = 0;
					if (sure[v] == -1)
						sure[line] = -1;
					else
						sure[line] = sure[v] ^ 1;
				}
				if (sure[line] == -1)
				{
					dependent[line].x = dependent[v].x;
					dependent[line].y ^= dependent[v].y ^ 1;
					if (dependent[line].y == 1)
						minmax[dependent[line].x].y++;
					else
						minmax[dependent[line].x].x++;
				}
			}
		}
	}

	int minErrors = 0, maxErrors = 0;
	for (int line = 1; line <= N; line++)
	{
		if (sure[line] == -1)
		{
			if (dependent[line].x == line)
			{
				minErrors += MIN(minmax[line].x, minmax[line].y);
				maxErrors += MAX(minmax[line].x, minmax[line].y);
			}
		}
		else if (sure[line] == 0)
		{
			++minErrors;
			++maxErrors;
		}
	}
	cout << minErrors << ' ' << maxErrors;
    return 0;
}