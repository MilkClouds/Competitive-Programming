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

int N;
ll ans;
pi A[2000];
map<pi, int> M;
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> N;
    rep(i, 0, N) {
        cin >> A[i].x >> A[i].y;
        M[A[i]]++;
    }
    rep(i, 0, N) rep(j, 0, N){
        if(!(A[i].x < A[j].x && A[i].y < A[j].y)) continue;
        if(M.count({min(A[i].x, A[j].x), max(A[i].y, A[j].y)}) && M.count({max(A[i].x, A[j].x), min(A[i].y, A[j].y)})) ans++;
    }
    cout << ans << endl;
}
