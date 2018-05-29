#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
using namespace std;

int parent[1003];
vector<string> names;
vector<int> adj[1003];

int num(string s) {
	for (int i = 0; i < names.size(); i++) {
		if (names[i] == s)
			return i;
	}
	names.push_back(s);
	return names.size() - 1;
}

int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < 1003; i++)
		parent[i] = -1;
	string mother, daughter;
	for (int i = 0; i < N; i++) {
		cin >> mother >> daughter;
		int m = num(mother);
		int d = num(daughter);
		parent[d] = m;
		adj[m].push_back(d);
	}
	for (int i = 0; i < 10; i++) {
		string name;
		cin >> name;
		int d = num(name);
		int m = parent[d];
		int grand = parent[m];
		int cousins = 0;
		for (int i : adj[grand]) {
			cousins += adj[i].size();
		}
		printf("Cousins: %d, Sisters: %d\n", cousins - adj[m].size(), adj[m].size() - 1);
	}
    return 0;
}