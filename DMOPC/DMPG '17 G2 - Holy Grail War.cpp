#include <cstdio>
#include <algorithm>
#define ll long long
using namespace std;

const ll NINF = -1e9;
const int MAXN = 500000;
int N, Q;

struct node { ll max = NINF, l = NINF, r = NINF, sum = 0; };

node segtree[2 * MAXN];

//merges two nodes into one
node merge(node a, node b)
{
	node ret;
	ret.max = max(max(a.max, b.max), a.r + b.l);
	ret.l = max(a.l, a.sum + b.l);
	ret.r = max(b.r, b.sum + a.r);
	ret.sum = a.sum + b.sum;
	return ret;
}

//update all nodes on the border of the interval
void popUp(int i)
{
	for (i >>= 1; i > 0; i >>= 1)
		segtree[i] = merge(segtree[i << 1], segtree[i << 1 | 1]);
}

void init()
{
	ll a;
	for (int i = N; i < N << 1; i++)
	{
		//initialize leaves of segtree from input
		scanf("%lld", &a);
		segtree[i] = node{ a,a,a,a };
	}
	for (int i = N - 1; i > 0; i--)
		segtree[i] = merge(segtree[i << 1], segtree[i << 1 | 1]); //initializes the rest of the nodes
}

void update(int i, ll x)
{
	i += N;
	segtree[i] = node{ x,x,x,x };
	popUp(i);
}

ll query(int L, int R)
{
	L += N;
	R += N;

	node l = node{ NINF,NINF,NINF,0LL };
	node r = node{ NINF,NINF,NINF,0LL };

	//splits interval into disjoint intervals each covered by a segtree node
	//then merges all nodes into ret
	//if merge is non-commutative, use retL and retR, then merge at the end
	for (; L <= R; L = (L + 1) >> 1, R = (R - 1) >> 1)
	{
		if (L & 1)
			l = merge(l, segtree[L]);
		if (!(R & 1))
			r = merge(segtree[R], r);
	}

	return merge(l, r).max;
}

int main()
{
	scanf("%d %d", &N, &Q);
	init();
	char op; int a, b;
	while (Q--)
	{
		scanf(" %c %d %d", &op, &a, &b);
		if (op == 'S')
			update(a-1, (ll)b);
		else
			printf("%lld\n", query(a-1, b-1));
	}
    return 0;
}