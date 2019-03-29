#include <bits/stdc++.h>
using namespace std;
#define pi pair<int, int>

pi edges[200005], queries[200005];
int ans[200005];

void solve(int l, int r, vector<int> qs){

}

int main() {
    int n, d, q;
    scanf("%d %d %d", &n, &d, &q);
    for (int i = 0; i<d; i++){
        scanf("%d %d", &edges[i].first, &edges[i].second);
    }
    for (int i = 0; i<q; i++){
        scanf("%d %d", &queries[i].first, &queries[i].second);
    }
    vector<int> qs ;
    solve(0, d-1, )
}