#include <bits/stdc++.h>
using namespace std;
#define pi pair<int, int>
#define ll long long

pi visitors[4003];
int pos[20];
int n, m;

ll f(){
    int cur = 0;
    ll ans = 0;
    for (int i = 0; i<n; i++){
        while (cur < m-1 && visitors[i].first > (visitors[pos[cur]].first + visitors[pos[cur+1]].first)/2){
            cur++;
        }
        ans += 1LL*abs(visitors[i].first - visitors[pos[cur]].first)*visitors[i].second;
    }
    return ans;
}

int main() {
    for (int t = 0; t<10; t++){
        scanf("%d %d", &n, &m);
        for (int i = 0; i<n; i++){
            scanf("%d %d", &visitors[i].first, &visitors[i].second);
        }
        sort(visitors, visitors+n);
        for (int i = 0; i<m; i++){
            pos[i] = n*i/m;
        }
        ll F = f();
        bool decreasing = true;
        while (decreasing){
            decreasing = false;
            for (int i = 0; i<m; i++){
                if (pos[i] > 0){
                    pos[i]--;
                    ll newF = f();
                    if (newF < F) {
                        F = newF;
                        decreasing = true;
                    } else {
                        pos[i]++;
                    }
                }
                if (pos[i] < n-1){
                    pos[i]++;
                    ll newF = f();
                    if (newF < F) {
                        F = newF;
                        decreasing = true;
                    }else{
                        pos[i]--;
                    }
                }
            }
        }
        for (int i = 0; i<m; i++){
            printf("%d ", pos[i]);
        }
        printf("%lld\n", F);
    }
}