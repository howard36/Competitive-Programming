#include <bits/stdc++.h>
using namespace std;

class EllysSki {
  public:
	int getMax(vector<int> h) {
		int n = h.size();
		vector<int> l(n), r(n);
		l[0] = 1;
		for (int i = 1; i < n; i++) {
			if (h[i] >= h[i - 1])
				l[i] = l[i - 1] + 1;
			else
				l[i] = 1;
		}
		r[n - 1] = 1;
		for (int i = n - 2; i >= 0; i--) {
			if (h[i] >= h[i + 1])
				r[i] = r[i + 1] + 1;
			else
				r[i] = 1;
		}
        int ans = 0;
        for (int i = 0; i<n; i++)
            ans = max(ans, max(l[i], r[i]));
        
        return ans;
	}
};