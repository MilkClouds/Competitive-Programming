# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
#define _CRT_SECURE_NO_WARNINGS
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

const int MAX = 50505;
ll N, K, V[MAX], P[MAX], ans, D[MAX], C[MAX];

typedef pair<ll, ll> Line;
struct LiChaoTree{
    ll f(ll j, ll i){
        return D[j] + (i - j) * (P[i] - P[j]);
    }
    struct Node{
        ll lnode, rnode, l;
        ll xl, xr;
    };
    vector<Node> nodes;
    LiChaoTree(): LiChaoTree(0, 0) {}
    LiChaoTree(ll xmin, ll xmax) {init(xmin, xmax);}
    void init(ll xmin, ll xmax){
        nodes.push_back({-1,-1,0,xmin,xmax});
    }

    void insert(ll n, ll i){
        ll xl = nodes[n].xl, xr = nodes[n].xr;
        ll xm = (xl + xr) >> 1;
        
        // 구간의 왼쪽 끝 기준으로 llow, lhigh를 결정한다
        ll llow = nodes[n].l, lhigh = i;
        if( f(llow, xl) >= f(lhigh,xl) ) swap(llow, lhigh);

        // 1. 한 직선이 다른 직선보다 항상 위에 있는 경우
        if( f(llow, xr) <= f(lhigh, xr) ){
            nodes[n].l = llow;
            return;
        }

        // 2-a. 교점이 구간의 오른쪽 절반에 존재하는 경우
        // lhigh를 저장하고 오른쪽 노드로 llow를 이용해 재귀호출
        else if( f(llow, xm) <= f(lhigh, xm) ){
            nodes[n].l = llow;
            if( nodes[n].rnode == -1 ){
                nodes[n].rnode = nodes.size();
                nodes.push_back({-1,-1,0,xm+1,xr});
            }
            insert(nodes[n].rnode, lhigh);
        }

        // 2-b. 교점이 구간의 왼쪽 절반에 존재하는 경우
        // llow를 저장하고 왼쪽 노드로 lhigh를 이용해 재귀호출
            else{
            nodes[n].l = lhigh;
            if( nodes[n].lnode == -1 ){
                nodes[n].lnode = nodes.size();
                nodes.push_back({-1,-1,0,xl,xm});
            }
            insert(nodes[n].lnode, llow);
        }
    }
    ll ans;
    void get(ll n, ll xq){
        if( n == -1 ) return;
        ll xl = nodes[n].xl, xr = nodes[n].xr;
        ll xm = (xl + xr) >> 1;
        if(f(nodes[n].l, xq) < f(ans, xq)) ans = nodes[n].l;
        if( xq < xm ) get(nodes[n].lnode, xq);
        else if(xq > xm) get(nodes[n].rnode, xq);
    }
};
pl solve(ll cost){
    LiChaoTree tree(0, N);
    rep(i, 1, N + 1){
        tree.ans = 0;
        tree.get(0, i);
        ll j = tree.ans;
        D[i] = tree.f(j, i) + cost;
        C[i] = C[j] + 1;
        tree.insert(0, i);
    }
    return {C[N], D[N]};
}
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> N >> K;
    rep(i, 0, N) cin >> V[i + 1];
    rep(i, 1, N + 1) P[i] = P[i - 1] + V[i];
    ll l = 0, r = 1e15;
    while(l < r){
        ll m = l + r >> 1;
        if(solve(m).x <= K) r = m;
        else l = m + 1;
    }
    cout << solve(r).y - K * r << endl;
}
