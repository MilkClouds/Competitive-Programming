# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#define rep(i,a,b) for(int i = (a); i < (b); i++)
#define rep2(i,a,b) for(int i = (b) - 1; i >= (a); i--)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define pb push_back
#define x first
#define y second
using namespace std;
using ll = long long;
using tl = tuple<ll, ll, ll, ll>;
using pl = pair<ll, ll>;
using pi = pair<int, int>;
using ld = long double;

int TC, N, Q, S, d;
vector<int> vec;

int query(int a, int b, int c){
    cout << a << " " << b << " " << c << endl;
    int k;
    cin >> k;
    assert(--Q >= 0);
    return k;
}
int find(int l, int r, int lm, int rm, int v){
    int S = query(vec[l], vec[r], v);
    if(S == vec[l]) {
        if(l == lm) return l;
        if(lm + 1 == l) return l;
        int p = (l + 2 * lm) / 3, q = ceil((lm + 2 * l) / 3.0);
        return find(p, q, lm, l, v);
    }
    if(S == vec[r]) {
        if(r == rm) return r + 1;
        if(r + 1 == rm) return r + 1;
        int p = (rm + 2 * r) / 3, q = (r + 2 * rm) / 3;
        return find(p, q, r, rm, v);
    }
    if(l + 1 == r) return r;
    int p = (r + 2 * l) / 3, q = (l + 2 * r) / 3;
    return find(p, q, l, r, v);
}

int main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> TC >> N >> Q;
    rep(tc, 0, TC){
        S = query(1, 2, 3);
        if(S == 1) vec = vector<int>({2, 1, 3});
        else if(S == 2) vec = vector<int>({1, 2, 3});
        else vec = vector<int>({1, 3, 2});
        rep(i, 4, N + 1){
            int p = (vec.size() - 1) / 3, q = (vec.size() - 1) * 2 / 3;
            vec.insert(vec.begin() + find(p, q, -1, vec.size(), i), i);
        }
        rep(i, 0, N) cout << vec[i] << " " ;
        cout << endl;
        cin >> d;
    }
}
