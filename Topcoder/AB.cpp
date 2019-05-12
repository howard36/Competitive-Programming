#include <bits/stdc++.h>
using namespace std;

class AB {
  public:
	string createString(int N, int K) {
		for (int i = 0; i < N; i++) {
			if (i * (N - i) == K) {
				string s = "";
				for (int j = 0; j < i; j++)
					s += "A";
				for (int j = 0; j < N - i; j++)
					s += "B";
				return s;
			}
		}
        return "";
	}
};