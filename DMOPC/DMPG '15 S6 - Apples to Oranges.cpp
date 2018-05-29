#include <bits/stdc++.h>
#define pid pair<int, double>
using namespace std;

unordered_map<string, int> names;
double dist[502];
vector<pid> adj[502];
int start;

bool visited[502];

void dfs(int v){
    visited[v] = true;
    for (pid p : adj[v]){
        int u = p.first;
        if (!visited[u]){
            dfs(u);
        }
    }
}

int main(){
    int N, M;
    scanf("%d%d", &N, &M);
    string s;
    for (int i = 0; i<N; i++){
        cin >> s;
        names[s] = i;
        if (s == "APPLES")
            start = i;
        dist[i] = 1e9;
    }
    dist[start] = 0;
    string s1, s2;
    double c;
    for (int i = 0; i<M; i++){
        cin >> s1 >> s2 >> c;
        adj[names[s1]].push_back(pid(names[s2], -log(c)));
    }

    for (int i = 1; i<N; i++){
        for (int v = 0; v<N; v++){
            for (pid p : adj[v]){
                int u = p.first;
                double d = p.second;
                if (dist[v] + d + 1e-5 < dist[u])
                    dist[u] = dist[v] + d;
            }
        }
    }
    int negcycle = -1;
    for (int v = 0; v<N; v++){
        for (pid p : adj[v]){
            int u = p.first;
            double d = p.second;
            if (dist[v] + d < dist[u]){
                negcycle = u;
                break;
            }
        }
        if (negcycle != -1)
            break;
    }
    if (negcycle == -1){
        printf("NAW\n");
        return 0;
    }
    dfs(negcycle);
    if (visited[start])
        printf("YA\n");
    else
        printf("NAW\n");
}