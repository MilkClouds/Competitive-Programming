# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
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

const int MAX = 2e5, INF = 1e9;
int N, ok, ng = INF + 1;
pi A[MAX];
bool possible(int K){
    queue<pi> Q;
    int yM = 0, ym = INF;
    rep(i, 0, N){
        while(!Q.empty() && Q.front().x <= A[i].x - K){
            yM = max(yM, Q.front().y);
            ym = min(ym, Q.front().y);
            Q.pop();
        }
        Q.push(A[i]);
        if(A[i].y + K <= yM || A[i].y - K >= ym) return 1;
    }
    return 0;
}
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> N;
    rep(i, 0, N) cin >> A[i].x >> A[i].y;
    sort(A, A + N);
    while(ng - ok > 1){
        int mid = ok + ng >> 1;
        if(possible(mid)) ok = mid;
        else ng = mid;
    }
    cout << ok << endl;
}
