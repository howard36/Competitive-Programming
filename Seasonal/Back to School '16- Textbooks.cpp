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

const int MAXN = 1000000;
int N;

struct book { int l, r, w; } books[MAXN];
int uncomp[MAXN];

struct node { int max; ll sum; int size; };

node segtree[2*MAXN];
int lazy[MAXN];
bool modified[MAXN];

//apply modification to node
void apply(int i, int p)
{
	segtree[i].max = p;
	segtree[i].sum = 1LL * p * segtree[i].size;
	if (i < N)
	{
		lazy[i] = p;
		modified[i] = true;
	}
}

//merges two nodes into one
node merge(node a, node b)
{
	return node{
		max(a.max,b.max),
		a.sum + b.sum,
		a.size + b.size
	};
}

//pushes the modification down from i to its children
void push(int i)
{
	if (modified[i])
	{
		apply(i << 1, lazy[i]);
		apply(i << 1 | 1, lazy[i]);
		modified[i] = false;
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
	if (modified[i])
	{
		segtree[i].max = lazy[i];
		segtree[i].sum = 1LL * lazy[i] * segtree[i].size;
	}
	else
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
	//builds size array
	for (int i = N; i < N << 1; i++)
		segtree[i].size = uncomp[i - N + 1] - uncomp[i - N];
	for (int i = N - 1; i > 0; i--)
		segtree[i].size = segtree[i << 1].size + segtree[i << 1 | 1].size;
}

void update(int L, int R, int p)
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

	node ret = node{ 0,0LL,0 };

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
	int T, _s, l, w, p = 0;
	T = read();
	for (int i = 0; i < T; i++)
	{
		_s = read(); l = read(); w = read();
		books[i] = book{ _s,_s+l,w };
		uncomp[p++] = _s;
		uncomp[p++] = _s+l;
	}
	sort(uncomp, uncomp + p);
	N = 2 * T;
	init();

	ll shade = 0;
	for (int i = 0; i < T; i++)
	{
		book b = books[i];
		int pl = lower_bound(uncomp, uncomp + p, b.l) - uncomp;
		int pr = lower_bound(uncomp, uncomp + p, b.r) - uncomp - 1;
		node q = query(pl, pr);
		shade += 1LL * q.max * q.size - q.sum;
		shade %= 1000000007;
		update(pl, pr, q.max + b.w);
	}

	printf("%lld", shade);
    return 0;
}