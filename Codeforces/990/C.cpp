#include <bits/stdc++.h>
using namespace std;

unordered_map<int, vector<int> > mymap;

int main() {
    // freopen("data.txt", "r", stdin);
    cin.tie(0);
    int n;
    scanf("%d", &n);
    string s;
    for (int i = 0; i<n; i++){
        cin >> s;
        int val = 0, minval = 1e9;
        // printf("%u\n", s.length());
        for (int j = 0; j<(int)(s.length()); j++){
            if (s[j] == '(')
                val++;
            else
                val--;
            minval = min(minval, val);
        }
        mymap[val].push_back(minval);
    }
    long long ans = 0;
    for (auto it : mymap){
        if (it.first < 0)
            continue;
        if (mymap.find(-it.first) == mymap.end())
            continue;
        else {
            sort(mymap[-it.first].begin(), mymap[-it.first].end());
            for (int i : it.second){
                if (i < 0)
                    continue;
                ans += mymap[-it.first].end() - lower_bound(mymap[-it.first].begin(), mymap[-it.first].end(), -it.first);
            }
        }
    }
    printf("%lld", ans);
}
