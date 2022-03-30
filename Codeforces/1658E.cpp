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

const int MAX = 2003;
ll N, K, A[MAX][MAX];
pl XL = {0, MAX * 2}, YL = {-MAX, MAX};
void limit(pl P){
    XL = {max(P.x + P.y - K, XL.x), min(P.x + P.y + K, XL.y)};
    YL = {max(P.x - P.y - K, YL.x), min(P.x - P.y + K, YL.y)};
}
inline bool possible(pl P){
    return XL.x <= P.x + P.y && P.x + P.y <= XL.y && YL.x <= P.x - P.y && P.x - P.y <= YL.y;
}
priority_queue<pair<ll, pl>> pq;
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> N >> K;
    rep(i, 0, N) rep(j, 0, N) {
        cin >> A[i][j];
        pq.emplace(A[i][j], pl(i, j));
    }
    while(!pq.empty()){
        if(possible(pq.top().y)) limit(pq.top().y); pq.pop();
    }
    rep(i, 0, N) {
        rep(j, 0, N){
            if(possible(pl(i, j))) cout << "M";
            else cout << "G";
        }
        cout << "\n";
    }
}
