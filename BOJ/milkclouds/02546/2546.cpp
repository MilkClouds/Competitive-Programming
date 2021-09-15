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

const int MAX = 3e5;
int T, N, M, A[MAX], B[MAX];
int main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> T;
    while(T--) {
        cin >> N >> M;
        double a = 0, b = 0;
        int cnt = 0;
        rep(i, 0, N) cin >> A[i];
        rep(i, 0, M) cin >> B[i];
        rep(i, 0, N) a += A[i];
        rep(i, 0, M) b += B[i];
        a /= N; b /= M;
        rep(i, 0, N) {
            if(A[i] < a && A[i] > b) cnt++;
        }
        cout << cnt << "\n";
    }
}
