#include <bits/stdc++.h>
using namespace std;

struct node{
    int cnt=0, left=0, right=0, val=-1;
};

node trie[1500006];

map<int, int> idx;

int main() {
    freopen("data.txt", "r", stdin);
    int N, Q, a, x, nodes = 1;
    scanf("%d %d", &N, &Q);
    for (int j = 0; j<N; j++){
        scanf("%d", &a);
        if (idx.find(a) == idx.end()){
            idx[a] = j;
        }
        int v = 1;
        for (int i = 29; i>=0; i--){
            if ((a>>i)&1){
                if (trie[v].right==0){
                    nodes++;
                    trie[v].right = nodes;
                }
                v = trie[v].right;
            }
            else {
                if (trie[v].left==0){
                    nodes++;
                    trie[v].left = nodes;
                }
                v = trie[v].left;
            }
            trie[v].cnt++;
        }
        trie[v].val = a;
    }
    // printf("Trie");
    int q = 0;
    for (int i = 0; i<Q; i++){
        scanf("%d", &x);
        q^=x;
        int v = 1;
        for (int j = 29; j>=0; j--){
            if ((q>>j)&1){
                if (trie[v].right)
                    v = trie[v].right;
                else v = trie[v].left;
            }
            else {
                if (trie[v].left)
                    v = trie[v].left;
                else v = trie[v].right;
            }
        }
        printf("%d\n", idx[trie[v].val]);
    }
}