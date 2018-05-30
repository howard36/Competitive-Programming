#include <functional>
#include <iostream>
#include <cstdio>
#include <utility>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

bool wayToSort(pair<int,int> i, pair<int,int> j)
{
	if (i.first != j.first)
		return i.first > j.first;
	else
		return i.second < j.second;
}

pair<int, int> people[200000];
int prefixSum[200001];

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		people[i].first = a;
		people[i].second = b;
		prefixSum[a + 1] += 1;
	}
	sort(people, people + n, wayToSort);
	for (int i = 1; i <= n; i++)
		prefixSum[i] += prefixSum[i - 1];

	int bought = 0, spent = 0;
	priority_queue<int, vector<int>, std::greater<int> > costs;
	for (int i=0; i<n; i++)
	{
		costs.push(people[i].second);
		if (people[i].first > prefixSum[people[i].first] + bought)
		{
			spent += costs.top();
			costs.pop();
			++bought;
		}
	}
	printf("%d", spent);
    return 0;
}