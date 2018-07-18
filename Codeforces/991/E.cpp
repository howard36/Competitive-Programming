#include <bits/stdc++.h>
#define ll long long
using namespace std;

int c[10];
ll fac[20];

int main() {
    // freopen("data.txt", "r", stdin);
    ll n;
    scanf("%lld", &n);
    // printf("%lld\n", n);
    while (n){
         c[n%10]++;
         n/=10;
    }
    fac[0] = 1;
    for (int i = 1; i<20; i++){
        fac[i] = i*fac[i-1];
    }
    ll ans = 0;
    // printf("Start");
    for (int a0 = (c[0]?1:0); a0 <= c[0]; a0++){
        for (int a1 = (c[1]?1:0); a1 <= c[1]; a1++){
            for (int a2 = (c[2]?1:0); a2 <= c[2]; a2++){
                for (int a3 = (c[3]?1:0); a3 <= c[3]; a3++){
                    for (int a4 = (c[4]?1:0); a4 <= c[4]; a4++){
                        for (int a5 = (c[5]?1:0); a5 <= c[5]; a5++){
                            for (int a6 = (c[6]?1:0); a6 <= c[6]; a6++){
                                for (int a7 = (c[7]?1:0); a7 <= c[7]; a7++){
                                    for (int a8 = (c[8]?1:0); a8 <= c[8]; a8++){
                                        for (int a9 = (c[9]?1:0); a9 <= c[9]; a9++){
                                            // printf("Test\n");
                                            int d = a0+a1+a2+a3+a4+a5+a6+a7+a8+a9;
                                            // cout << a0 << endl;
                                            // cout << (fac[a0]*fac[d-1-a0]) << endl;
                                            // ll z = (fac[d-1]/(fac[a0]*fac[d-1-a0]));
                                            // printf("%lld\n", z);
                                            // ll rest = (fac[d-a0]/(fac[a1]*fac[a2]*fac[a3]*fac[a4]*fac[a5]*fac[a6]*fac[a7]*fac[a8]*fac[a9]));
                                            // printf("%lld\n", rest);
                                            ans += (fac[d-1]/(fac[a0]*fac[d-1-a0]))*(fac[d-a0]/(fac[a1]*fac[a2]*fac[a3]*fac[a4]*fac[a5]*fac[a6]*fac[a7]*fac[a8]*fac[a9]));
                                            // cout << "Added" << endl;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    cout << ans << endl;
}
