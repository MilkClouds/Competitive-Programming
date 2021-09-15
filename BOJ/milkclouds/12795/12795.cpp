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

ll Q, c, a, b;

typedef pair<ll, ll> Line;
struct LiChaoTree{
    ll f(Line l, ll x){
        return l.first * x + l.second;
    }
    struct Node{
        int lnode, rnode;
        ll xl, xr;
        Line l;
    };
    vector<Node> nodes;
    LiChaoTree(): LiChaoTree(0, 0) {}
    LiChaoTree(ll xmin, ll xmax) {init(xmin, xmax);}
    void init(ll xmin, ll xmax){
        nodes.push_back({-1,-1,xmin,xmax,{0,-1e18}});
    }

    void insert(int n, Line newline){
        ll xl = nodes[n].xl, xr = nodes[n].xr;
        ll xm = (xl + xr) >> 1;
        
        // 구간의 왼쪽 끝 기준으로 llow, lhigh를 결정한다
        Line llow = nodes[n].l, lhigh = newline;
        if( f(llow, xl) >= f(lhigh,xl) ) swap(llow, lhigh);

        // 1. 한 직선이 다른 직선보다 항상 위에 있는 경우
        if( f(llow, xr) <= f(lhigh, xr) ){
            nodes[n].l = lhigh;
            return;
        }

        // 2-a. 교점이 구간의 오른쪽 절반에 존재하는 경우
        // lhigh를 저장하고 오른쪽 노드로 llow를 이용해 재귀호출
        else if( f(llow, xm) <= f(lhigh, xm) ){
            nodes[n].l = lhigh;
            if( nodes[n].rnode == -1 ){
                nodes[n].rnode = nodes.size();
                nodes.push_back({-1,-1,xm+1,xr,{0,-1e18}});
            }
            insert(nodes[n].rnode, llow);
        }

        // 2-b. 교점이 구간의 왼쪽 절반에 존재하는 경우
        // llow를 저장하고 왼쪽 노드로 lhigh를 이용해 재귀호출
        else{
            nodes[n].l = llow;
            if( nodes[n].lnode == -1 ){
                nodes[n].lnode = nodes.size();
                nodes.push_back({-1,-1,xl,xm,{0,-1e18}});
            }
            insert(nodes[n].lnode, lhigh);
        }
    }
    ll get(int n, ll xq){
        if( n == -1 ) return -1e18;
        ll xl = nodes[n].xl, xr = nodes[n].xr;
        ll xm = (xl + xr) >> 1;

        if( xq <= xm ) return max(f(nodes[n].l, xq), get(nodes[n].lnode, xq));
        else return max(f(nodes[n].l, xq), get(nodes[n].rnode, xq));
    }
};

int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> Q;
    LiChaoTree tree(-2e12, 2e12);
    while(Q--){
        cin >> c;
        if(c & 1){
            cin >> a >> b;
            tree.insert(0, {a, b});
        } else {
            cin >> a;
            cout << tree.get(0, a) << '\n';
        }
    }
}
