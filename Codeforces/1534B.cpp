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

ll solve(){
    int N;
    ll ans = 0;
    cin >> N;
    vector<int> A(N + 2, 0);
    rep(i, 0, N) cin >> A[i + 1];
    rep(i, 1, N + 1){
        if(A[i - 1] < A[i] && A[i] > A[i + 1]){
            ll tmp = max(A[i - 1], A[i + 1]);
            ans += A[i] - tmp;
            A[i] = tmp;
        }
        ans += max(0, A[i] - A[i - 1]) + max(0, A[i] - A[i + 1]);
    }
    return ans;
}
int TC;
int main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> TC;
    while(TC--) cout << solve() << "\n";
}
