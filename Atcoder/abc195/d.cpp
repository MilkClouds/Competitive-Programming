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

int N, M, Q, X[51], l, r;
pi A[51], Y[51];

int query(){
    int ret = 0;
    vector<bool> chk(M, 0);
    rep(i, 0, N){
        rep(j, 0, M){
            if((l - 1 <= Y[j].y && Y[j].y < r) || A[i].y > Y[j].x || chk[j]) continue;
            chk[j] = 1;
            ret += A[i].x;
            break;
        }
    }
    return ret;
}

int main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> N >> M >> Q;
    rep(i, 0, N) {
        cin >> A[i].y >> A[i].x;
    }
    sort(A, A + N, greater<pi>());
    rep(i, 0, M) {
        cin >> X[i];
        Y[i] = {X[i], i};
    }
    sort(Y, Y + M);
    while(Q--){
        cin >> l >> r;
        cout << query() << "\n";
    }
}
