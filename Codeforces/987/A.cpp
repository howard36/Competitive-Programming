#include <bits/stdc++.h>
using namespace std;

string names[6];
map<string, int> mymap;
int exists[6];

int main(){
    // freopen("data.txt", "r", stdin);

    names[0] = "Power";
    names[1] = "Time";
    names[2] = "Space";
    names[3] = "Soul";
    names[4] = "Reality";
    names[5] = "Mind";
    mymap["purple"] = 0;
    mymap["green"] = 1;
    mymap["blue"] = 2;
    mymap["orange"] = 3;
    mymap["red"] = 4;
    mymap["yellow"] = 5;
    int n;
    cin >> n;
    string s;
    for (int i = 0; i<n; i++){
        cin >> s;
        exists[mymap[s]] = 1;
    }
    printf("%d\n", 6-n);
    for (int i = 0; i<6; i++){
        if (!exists[i])
            cout << names[i] << endl;
    }
}
