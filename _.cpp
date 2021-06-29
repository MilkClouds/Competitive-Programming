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

const int MAX = 1e5 + 10;
const ll INF = 6e18;
int N, K;
ll A[MAX], dp[MAX][205], S[MAX], pre[MAX][205];

typedef pair<ll, ll> Line;
struct LiChaoTree{
    ll f(ll j, ll i){
        return dp[j][num] + (S[N] - S[j]) * (S[N] - S[i]);
    }
    struct Node{
        ll lnode, rnode, l;
        ll xl, xr;
    };
    vector<Node> nodes;
    ll num;
    LiChaoTree(): LiChaoTree(0, 0) {}
    LiChaoTree(ll xmin, ll xmax) {init(xmin, xmax, 0);}
    void init(ll xmin, ll xmax, ll n) {
        num = n;
        nodes.push_back({-1,-1,N,xmin,xmax});
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
                nodes.push_back({-1,-1,N,xm+1,xr});
            }
            insert(nodes[n].rnode, lhigh);
        }

        // 2-b. 교점이 구간의 왼쪽 절반에 존재하는 경우
        // llow를 저장하고 왼쪽 노드로 lhigh를 이용해 재귀호출
            else{
            nodes[n].l = lhigh;
            if( nodes[n].lnode == -1 ){
                nodes[n].lnode = nodes.size();
                nodes.push_back({-1,-1,N,xl,xm});
            }
            insert(nodes[n].lnode, llow);
        }
    }
    ll ans;
    ll get(ll n, ll xq){
        if( n == -1 ) return INF;
        ll xl = nodes[n].xl, xr = nodes[n].xr;
        ll xm = (xl + xr) >> 1;
        if(f(nodes[n].l, xq) < f(ans, xq)){
            ans = nodes[n].l;
        }
        if( xq < xm ) return min(f(nodes[n].l, xq), get(nodes[n].lnode, xq));
        else if(xq > xm) return min(f(nodes[n].l, xq), get(nodes[n].rnode, xq));
        return f(nodes[n].l, xq);
    }
};

LiChaoTree tree[205];
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> N >> K;
    rep(i, 0, N) cin >> A[i];
    rep(i, 0, N) S[i + 1] = S[i] + A[i];
    rep(i, 0, K + 1) tree[i].init(0, N, i);
    tree[0].insert(0, N);
    tree[3]
    rep2(i, 0, N) rep2(j, 0, K){
        tree[j].ans = N;
        dp[i][j + 1] = tree[j].get(0, i);
        cout << i << " " << j + 1 << " " << dp[i][j + 1] << endl;
        pre[i][j + 1] = tree[j].ans;
        tree[j + 1].insert(0, i);        
    }
    rep(i, 0, N) {rep(j, 0, K + 1) cout << dp[i][j] << " "; cout << endl;}
    int i = 0, j = K;
    cout << tree[K].get(0, 0) << endl;
    while(j){
        cout << i << " ";
        i = pre[i][j--];
    }
    cout << endl;
}
