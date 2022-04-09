#include <bits/stdc++.h>
#define rep(i,a,b) for(int i = (a); i < (b); i++)
#define rep2(i,a,b) for(int i = (b) - 1; i >= (a); i--)
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

const int MAX = 4e5 + 2, INF = 1e9;
int N, K, A[MAX], m = INF, ans = INF;
priority_queue<pi> pq, pq2;
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> N >> K;
    cinA(A, N);
    rep(i, K, N) pq.emplace(A[i], i);
    rep(i, 0, K) pq2.emplace(A[i], i);
    while(!pq2.empty()){
        auto [v, i] = pq2.top(); pq2.pop();
        while(!pq.empty() && pq.top().x > v){
            m = min(m, pq.top().y);
            pq.pop();
        }
        ans = min(ans, m - i);
    }
    cout << (ans > N ? -1 : ans);
}
