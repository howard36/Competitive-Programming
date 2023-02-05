#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back
#define mp make_pair
#define all(v) v.begin(), v.end()
#define sz(v) (int)v.size()

#define FAST ios::sync_with_stdio(0); cin.tie(0);
#define finish(x) return cout << x << '\n', 0;
#define dbg(x) cerr << ">>> " << #x << " = " << x << "\n";
#define _ << " _ " <<

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef pair<ld,ld> pd;
typedef complex<ld> cd;

template<class T> struct node {
    T val;
    T lazy;
    int l, r;
    node* left;
    node* right;
    node(int l, int r) {
        this -> l = l;
        this -> r = r;
        this -> left = nullptr;
        this -> right = nullptr;
    }
};

template<class T> struct segtree {
    T combIdentity = 1e9;
    T comb(T l, T r) {
        return min(l,r);
    }
    T pushIdentity = 0;
    void push(node<T>* n) {
        n->val += n->lazy;
        if(n->l != n->r) {
            n->left->lazy += n->lazy;
            n->right->lazy += n->lazy;
        }
        n->lazy = pushIdentity;
    }
    
    node<T>* root;
    segtree(int SZ) {
        int ub = 1;
        while(ub < SZ) ub *= 2;
        root = new node<T>(0, ub-1);
        root->val = pushIdentity;
        root->lazy = pushIdentity;
    }
    void propagate(node<T>* n) {
        if(n->l != n->r) {
            int mid = ((n->l) + (n->r))/2;
            if(n->left == nullptr) {
                n->left = new node<T>(n->l, mid);
                n->left->val = pushIdentity;
                n->left->lazy = pushIdentity;
            }
            if(n->right == nullptr) {
                n->right = new node<T>(mid+1, n->r);
                n->right->val = pushIdentity;
                n->right->lazy = pushIdentity;
            }
        }
        push(n);
    }
    void updN(node<T>* n, int i1, int i2, T val) {
        propagate(n);
        if(i2 < n->l || i1 > n->r) return;
        if(i1 <= n->l && i2 >= n->r) {
            n->lazy = val;
            push(n);
            return;
        }
        
        updN(n->left, i1, i2, val);
        updN(n->right, i1, i2, val);
        n->val = comb(n->left->val, n->right->val);
    }
    void upd(int i1, int i2, T val) {
        updN(root, i1, i2, val);
    }
    T queryN(node<T>* n, int i1, int i2) {
        propagate(n);
        if(i2 < n->l || i1 > n->r) return combIdentity;
        if(n->l >= i1 && n->r <= i2) return n->val;
        
        T a = combIdentity;
        if(n->left != nullptr) a = comb(a, queryN(n->left, i1, i2));
        if(n->right != nullptr) a = comb(a, queryN(n->right, i1, i2));
        
        return a;
    }
    T query(int i1, int i2) {
        return queryN(root, i1, i2);
    }
};

int a[200005];

void solve() {
    int n;
    cin >> n;
    segtree<int> st(n+5);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i < n; i++) {
        st.upd(i, n+4, 1);
    }

    ll sum = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
        st.upd(0, a[i]-1, 1);
        int h = st.query(0, a[i]-1);
        // dbg(h _ st.query(0,h-1))
        if (st.query(0, h-1) >= h) {
            ans += h;
            // dbg("c1")
        } else {
            // dbg("c2")
            int lo = 0, hi = h-1;
            while (lo < hi) {
                int mid = (lo + hi)/2;
                if (st.query(0, mid) < h) hi = mid;
                else lo = mid + 1;
            }
            ans += lo;
        }
        // dbg(a[i] _ sum _ ans)
        cout << sum - ans << " ";
    }
    cout << endl;
}

int main() { FAST
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}
