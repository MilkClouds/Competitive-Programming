# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>
#define rep(i,a,b) for(int i = (a); i < (b); i++)
#define rep2(i,a,b) for(int i = (b) - 1; i >= (a); i--)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define pb push_back
#define eb emplace_back
#define em emplace
#define popcount __builtin_popcount
#define popcountll __builtin_popcountll
#define x first
#define y second
using namespace std;
using ll = long long;
using ld = long double;
using pi = pair<int, int>;
using ti = tuple<int, int, int>;
using pl = pair<ll, ll>;
using tl = tuple<ll, ll, ll>;

const int MAX = 2e5 + 5;
ll N, M, A[MAX], c, i, j;
struct Node{
    ll minValue, sumValue;
    Node(): Node(numeric_limits<int>::max(), 0) {}
    Node(ll m) : Node(m, m) {}
    Node(ll m, ll s): minValue(m), sumValue(s) {}
    Node operator + (Node o){
        return Node(min(minValue, o.minValue), sumValue + o.sumValue);
    }
} tree[MAX * 4];
Node init(int node, int l, int r){
    if(r - l == 1) {
        return tree[node] = Node(A[l]);
    }
    int m = l + r >> 1;
    return tree[node] = init(node * 2, l, m) + init(node * 2 + 1, m, r);
}
Node update(int node, int l, int r, int i, ll j){
    if(r <= i || i < l) return tree[node];
    if(r - l == 1){
        return tree[node] = Node(j);
    }
    int m = l + r >> 1;
    return tree[node] = update(node * 2, l, m, i, j) + update(node * 2 + 1, m, r, i, j);
}
Node query(int node, int l, int r, int s, int e){
    if(r <= s || e <= l) return Node();
    if(s <= l && r <= e) return tree[node];
    int m = l + r >> 1;
    return query(node * 2, l, m, s, e) + query(node * 2 + 1, m, r, s, e);
}

int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> N;
    rep(i, 1, N + 1) cin >> A[i];
    init(1, 0, N + 2);
    cin >> M;
    while(M--){
        cin >> c >> i >> j;
        if(c == 1){
            A[i] = j;
            update(1, 0, N + 2, i, j);
        } else {
            assert(A[i] >= j);
            int ll = 0, lr = i, rl = i, rr = N + 1;
            while(rl + 1 < rr){
                int rm = rl + rr >> 1;
                if(query(1, 0, N + 2, i, rm + 1).minValue < j) rr = rm;
                else rl = rm;
            }
            while(ll + 1 < lr){
                int lm = ll + lr >> 1;
                if(query(1, 0, N + 2, lm, i + 1).minValue < j) ll = lm;
                else lr = lm;
            }
            cout << query(1, 0, N + 2, lr, rl + 1).sumValue << "\n";
        }
    }
}
