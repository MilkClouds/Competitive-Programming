#include <bits/stdc++.h>
#define rep(i,a,b) for(ll i = (a); i < (b); i++)
#define rep2(i,a,b) for(ll i = (b) - 1; i >= (a); i--)
#define cinA(A, N) rep(i, 0, N) cin >> A[i];
#define coutA(A, N) rep(i, 0, N) cout << A[i] << " ";
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define eb emplace_back
#define popcount __builtin_popcount
#define popcountll __builtin_popcountll
#define x first
#define y second
using namespace std;
using ll = long long;
using ull = uint64_t;
using ld = long double;
using pi = pair<int, int>;
using ti = tuple<int, int, int>;
using pl = pair<ll, ll>;
using tl = tuple<ll, ll, ll>;

const int MAX = 1e5 + 11;
int N, C, X[MAX], P[MAX];
bool flag;
set<int> S;
pi A[MAX];
void insert(int i){
    P[i]++;
    if(P[i] < A[i].x) S.insert(i);
    else if(P[i] <= A[i].y) {S.erase(i);}
    else flag = 1;
}
void solve(){
    cin >> N >> C;
    rep(i, 1, C + 1) cin >> A[i].x >> A[i].y;
    cinA(X, N);
    ll ans = 0;
    rep(i, 0, N){
        flag = 0;
        S.clear();
        fill(P, P + C + 1, 0);
        insert(X[i]); insert(X[(i + 1) % N]);
        if(!flag && S.empty()) ans++;
        rep(j, i + 2, i + N - 1){
            if(flag) break;
            insert(X[j % N]);
            if(!flag && S.empty()) ans++;
        }
    }
    cout << ans << "\n";
}

int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    int TC;
    cin >> TC;
    rep(tc, 0, TC){
        cout << "Case #" << tc + 1 << ": "; solve();
    }
}

