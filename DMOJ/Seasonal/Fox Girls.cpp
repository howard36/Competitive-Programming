#include <bits/stdc++.h>
using namespace std;

int t[100005];
vector<int> adj[100005];

void check(int v){

}

int main() {
    int n;
    for (int i = 1; i<=n; i++){
        scanf("%d", &t[i]);
    }
    int x;
    for (int i = 1; i<=n; i++){
        scanf("%d", &x);
        adj[i].push_back(x);
        adj[x].push_back(i);
    }
    for (int i = 1; i<=n; i++){
        check(i);
    }
}