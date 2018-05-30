#include <bits/stdc++.h>
using namespace std;

int nxt[100005], cycle[100005];


void search(int cur) {
    unordered_set<int> visited;
    while (cycle[cur] == 0) {
        if (visited.count(cur))
            cycle[cur] = 1;
        else
            visited.insert(cur);
        cur = nxt[cur];
    }
}

int main()
{
    ifstream fin("shuffle.in");
    ofstream fout("shuffle.out");
    int N;
    fin >> N;
    for (int i = 1; i <= N; i++)
        fin >> nxt[i];
    for (int i = 1; i <= N; i++)
        search(i);
    int count = 0;
    for (int i = 1; i <= N; i++)
        if (cycle[i])
            count++;
    fout << count << endl;
    return 0;
}
