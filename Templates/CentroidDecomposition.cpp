#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100005];
bool added[100005]; // whether a vertex has been added to the centroid tree or not
int sz[100005], parent[100005]; // parent in the centroid tree

// calculates subtree sizes
int dfs(int v, int p) {
    sz[v] = 1;
    for (int u : adj[v]) {
        if (!added[u] && u != p) {
            sz[v] += dfs(u, v);
        }
    }
    return sz[v];
}

int getCentroid(int v, int p, int totalSize) {
    for (int u : adj[v]) {
        if (!added[u] && u != p && sz[u] > totalSize / 2) {
            return getCentroid(u, v, totalSize);
        }
    }
    return v;
}

// performs centroid decomp on the section of the tree that v is in, and returns the centroid
int decompose(int v) {
    int totalSize = dfs(v, -1);
    int centroid = getCentroid(v, -1, totalSize);
    added[centroid] = true;
    for (int u : adj[centroid]) {
        if (!added[u]) {
            int subCentroid = decompose(u);
            parent[subCentroid] = centroid;
        }
    }
    return centroid;
}