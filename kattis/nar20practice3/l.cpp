#include <bits/stdc++.h>
 
using namespace std;
 
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
 
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define PI 3.14159265358979323846

map<string, long double> m;

int main() {
    
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //getline(cin, s);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    
    
    int n;
    cin >> n;
    m["pink"]=0;

    for(int i=0;i<n;i++){
        string O, W;
        long double ex;
        cin >> O >> W >> ex;
        if(m.count(W)) m[O]=max(m[O],m[W] + logl(ex));
    }
    if(m.count("blue")) printf("%.9Lf\n", expl(min(logl(10.0), m["blue"])));
    else printf("%.9f\n", 0.0000);

    return 0;
}

