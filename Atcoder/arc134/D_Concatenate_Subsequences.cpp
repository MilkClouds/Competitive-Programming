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

const int MAX = 2e5, INF = 2e9;
int N, A[MAX], i = -1, flag;
set<pi> pq, pq2;
vector<int> ans;
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> N;
    cinA(A, N * 2);
    rep(i, 0, N){
        pq.emplace(A[i], i);
    }
    rep(i, 0, N){
        if(pq.begin()->x == A[i] && A[i] >= A[i + N]){
            pq2.emplace(A[i], A[i + N]);
        }
    }
    if(!pq2.empty()){
        auto [p, q] = *pq2.begin();
        cout << p << " " << q << endl;
        return 0;
    }
    while(!pq.empty()){
        auto [value, pos] = *pq.begin();
        if(!ans.empty() && (value > A[ans[0] + N] || (value == A[ans[0] + N] && 1 != flag))) break;
        ans.eb(pos);
        if(ans.size() >= 2)
            if(A[ans[ans.size() - 2] + N] < A[ans[ans.size() - 1] + N] && !flag) flag = 1;
            else if(A[ans[ans.size() - 2] + N] > A[ans[ans.size() - 1] + N] && !flag) flag = -1;
        rep(j, i + 1, pos + 1) pq.erase(pi(A[j], j));
        i = pos;
    }
    for(auto i: ans) cout << A[i] << " ";
    for(auto i: ans) cout << A[i + N] << " ";
}
