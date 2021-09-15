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

int TC, N, K, cnt;
pi A[202];
inline bool intersect(pi a, pi b){
    if(a.x < b.x && b.y < a.y) return 0;
    swap(a, b);
    if(a.x < b.x && b.y < a.y) return 0;
    return !(a.y < b.x || b.y < a.x);
}
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> TC;
    while(TC--){
        cin >> N >> K;
        set<int> S;
        rep(i, 0, 2 * N) S.insert(i + 1);
        rep(i, 0, K){
            cin >> A[i].x >> A[i].y;
            if(A[i].x > A[i].y) swap(A[i].x, A[i].y);
            S.erase(A[i].x);
            S.erase(A[i].y);
        }
        cnt = 0;
        rep(i, 0, K) rep(j, i + 1, K) {
            cnt += intersect(A[i], A[j]);
        }
        rep(i, 0, K){
            int left = 0, right = 0;
            for(auto j: S){
                if(A[i].x < j && A[i].y > j) left++;
                else right++;
            }
            cnt += min(left, right);
        }
        cnt += (N - K) * (N - K - 1) / 2;
        cout << cnt << "\n";
    }
}
