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

const int MAX = 15e5 + 1, INF = 1e7;
int N, M, A[MAX], ans = INF;
multiset<int> a;
set<int> b;


int main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> N >> M;
    rep(i, 0, N) cin >> A[i];
    rep(i, 0, N + 1) b.insert(i);
    rep(i, 0, M) {
        if(b.count(A[i])) b.erase(A[i]);
        a.insert(A[i]);
    }
    rep(i, 0, N - M + 1){
        ans = min(ans, *b.begin());
        if(i == N - M) break;
        a.erase(a.find(A[i]));
        if(a.count(A[i]) == 0){
            b.insert(A[i]);
        }
        if(b.count(A[i + M])) b.erase(A[i + M]);
        a.insert(A[i + M]);
    }
    cout << ans;
}
