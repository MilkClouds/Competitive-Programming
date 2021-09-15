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

int N, A[3001][5];
bool B[3001][5];

bool possible(int k){
    vector<int> C(N, 0);
    map<int, int> chk;
    rep(i, 0, N) {
        rep(j, 0, 5) {
            C[i] = C[i] * 2 + (B[i][j] = A[i][j] >= k);
        }
        chk[C[i]]++;
    }
    rep(i, 0, 1 << 5){
        rep(j, 0, 1 << 5){
            rep(k, 0, 1 << 5){
                if((i | j | k) == 31 && chk[i] && chk[j] && chk[k]) return 1;
            }
        }
    }
    return 0;
}

int main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> N;
    rep(i, 0, N) rep(j, 0, 5) cin >> A[i][j];
    int l = 0, r = 1'000'000'005;
    while(r - l > 1){
        int m = l + r >> 1;
        if(possible(m)) l = m;
        else r = m;
    }
    cout << l << endl;
}
