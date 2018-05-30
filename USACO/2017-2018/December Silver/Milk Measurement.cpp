#include <bits/stdc++.h>
#define pi pair<int,int>
using namespace std;

typedef tuple<int, int, int> record;

vector<record> records;
int display[100005], milk[100005];
unordered_map<int, int> compress;
map<int, int> counts;

int main()
{
    ifstream fin("measurement.txt");
    ofstream fout("measurement.out");
    int N, G;
    fin >> N >> G;
    int numcows = 0;
    for (int i = 0; i < N; i++) {
        record r;
        int id;
        fin >> get<0>(r) >> id >> get<2>(r);
        if (compress.count(id) == 0) {
            compress[id] = numcows;
            numcows++;
        }
        get<1>(r) = compress[id];
        records.push_back(r);
    }
    sort(records.begin(), records.end());

    int count = 0;
    for (int i = 0; i <= numcows; i++) {
        milk[i] = G;
    }
    counts[G] = numcows + 1;

    for (int i = 0; i < N; i++) {
        record r = records[i];
        int cow = get<1>(r);

        auto max1 = counts.rbegin();
        int count1 = counts[milk[cow]];
        bool notdisp1 = false, onlydisp1 = false, shareddisp1 = false;
        if (milk[cow] == max1->first) { //on display
            if (count1 == 1)
                onlydisp1 = true;
            else
                shareddisp1 = true;
        }
        else
            notdisp1 = true;

        counts[milk[cow]] -= 1;
        milk[cow] += get<2>(r);
        counts[milk[cow]] += 1;

        auto max2 = counts.rbegin();
        int count2 = counts[milk[cow]];
        bool notdisp2 = false, onlydisp2 = false, shareddisp2 = false;
        if (milk[cow] == max2->first) { //on display
            if (count2 == 1)
                onlydisp2 = true;
            else
                shareddisp2 = true;
        }
        else
            notdisp2 = true;

        if ((notdisp1^notdisp2) || (onlydisp1^onlydisp2) || (shareddisp1^shareddisp2))
            count++;
    }
    fout << count << endl;
    return 0;
}
