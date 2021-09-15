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

const int MAX = 101;
int TC, N, u, v, A[MAX], ans, flag;
int main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> TC;
    while(TC--){
        cin >> N >> u >> v;
        ans = -1; flag = 0;
        rep(i, 0, N) cin >> A[i];
        rep(i, 0, N - 1) if(abs(A[i + 1] - A[i]) > 1) ans = 0;
        rep(i, 0, N) if(A[i] ^ A[0]) flag = 1;
        if(~ans) cout << ans << "\n";
        else if(flag) cout << min(u, v) << "\n";
        else cout << min(u, v) + v << "\n";
    }
}
