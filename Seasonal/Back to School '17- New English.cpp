#include <iostream>
#include <cstdio>
#include <tuple>
#include <algorithm>
#include <vector>
using namespace std;
#define ti3 tuple<int,int,int>
#define pi pair<int,int>

vector<ti3> requests;
int word[100001], letterCount[26], lastRequest[26];
char c;
int n, m, x, j;

bool comp(ti3 i, ti3 j) { return get<2>(i) < get<2>(j); }

int main()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> c >> x >> j;
		requests.push_back(make_tuple((int)c - (int)'a', x, j));
	}
	sort(requests.begin(), requests.end(), comp);
	for (int i = 0; i < n; i++)
		word[i] = -1;

	bool possible = true;
	for (ti3 request : requests)
	{
		lastRequest[get<0>(request)] = get<2>(request);
		int amountToAdd = get<1>(request) - letterCount[get<0>(request)];
		int added = 0;
		int i = get<2>(request) - 1;
		for (; i > lastRequest[get<0>(request)] && added < amountToAdd; i--)
		{
			if (word[i] == -1)
			{
				word[i] = get<0>(request);
				++added;
			}
		}
		if (i == lastRequest[get<0>(request)])
		{
			possible = false;
			break;
		}
		letterCount[get<0>(request)] += added;
	}

	if (possible)
	{
		int pos = 0;
		while (word[pos] != -1)
			++pos;
		if (pos != n)
		{
			int letter = -1;
			for (int i = 0; i < 26; i++)
				if (lastRequest[i] <= pos)
					letter = i;
			if (letter == -1)
			{
				cout << -1;
				return 0;
			}
			else
			{
				for (int i = pos; i < n; i++)
					if (word[i] == -1)
						word[i] = letter;
			}
		}
		for (int i = 0; i < n; i++)
			cout << (char)(word[i] + (int)'a');
	}
	else
		cout << -1;
    return 0;
}