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
using tl = tuple<ll, ll, ll, ll>;
using pl = pair<ll, ll>;
using pi = pair<int, int>;
using ld = long double;

const int INF = 1e9;
const int DIR[2][4] = {{3, 2, 1, 0}, {1, 0, 3, 2}};
struct mirror{
    int r, c, type;
    mirror(): mirror(0, 0, 0){}
    mirror(int r, int c, int type): r(r), c(c), type(type){}
    bool operator < (const mirror& o) const {
        if(r != o.r) return r < o.r;
        return c < o.c;
    }
};
struct FenwickTree {
public:
    FenwickTree() : FenwickTree(0) {}
    explicit FenwickTree(int N) : N(N), tree(N + 1, 0) {}
    ll query(int i) {
        ll ret = 0;
        for (; i; i ^= i & -i)ret += tree[i];
        return ret;
    }
    void update(int i, int j, int value = 1){
        if(i > j) swap(i, j);
        upd(j, -value);
        upd(i + 1, value);
    }
    void upd(int i, int x) {
        for (; i <= N; i += i & -i)tree[i] += x;
    }
private:
    int N;
    vector<int> tree;
};
int R, C, M, N, r, c, dir, cnt;
vector<mirror> mirrors;
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    while(cin >> R >> C >> M >> N){
        cnt++;
        mirrors.clear();
        mirrors.eb(R, C + 1, 0);
        vector<int> xs{1, R}, ys{0, C + 1};
        rep(i, 0, M){
            cin >> r >> c;
            xs.eb(r); ys.pb(c);
            mirrors.eb(r, c, 0);
        }
        rep(i, 0, N){
            cin >> r >> c;
            xs.eb(r); ys.pb(c);
            mirrors.eb(r, c, 1);
        }
        sort(all(xs)); sort(all(ys));
        xs.erase(unique(all(xs)), xs.end()); ys.erase(unique(all(ys)), ys.end());
        map<int, int> xc, yc;
        rep(i, 0, xs.size()) xc[xs[i]] = i;
        rep(i, 0, ys.size()) yc[ys[i]] = i;
        vector<vector<mirror>> mirrors_by_r(xs.size());
        vector<vector<mirror>> mirrors_by_c(ys.size());
        for(auto& i: mirrors){
            i.r = xc[i.r];
            i.c = yc[i.c];
            mirrors_by_r[i.r].eb(i);
            mirrors_by_c[i.c].eb(i);
        }
        rep(i, 0, xs.size()) sort(all(mirrors_by_r[i]));
        rep(i, 0, ys.size()) sort(all(mirrors_by_c[i]));
        bool flag = 0;
        vector<pi> a, b;
        function<void(int, int, int)> dfs = [&](int i, int j, int dir){
            //cout << i << " " << j << " " << dir << endl;
            if(i == xs.size() - 1 && j == ys.size() - 1 && dir == 3) {
                flag = 1;
                return;
            }
            if(dir == 0) {
                auto pos = upper_bound(all(mirrors_by_r[i]), mirror(i, j, 0));
                if(pos != mirrors_by_r[i].end()){
                    b.eb(j, pos -> c);
                    dfs(pos -> r, pos -> c, DIR[pos -> type][dir]);
                } else b.eb(j, C + 1);
            }
            else if(dir == 1){
                auto pos = upper_bound(all(mirrors_by_c[j]), mirror(i, j, 0));
                if(pos != mirrors_by_c[j].end()){
                    b.eb(i, pos -> r);
                    dfs(pos -> r, pos -> c, DIR[pos -> type][dir]);
                } else b.eb(i, R + 1);
            }
            else if(dir == 2){
                auto pos = lower_bound(all(mirrors_by_r[i]), mirror(i, j, 0));
                if(pos != mirrors_by_r[i].begin()){
                    pos--;
                    b.eb(pos -> c, j);
                    dfs(pos -> r, pos -> c, DIR[pos -> type][dir]);
                } else b.eb(j, C + 1);
            }
            else{
                auto pos = lower_bound(all(mirrors_by_c[j]), mirror(i, j, 0));
                if(pos != mirrors_by_c[j].begin()){
                    pos--;
                    b.eb(pos -> r, i);
                    dfs(pos -> r, pos -> c, DIR[pos -> type][dir]);
                } else b.eb(i, R + 1);
            }
        };
        dfs(0, 0, 0);
        //cout << endl;
        a = b;
        b.clear();
        if(flag){
            cout << "Case " << cnt << ": 0\n";
            continue;
        }
        dfs(xs.size() - 1, ys.size() - 1, 2);
        //cout << endl;
        //cout << a.size() << " " << b.size()<<endl;
        vector<pair<int, pi>> ax, ay;
        set<pair<pi, int>> bx, by;
        rep(i, 0, a.size() - 1){
            if(a[i].x == a[i + 1].x) ax.pb({a[i].x, {a[i].y, a[i + 1].y}});
            else ay.pb({a[i].y, {a[i].x, a[i + 1].x}});
        }
        sort(all(ax));
        sort(all(ay));
        rep(i, 0, b.size() - 1){
            if(b[i].x == b[i + 1].x) bx.insert({{b[i].y, b[i + 1].y}, b[i].x});
            else by.insert({{b[i].x, b[i + 1].x}, b[i].y});
        }
        ll ans = 0; pi anst = {INF, INF};

        int l = 0, r = 0;
        FenwickTree tree(C + 1);
        while(!by.empty()){
            pi PI; int H;
            tie(PI, H) = *by.begin(); by.erase(by.begin());
            while(ax[r].x <= PI.y){
                tree.update(ax[r].y.x, ax[r].y.y);
                r++;
            }
            while(r > 0 && ax[r - 1].x > PI.y){
                r--;
                tree.update(ax[r].y.x, ax[r].y.y, -1);
            }
            while(ax[l].x < PI.x){
                tree.update(ax[l].y.x, ax[l].y.y, -1);
                l++;
            }
            while(l > 0 && ax[l - 1].x > PI.x){
                l--;
                tree.update(ax[l].y.x, ax[l].y.y);
            }
            ans += tree.query(H) - tree.query(H - 1);
        }
        if(ans == 0) {
            cout << "Case " << cnt << ": impossible\n";
            continue;
        }
        cout << "Case " << cnt << ": " << ans << " " << anst.x << " " << anst.y << "\n";
    }
}
