#include <cstdio>
#include <algorithm>
#define ll long long
using namespace std;

#define getchar() (*_pbuf ? *_pbuf++ : (_buf[fread_unlocked(_pbuf = _buf, 1, 16384, stdin)] = 0, *_pbuf++))
char _buf[16385], *_pbuf = _buf;

int read()
{
	int c, o = 0;
	while ((c = getchar()) < '0');
	do o = o * 10 + c - '0';
	while ((c = getchar()) >= '0');
	return o;
}

int N, K, Q;

const int MAXN = 200010;

struct node { ll max = 0, lazy = 0; };

node segtree[2 * MAXN];
int segsize[MAXN];

//apply modification to node
void apply(int i, ll p)
{
	segtree[i].max += p;
	if (i < N)
		segtree[i].lazy += p;
}

//merges two nodes into one
node merge(node a, node b)
{
	return node{
		max(a.max,b.max),
		0
	};
}

//pushes the modification down from i to its children
void push(int i)
{
	if (segtree[i].lazy != 0)
	{
		apply(i << 1, segtree[i].lazy);
		apply(i << 1 | 1, segtree[i].lazy);
		segtree[i].lazy = 0;
	}
}

//pushes all modifications on the border of the interval down, so they don't interfere with update or query
void pushDown(int i)
{
	int k;
	for (k = 0; (i >> k) > 0; k++);
	for (k--; k > 0; k--)
		push(i >> k);
}

//update node based on values of its children
void pop(int i)
{
	if (segtree[i].lazy == 0)
		segtree[i] = merge(segtree[i << 1], segtree[i << 1 | 1]);
}

//update all nodes on the border of the interval
void popUp(int i)
{
	for (i >>= 1; i > 0; i >>= 1)
		pop(i);
}

void init()
{
	for (int i = N; i < N << 1; i++)
		segsize[i] = 1;
	for (int i = N - 1; i > 0; i--)
		segsize[i] = segsize[i << 1] + segsize[i << 1 | 1];
}

void update(int L, int R, ll p)
{
	L += N;
	R += N;

	int LCopy = L;
	int RCopy = R;

	pushDown(LCopy);
	pushDown(RCopy);

	//splits interval into disjoint intervals each covered by a segtree node
	//then applies update to each node
	for (; L <= R; L = (L + 1) >> 1, R = (R - 1) >> 1)
	{
		if (L & 1)
			apply(L, p);
		if (!(R & 1))
			apply(R, p);
	}

	popUp(LCopy);
	popUp(RCopy);
}

node query(int L, int R)
{
	L += N;
	R += N;

	pushDown(L);
	pushDown(R);

	node ret;

	//splits interval into disjoint intervals each covered by a segtree node
	//then merges all nodes into ret
	//if merge is non-commutative, use retL and retR, then merge at the end
	for (; L <= R; L = (L + 1) >> 1, R = (R - 1) >> 1)
	{
		if (L & 1)
			ret = merge(ret, segtree[L]);
		if (!(R & 1))
			ret = merge(ret, segtree[R]);
	}

	return ret;
}

int main()
{
	N = read(); K = read(); Q = read();
	int a, b, c;
	for (int i = 0; i < Q; i++)
	{
	    a = read(); b = read(); c = read();
		if (a == 0)
			update(max(0, b - K + 1), b, (ll)c);
		else if (b >= N)
			printf("0\n");
		else
			printf("%lld\n", query(min(N-1,b), min(N-1,c)).max);
	}

    return 0;
}