#include <bits/stdc++.h>
using namespace std;

int type[1000006], adj[1000006][2], val[1000006], dep[1000006];

void dfs(int v){
    if (v == 0 || type[v] == 4)
        return;
    dfs(adj[v][0]);
    dfs(adj[v][1]);
    if (type[v] == 0){
        val[v] = val[adj[v][0]] & val[adj[v][1]];
    }
    if (type[v] == 1){
        val[v] = val[adj[v][0]] | val[adj[v][1]];
    }
    if (type[v] == 2){
        val[v] = val[adj[v][0]] ^ val[adj[v][1]];
    }
    if (type[v] == 3){
        val[v] = !val[adj[v][0]];
    }
}

void dfs2(int v){
    if (v == 0 || !dep[v])
        return;
    if (type[v] == 0){
        if (val[adj[v][0]] == 0 && val[adj[v][1]] == 0){
            
        }
        if (val[adj[v][0]] == 0 && val[adj[v][1]] == 1){
            dep[adj[v][0]] = 1;
        }
        if (val[adj[v][0]] == 1 && val[adj[v][1]] == 0){
            dep[adj[v][1]] = 1;
        }
        if (val[adj[v][0]] == 1 && val[adj[v][1]] == 1){
            dep[adj[v][0]] = 1;
            dep[adj[v][1]] = 1;
        }
    }
    if (type[v] == 1){
        if (val[adj[v][0]] == 0 && val[adj[v][1]] == 0){
            dep[adj[v][0]] = 1;
            dep[adj[v][1]] = 1;
        }
        if (val[adj[v][0]] == 0 && val[adj[v][1]] == 1){
            dep[adj[v][1]] = 1;
        }
        if (val[adj[v][0]] == 1 && val[adj[v][1]] == 0){
            dep[adj[v][0]] = 1;
        }
        if (val[adj[v][0]] == 1 && val[adj[v][1]] == 1){
            
        }
    }
    if (type[v] == 2){
        dep[adj[v][0]] = 1;
        dep[adj[v][1]] = 1;
    }
    if (type[v] == 3){
        dep[adj[v][0]] = 1;
    }
    if (type[v] == 4){
        return;
    }
    dfs2(adj[v][0]);
    dfs2(adj[v][1]);
}

int main() {
    // freopen("data.txt", "r", stdin);
    cin.tie(0);
    int n;
    cin >> n;
    string s;
    for (int i = 1; i<=n; i++){
        cin >> s;
        if (s == "AND"){
            type[i] = 0;
            cin >> adj[i][0] >> adj[i][1];
        }
        if (s == "OR"){
            type[i] = 1;
            cin >> adj[i][0] >> adj[i][1];
        }
        if (s == "XOR"){
            type[i] = 2;
            cin >> adj[i][0] >> adj[i][1];
        }
        if (s == "NOT"){
            type[i] = 3;
            cin >> adj[i][0];
        }
        if (s == "IN"){
            type[i] = 4;
            cin >> val[i];
        }
    }
    dfs(1);
    dep[1] = 1;
    dfs2(1);
    for (int i = 1; i<=n; i++){
        if (type[i] == 4){
            printf("%d", val[1]^dep[i]);
        }
    }
    printf("\n");
}