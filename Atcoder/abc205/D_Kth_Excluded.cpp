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

const int MAX = 1e5;
const ll INF = 6e18;
int N, Q;
ll A[MAX], K;
int main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> N >> Q;
    rep(i, 0, N) cin >> A[i];
    sort(A, A + N);
    rep(i, 0, Q){
        cin >> K;
        ll l = 0, r = INF;
        while(l + 1 < r){
            ll m = l + r >> 1;
            ll tmp = m - (upper_bound(A, A + N, m) - A);
            if(tmp < K) l = m;
            else r = m;
        }
        cout << r << "\n";
    }
}
