#include <string>
#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#define pi pair<int,int>
#define mp make_pair
using namespace std;

unordered_map<string, int> energy;
vector<pi> food;

bool comp(pi x, pi y)
{
	if (x.first != y.first)
		return x.first < y.first;
	else
		return x.second > y.second;
}

int main()
{
	int t, n, e, d;
	string s;
	cin >> t;
	while (t--)
	{
		cin >> s >> e;
		energy[s] = e;
	}
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> s >> d;
		food.push_back(mp(d, energy[s]));
	}
	food.push_back(mp(0, 0));
	sort(food.begin(), food.end(), comp);

	int i = 0, curEnergy = 0;
	while (i < n && max(curEnergy,0) >= food[i+1].first - food[i].first)
	{
		curEnergy -= food[i+1].first - food[i].first;
		curEnergy += food[i+1].second;
		++i;
	}
	cout << i;
    return 0;
}