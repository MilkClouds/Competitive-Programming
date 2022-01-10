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

const int MAX = 1e6;
int N, A[MAX], B[MAX], cnt, ans;
set<pi> pq;
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> N; cinA(A, N); cinA(B, N);
    rep(i, 0, N) pq.emplace(A[i], i);
    rep(i, 0, N) cnt += A[i] == B[i];
    ans |= cnt == N;
    rep2(i, 1, N){
        auto [value, pos] = *pq.rbegin(); pq.erase(pi(value, pos));
        if(pos == i) continue;
        pq.erase(pi(A[i], i));
        pq.insert(pi(A[i], pos));
        if(A[i] == B[i]) cnt--;
        if(A[pos] == B[pos]) cnt--;
        if(A[pos] == B[i]) cnt++;
        if(A[i] == B[pos]) cnt++;
        ans |= cnt == N;
        swap(A[i], A[pos]);
    }
    cout << ans << endl;
}
