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
using arr = array<int, 10>;

const int MAX = 2e5;
int N, M;
vector<int> A[10];
set<arr> ban;
map<arr, bool> vis;
arr C;
ll sum(arr& a){
    ll ret = 0;
    rep(i, 0, N) ret += A[i][a[i] - 1];
    return ret;
}
ll ansv; arr ansa;
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> N;
    rep(i, 0, N){
        cin >> C[i];
        A[i].assign(C[i], 0);
        rep(j, 0, C[i]) cin >> A[i][j];
    }
    cin >> M;
    rep(_, 0, M){
        arr tmp; tmp.fill(0);
        rep(i, 0, N) cin >> tmp[i];
        ban.insert(tmp);
    }
    priority_queue<pair<ll, arr>> Q; Q.emplace(sum(C), C); vis[C] = 1;
    while(!Q.empty()){
        auto [s, u] = Q.top(); Q.pop();
        auto pos = ban.find(u);
        if(pos != ban.end()){
            ban.erase(pos);
            rep(i, 0, N){
                if(u[i] == 1) continue;
                u[i]--;
                if(!vis[u]){
                    vis[u] = 1;
                    Q.emplace(sum(u), u);
                }
                u[i]++;
            }
        } else {
            if(s > ansv){
                ansv = s;
                ansa = u;
            }
        }
    }
    rep(i, 0, N) cout << ansa[i] << " ";
}
