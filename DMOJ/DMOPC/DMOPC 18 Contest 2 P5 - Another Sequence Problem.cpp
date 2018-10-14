#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int a[3000];
ll dp[2][502][502];
ll dp2[2502][2502];

ll inv(ll a){
    ll ans = 1;
    for (int e = mod - 2; e > 0; e/=2){
        if (e%2 == 1) {
            ans = (ans * a)%mod;
        }
        a = (a*a)%mod;
    }
    return ans;
}

int main() {
    // printf("%lld\n", inv(2));
    freopen("data.txt", "r", stdin);
    ll N;
    int M, K;
    bool haszero = false;
    scanf("%lld %d %d", &N, &M, &K);
    for (int i = 0; i<K; i++){
        scanf("%d", &a[i]);
        if (a[i] == 0)
            haszero = true;
    }
    /*
    ll num = 1, den = 1;
    for (int i = 1; i<=M; i++){
        num = (num*(N%mod+i))%mod;
        den = (den*i)%mod;
    }
    ll ans = num*inv(den)%mod - N;
    printf("%lld", ((ans%mod)+mod)%mod );
*/

    sort(a, a+K);
    for (int j = 0; j <= M; j++){
        for (int m = 0; m<=M; m++){
            if (j == 0){
                dp2[j][m] = 1;
            }else{
                for (int k = 1; k<K; k++){
                    dp2[j][m] = (dp2[j][m] + dp2[j-1][m-a[k]])%mod;
                }
            }
        }
    }
    if (haszero){
        ll mult = 1, ans = 0;
        for (int j = 0; j<=M; j++){
            ans = (ans+(mult*dp2[j][M])%mod)%mod;
            mult = (mult*(N-j)%mod)*inv(j+1)%mod;
        }
        printf("%lld", ans);
    }else{
        printf("%lld", dp2[M][N]);
    }
    /*
    for (int k = 0; k<K; k++){
        for (int m = 0; m<=M; m++){
            for (int j = 0; j<=M; j++){
                dp[k&1][m][j] = 0;
                if (k == 0){
                    dp[k&1][m][j] = 1;
                }else{
                    for (int nk = 0; nk <= m/a[k]; nk++){
                        ll num = 1, den = 1;
                        for (int i = 0; i<nk; i++){
                            num = (num*(N%mod-j-i))%mod;
                            den = (den*(i+1))%mod;
                        }
                        // if (k == 1 && m == 2 && j == 0){
                        //     printf("%lld\n", (num*inv(den)));
                        // }
                        dp[k&1][m][j] += ((num*inv(den))%mod)*dp[(k-1)&1][m-nk*a[k]][j+nk]%mod;
                        dp[k&1][m][j] %= mod;
                    }
                    // printf("dp[%d][%d][%d] = %lld\n", k, m, j, dp[k][m][j]);
                }
            }
        }
    }
    printf("%lld", dp[(K-1)&1][M][0]);
    */
}


    