#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000001

vector<int> sizes, bitmasks[12];
ll dp[1025][17];

inline ll add(ll a, ll b){return (a+b)%mod;}
inline ll mult(ll a, ll b){return (a*b)%mod;}

int main() {
    int n;
    scanf("%d", &n);
    bitmasks[1].push_back(1);
    bitmasks[1].push_back(0);
    for (int i = 2; i<=11; i++){
        for (int mask : bitmasks[i-1]){
            if (mask%2 == 0)
                bitmasks[i].push_back(mask*2+1);
            bitmasks[i].push_back(mask*2);
        }
    }
    ll ans = 1;
    for (int i = 1; i<=n; i++){
        if ((i%2)*(i%3)){
            sizes.clear();
            for (int j = 0; i*(1<<j)<=n; j++){
                sizes.push_back(0);
                for (int k = i*(1<<j); k<=n; k*=3){
                    sizes[j]++;
                }
            }
            memset(dp, 0, sizeof(dp));
            for (int j = 0; j<bitmasks[sizes[0]].size(); j++)
                dp[j][0] = 1;
            int j;
            for (j = 1; i*(1<<j)<=n; j++){
                for (int k = 0; k<bitmasks[sizes[j]].size(); k++){
                    for (int l = 0; l<bitmasks[sizes[j-1]].size(); l++){
                        if ((bitmasks[sizes[j]][k] & bitmasks[sizes[j-1]][l]) == 0){
                            dp[k][j] = add(dp[k][j], dp[l][j-1]);
                        }
                    }
                }
            }
            j--;
            ll sum = 0;
            for (int k = 0; k<bitmasks[sizes[j]].size(); k++)
                sum = add(sum, dp[k][j]);
            ans = mult(ans, sum);
        }
    }
    printf("%lld", ans);
}