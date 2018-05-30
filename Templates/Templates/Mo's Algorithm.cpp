#include "stdafx.h"

#include <algorithm>
using namespace std;

int N, Q, blocksize;

struct query { int l; int r; int id; int ans; };

bool Mo(query a, query b) {
	if (a.l / blocksize != b.l / blocksize)
		return a.l / blocksize < b.l / blocksize;
	return a.r < b.r;
}

int main() {

	blocksize = max((int)(N / sqrt(2 * Q)), 1); //guarantees at most N*sqrt(2Q) shifts
}
