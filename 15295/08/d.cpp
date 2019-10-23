#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define cd complex<ld>

vector<cd> red, blue;

cd intersect(cd a, cd b, cd c, cd d) {
	cd num = (conj(a)*b-a*conj(b))*(c-d) - (a-b)*(conj(c)*d-c*conj(d));
	cd den = (conj(a) - conj(b))*(c-d) - (a-b)*(conj(c) - conj(d));
	return num / den;
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i<n; i++) {
		int x, y;
		char c;
		scanf("%d %d %c", &x, &y, &c);
		if (c == 'I')
			red.push_back(cd(x, y));
		else
			blue.push_back(cd(x, y));
	}
	int r = red.size(), b = blue.size();
	for (int i = 0; i<r; i++) {
		for (int j = 0; j<b; j++) {
			cd m1 = (red[i] + blue[j])/((ld)2.0);
			cd d1 = cd(0,1) * (red[i]-blue[j]);
			cd n1 = m1 + d1;
			for (int k = 0; k<r; k++) {
				for (int l = 0; l<b; l++) {
					cd m2 = (red[k] + blue[l])/((ld)2.0);
					cd d2 = cd(0,1) * (red[k]-blue[l]);
					cd n2 = m2 + d2;
					if (abs(imag(d1/d2)) < 1e-7)
						continue;
					cd c = intersect(m1, n1, m2, n2);
					ld M = 0;
					bool works = true;
					for (cd d : red)
						M = max(M, abs(c-d));
					for (cd d : blue) {
						if (abs(c-d) < M - 1e-7)
							works = false;
					}
					if (works) {
						//printf("%d %d %d %d\n", i, j, k, l);
						//cout << c << endl;
						printf("No\n");
						return 0;
					}
				}
			}
		}
	}
	printf("Yes\n");

}
