#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n,m;
    cin >> n >> m;
    if (n==1 || m==1) cout << "First";
    else cout << (((n+m)&1) ? "First" : "Second");
}