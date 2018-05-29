#include <cstdio>
#define ll long long

ll S[100005], T[100005], freqS[100005][3], freqT[100005][3], psfS[100005][2], psfT[100005][2];
int a = 0, b = 0;

int queryT(ll y, ll depth);

int queryS(ll y, ll depth) {
	if (depth == 0)
		return 0;
	if (depth == 1)
		return S[y-1];
	ll lo = 0, hi = a - 1;
	while (lo < hi) {
		ll mid = (lo + hi) / 2;
		ll upto = psfS[mid][0] * freqS[depth - 1][2] + psfS[mid][1] * freqT[depth - 1][2];
		if (y <= upto)
			hi = mid;
		else
			lo = mid + 1;
	}
	if (lo != hi)
		printf("ERROR");
	ll newy;
	if (lo == 0)
		newy = y;
	else
		newy = y - (psfS[lo - 1][0] * freqS[depth - 1][2] + psfS[lo - 1][1] * freqT[depth - 1][2]);
	if (S[lo])
		return queryT(newy, depth - 1);
	else
		return queryS(newy, depth - 1);
}

int queryT(ll y, ll depth) {
	if (depth == 0)
		return 1;
	if (depth == 1)
		return T[y-1];
	ll lo = 0, hi = a - 1;
	while (lo < hi) {
		ll mid = (lo + hi) / 2;
		ll upto = psfT[mid][0] * freqS[depth - 1][2] + psfT[mid][1] * freqT[depth - 1][2];
		if (y <= upto)
			hi = mid;
		else
			lo = mid + 1;
	}
	if (lo != hi)
		printf("ERROR");
	ll newy;
	if (lo == 0)
		newy = y;
	else
		newy = y - (psfT[lo - 1][0] * freqS[depth - 1][2] + psfT[lo - 1][1] * freqT[depth - 1][2]);
	if (T[lo])
		return queryT(newy, depth - 1);
	else
		return queryS(newy, depth - 1);
}

int main()
{
	int s0 = 0, s1 = 0, t0 = 0, t1 = 0;
	char c;
	while ((c = getchar()) >= '0') {
		S[a] = c - '0';
		if (S[a]) ++s1;
		else ++s0;
		psfS[a][0] = s0, psfS[a][1] = s1;
		++a;
	}
	while ((c = getchar()) >= '0') {
		T[b] = c - '0';
		if (T[b]) ++t1;
		else ++t0;
		psfT[b][0] = t0, psfT[b][1] = t1;
		++b;
	}
	freqS[0][0] = 1; freqS[0][2] = 1, freqT[0][1] = 1, freqT[0][2] = 1;
	for (int i = 1; i < 100005; i++) {
		freqS[i][0] = s0 * freqS[i - 1][0] + t0 * freqS[i - 1][1];
		freqS[i][1] = s1 * freqS[i - 1][0] + t1 * freqS[i - 1][1];
		freqS[i][2] = freqS[i][0] + freqS[i][1];
		freqT[i][0] = s0 * freqT[i - 1][0] + t0 * freqT[i - 1][1];
		freqT[i][1] = s1 * freqT[i - 1][0] + t1 * freqT[i - 1][1];
		freqT[i][2] = freqT[i][0] + freqT[i][1];
		if (freqS[i][2] > 1e12)
			break;
	}

	int Q;
	ll x;
	scanf("%d", &Q);
	for (int i = 0; i < Q; i++) {
		scanf("%lld", &x);
		ll sum = 1, depth = 0;
		while (sum < x) { //can be replaced by binary search
			depth++;
			sum += freqS[depth][2];
		}
		ll y = x - (sum - freqS[depth][2]);
		printf("%d\n", queryS(y, depth));
	}
    return 0;
}