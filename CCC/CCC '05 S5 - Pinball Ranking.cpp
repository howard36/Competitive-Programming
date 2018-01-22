#include <cstdio>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
vector<int> BIT(100000);
vector<int> scores;
vector<int> sortedScores;
unordered_map<int, int> scoreToIndex;

int sum(int i)
{
	int ans = 0;
	while (i >= 1)
	{
		ans += BIT[i];
		i -= i&-i;
	}
	return ans;
}

void increment(int i, int inc)
{
	while (i <= BIT.size())
	{
		BIT[i] += inc;
		i += i&-i;
	}
}

int main()
{
	int t, score; double total = 0.0;
	scanf("%d", &t);
	for (int i = 0; i < t; i++)
	{
		scanf("%d", &score);
		scores.push_back(score);
		sortedScores.push_back(score);
	}
	sort(sortedScores.begin(), sortedScores.end());
	int current = -1;
	for (int i = 0; i < t; i++)
	{
		if (sortedScores[i] != current)
		{
			current = sortedScores[i];
			scoreToIndex[current] = i;
		}
	}
	int index;
	for (int i = 0; i < t; i++)
	{
		index = scoreToIndex[scores[i]] + 1;
		increment(index, 1);
		total += i - sum(index) + 2;
	}
	double avg = total / t;
	printf("%.2f", avg);
    return 0;
}