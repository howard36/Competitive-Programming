#include <bits/stdc++.h>
using namespace std;


//Iterative Segment Tree

const int MAXN = 500000;
int N;

struct node { int max = 0, sum = 0, lazy = 0; };

node segtree[2 * MAXN];
int segsize[MAXN];
bool modified[MAXN];

//apply modification to node
void apply(int i, int p) {
	segtree[i].max = p;
	segtree[i].sum = p * segsize[i];
	if (i < N) {
		segtree[i].lazy = p;
		modified[i] = true;
	}
}

//merges two nodes into one
node merge(node a, node b) {
	return node {
		max(a.max,b.max),
		a.sum + b.sum
	};
}

//pushes the modification down from i to its children
void push(int i) {
	if (modified[i]) {
		apply(i << 1, segtree[i].lazy);
		apply(i << 1 | 1, segtree[i].lazy);
		modified[i] = false;
	}
}

//pushes all modifications on the border of the interval down, so they don't interfere with update or query
void pushDown(int i) {
	int k;
	for (k = 0; (i >> k) > 0; k++);
	for (k--; k > 0; k--)
		push(i >> k);
}

//update node based on values of its children
void pop(int i) {
	if (modified[i]) {
		segtree[i].max = segtree[i].lazy;
		segtree[i].sum = segtree[i].lazy * segsize[i];
	}
	else
		segtree[i] = merge(segtree[i << 1], segtree[i << 1 | 1]);
}

//update all nodes on the border of the interval
void popUp(int i) {
	for (i >>= 1; i > 0; i >>= 1)
		pop(i);
}

void init() {
	int a;
	for (int i = N; i < N << 1; i++) {
		//initialize leaves of segtree from input
		scanf("%d", &a);
		segtree[i] = node{ a,a,1 };
	}
	for (int i = N - 1; i > 0; i--)
		pop(i); //initializes the rest of the nodes

	for (int i = N; i < N << 1; i++)
		segsize[i] = 1;
	for (int i = N - 1; i > 0; i--)
		segsize[i] = segsize[i << 1] + segsize[i << 1 | 1];
}

void update(int L, int R, int p) {
	L += N;
	R += N;

	int LCopy = L;
	int RCopy = R;

	pushDown(LCopy);
	pushDown(RCopy);

	//splits interval into disjoint intervals each covered by a segtree node
	//then applies update to each node
	for (; L <= R; L = (L + 1) >> 1, R = (R - 1) >> 1) {
		if (L & 1)
			apply(L, p);
		if (!(R & 1))
			apply(R, p);
	}

	popUp(LCopy);
	popUp(RCopy);
}

node query(int L, int R) {
	L += N;
	R += N;

	pushDown(L);
	pushDown(R);

	node ret;

	//splits interval into disjoint intervals each covered by a segtree node
	//then merges all nodes into ret
	//if merge is non-commutative, use retL and retR, then merge at the end
	for (; L <= R; L = (L + 1) >> 1, R = (R - 1) >> 1) {
		if (L & 1)
			ret = merge(ret, segtree[L]);
		if (!(R & 1))
			ret = merge(ret, segtree[R]);
	}

	return ret;
}





//Recursive Segment Tree

vector<int> SegmentTree;

void InitSegmentTree(int size) {
	int length = (int)pow(2.0, ceil(log((double)size) / log(2.0)) + 1);
	SegmentTree.resize(length, 0);
}

//type: 0 = index of minimum in range, 1 = index of maximum in range, 2 = sum of range
//b = beginning, e = end (inclusive)
void BuildSegmentTree(int type, int A[], int node, int b, int e) {
	if (b == e) {
		if (type == 2) SegmentTree[node] = A[b];
		else SegmentTree[node] = b;
	}
	else {
		int lIndex = 2 * node, rIndex = 2 * node + 1;
		BuildSegmentTree(type, A, lIndex, b, (b + e) / 2);
		BuildSegmentTree(type, A, rIndex, (b + e) / 2 + 1, e);

		int lContent = SegmentTree[lIndex], rContent = SegmentTree[rIndex];
		switch (type)
		{
			case 0:
				if (A[lContent] < A[rContent]) SegmentTree[node] = lContent;
				else SegmentTree[node] = rContent;
				break;
			case 1:
				if (A[lContent] > A[rContent]) SegmentTree[node] = lContent;
				else SegmentTree[node] = rContent;
				break;
			case 2:
				SegmentTree[node] = lContent + rContent;
				break;
		}
	}
}

//i = start of query range, j = end of query range (inclusive)
int SegmentTreeQuery(int type, int A[], int node, int b, int e, int i, int j)
{
	if (i > e || j < b)	return -1;					// interval does not intersect query interval
	if (b >= i && e <= j) return SegmentTree[node];	// interval is inside query interval

	int p1 = SegmentTreeQuery(type, A, 2 * node, b, (b + e) / 2, i, j);
	int p2 = SegmentTreeQuery(type, A, 2 * node + 1, (b + e) / 2 + 1, e, i, j);

	if (p1 == -1) return p2; // in case we try to access segment outside query
	if (p2 == -1) return p1;

	switch (type) {
		case 0:
			if (A[p1] < A[p2]) return p1;
			else return p2;
			break;
		case 1:
			if (A[p1] > A[p2]) return p1;
			else return p2;
			break;
		case 2:
			return p1 + p2;
			break;
	}
}

//does not update array itself
void UpdateSegmentTree(int type, int node, int b, int e, int index, int value)
{
	if (b>index || e<index) return;
	if (b == e)	{
		SegmentTree[node] = value;
		return;
	}

	int lIndex = 2 * node, rIndex = 2 * node + 1;
	UpdateSegmentTree(type, lIndex, b, (b + e) / 2, index, value);
	UpdateSegmentTree(type, rIndex, (b + e) / 2 + 1, e, index, value);

	switch (type) {
		case 0:
			SegmentTree[node] = min(SegmentTree[lIndex], SegmentTree[rIndex]);
			break;
		case 1:
			SegmentTree[node] = max(SegmentTree[lIndex], SegmentTree[rIndex]);
			break;
		case 2:
			SegmentTree[node] = SegmentTree[lIndex] + SegmentTree[rIndex];
			break;
	}
}
