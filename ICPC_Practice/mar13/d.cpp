#include <bits/stdc++.h>
using namespace std;
 
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define all(v) v.begin(), v.end()
#define sz(v) (int)v.size()
 
#define MOO(i, a, b) for(int i=a; i<b; i++)
#define M00(i, a) for(int i=0; i<a; i++)
#define MOOd(i,a,b) for(int i = (b)-1; i >= a; i--)
#define M00d(i,a) for(int i = (a)-1; i>=0; i--)
 
#define FAST ios::sync_with_stdio(0); cin.tie(0);
#define finish(x) return cout << x << '\n', 0;
#define dbg(x) cerr << ">>> " << #x << " = " << x << "\n";
#define _ << " _ " <<
 
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef pair<ld,ld> pd;
typedef complex<ld> cd;
 
const int MAX_N = 1000005;
const int MX = 40;
int n;
ll arr[MAX_N];
ll dp[MAX_N][MX];
ll val[MAX_N][MX];
 
int main() { FAST
    cin >> n;
    M00(i, n) cin >> arr[i];
    M00(i, MX) {
        if(arr[0] & (1LL<<i)) {
            dp[0][i] = 0;
            val[0][i] = arr[0];
        } else {
            dp[0][i] = -1;
        }
    }
    MOO(i, 1, n) {
        int ic = i;
        int ip = i-1;
        M00(j, MX) {
            dp[ic][j] = dp[ip][j];
            val[ic][j] = val[ip][j];
        }
        M00(j, MX) {
            if(arr[i] & (1LL<<j)) {
                M00(k, MX) {
                    if(dp[ip][k] != -1) {
                        if(dp[ip][k] + (val[ip][k] & arr[i]) >= dp[ic][j]) {
                            dp[ic][j] = dp[ip][k] + (val[ip][k] & arr[i]);
                            val[ic][j] = arr[i];
                        }

                    }
                }
            }
        }
    }
    ll res = 0;
    M00(i, MX) res = max(res, dp[n-1][i]);
    finish(res);
}
