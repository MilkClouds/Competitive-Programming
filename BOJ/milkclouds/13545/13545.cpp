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

const int MAX = 1e5 + 10;
int N, SZ, M, A[MAX], S[MAX], ans[MAX], cnt[MAX], bucket[MAX], bias;
struct ABC{
    int x, y, i, p;
    bool operator < (const ABC& o) const {
        return pi(p, y) < pi(o.p, o.y);
    }
} Q[MAX];
list<int> SS[MAX];
inline int get(int i){
    return SS[i].back() - SS[i].front();
}
void edit(int i, int j){
    if(SS[S[i]].size() < 2) return;
    int diff = get(S[i]);
    cnt[diff] += j;
    bucket[diff / SZ] += j;
}
void insert(int i){
    edit(i, -1);
    if(SS[S[i]].empty() || SS[S[i]].back() < i) SS[S[i]].push_back(i);
    else SS[S[i]].push_front(i);
    edit(i, 1);
}
void remove(int i){
    edit(i, -1);
    if(SS[S[i]].back() == i) SS[S[i]].pop_back();
    else SS[S[i]].pop_front();
    edit(i, 1);
}
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> N;
    SZ = sqrt(N);
    rep(i, 1, N + 1) cin >> A[i];
    rep(i, 1, N + 1) S[i] = S[i - 1] + A[i], bias = min(bias, S[i]);
    rep(i, 0, N + 1) S[i] -= bias;
    cin >> M;
    rep(i, 0, M){
        Q[i].i = i;
        cin >> Q[i].x >> Q[i].y; Q[i].x--;
        Q[i].p = Q[i].x / SZ;
    }
    sort(Q, Q + M);
    cnt[0] = bucket[0] = 1;
    rep(i, Q[0].x, Q[0].y + 1) insert(i);
    int l = Q[0].x, r = Q[0].y;
    rep(i, 0, M){
        while(r < Q[i].y){
            insert(++r);
        }
        while(Q[i].x < l){
            insert(--l);
        }
        while(Q[i].y < r){
            remove(r--);
        }
        while(l < Q[i].x){
            remove(l++);
        }
        int j = N / SZ;
        while(bucket[j] == 0) j--;
        j = min(N, (j + 1) * SZ);
        while(cnt[j] == 0) j--;
        ans[Q[i].i] = j;
    }
    rep(i, 0, M) cout << ans[i] << "\n";
}

