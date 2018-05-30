#include <bits/stdc++.h>
#define ll long long
using namespace std;


ll gcd(ll a, ll b) {
    while (b != 0) {
        ll t = b;
        b = a % b;
        a = t;
    }
    return a;
}

vector<int> mins;
long long scores[100005];

int main()
{
    ifstream fin("homework.in");
    ofstream fout("homework.out");
    int N;
    fin >> N;
    for (int i = 1; i <= N; i++)
        fin >> scores[i];
    ll sum = scores[N], min = scores[N], minavgn = 0, minavgd = 1;
    for (int k = N - 2; k >= 1; k--) {
        sum += scores[k + 1];
        if (scores[k + 1] < min)
            min = scores[k + 1];
        ll n = sum - min, d = N - k;
        ll g = gcd(n, d);
        n /= g, d /= g;
        if (n*minavgd >= d*minavgn) {
            if (n*minavgd > d*minavgn) {
                mins.clear();
                minavgn = n;
                minavgd = d;
            }
            mins.push_back(k);
        }
    }
    for (int i = mins.size() - 1; i >= 0; i--)
        fout << mins[i] << endl;

    return 0;
}
