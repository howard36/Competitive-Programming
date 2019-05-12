#include <bits/stdc++.h>
using namespace std;

int a[100005], f[100005], ff[100005];
multiset<int> s;

bool check(int i){
    // if (i == 6 || i == 7){
    //     printf("\n\ni = %d", i);
    //     for (int j = 0; j<6; j++)
    //         printf("f[%d] = %d\n", j, f[j]);
    // }
    int m = *(s.rbegin());
    if (ff[m] == 1 && ff[m-1]*(m-1)+m == i)
        return true;
    if (ff[m]*m == i-1)
        return true;
    if (m == 1 && ff[m] == i)
        return true;
    return false;
}

int main() {
	int n;
	scanf("%d", &n);
    for (int i = 0; i<n; i++){
        scanf("%d", &a[i]);
        f[a[i]]++;
    }
    int m = 0;
    for (int i = 0; i<100005; i++){
        ff[f[i]]++;
    }
    for (int i = 0; i<100005; i++){
        s.insert(f[i]);
    }
    for (int i = n-1; i>=0; i--){
        if (check(i+1)){
            printf("%d", i+1);
            return 0;
		}
		ff[f[a[i]]]--;
        s.erase(s.find(f[a[i]]));
        f[a[i]]--;
        ff[f[a[i]]]++;
        s.insert(f[a[i]]);
    }
}