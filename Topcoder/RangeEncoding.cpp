#include <bits/stdc++.h>
using namespace std;

class RangeEncoding {
  public:
	int minRanges(vector<int> arr) {
        int n = arr.size();
        int ans = 1;
        for (int i = 1; i<n; i++){
            if (arr[i] != arr[i-1] + 1)
                ans++;
        }
        return ans;
	}
};