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
#define x first
#define y second
using namespace std;
using ll = long long;
using tl = tuple<ll, ll, ll, ll>;
using pl = pair<ll, ll>;
using pi = pair<int, int>;
using ld = long double;

const int MAX = 1e5 + 1;
ll N, M, O, P, Q;
vector<ll> A;
struct DSU {
    // if u is root : par[u] = -(size of tree)
    // else: par[u] = parent of u
public:
    DSU() : N(0) {}
    explicit DSU(int N, vector<ll> A) : N(N), par(N, -1), A(A) {}
    int merge(int u, int v) {
        assert(0 <= u && u < N);
        assert(0 <= v && v < N);
        u = find(u); v = find(v);
        if (u == v) return u;
        if (-par[u] < -par[v]) swap(u, v);
        par[u] += par[v];
        par[v] = u;
        A[u] = A[u] + A[v];
        return u;
    }
    int war(int u, int v) {
        assert(0 <= u && u < N);
        assert(0 <= v && v < N);
        u = find(u); v = find(v);
        if (u == v) return u;
        if (-par[u] < -par[v]) swap(u, v);
        par[u] += par[v];
        par[v] = u;
        A[u] = abs(A[u] - A[v]);
        return u;
    }
    int find(int u) {
        assert(0 <= u && u < N);
        if (par[u] < 0) return u;
        return par[u] = find(par[u]);
    }
    bool same(int u, int v) {
        assert(0 <= u && u < N);
        assert(0 <= v && v < N);
        return find(u) == find(v);
    }
    int size(int u) {
        assert(0 <= u && u < N);
        return -par[find(u)];
    }
    vector<ll> query(){
        vector<int> roots(N), groups(N);
        vector<ll> ret;
        for(int i = 0; i < N; i++){
            roots[i] = find(i);
            groups[roots[i]]++;
        }
        for(int i = 0; i < N; i++){
            if(groups[i] == 0) continue;
            if(A[i] == 0) continue;
            ret.pb(A[i]);
        }
        return ret;
    }
    vector<vector<int> > groups() {
        vector<int> roots(N), groups(N);
        for (int i = 0; i < N; i++) {
            roots[i] = find(i);
            groups[roots[i]]++;
        }
        vector<vector<int> > result(N);
        for (int i = 0; i < N; i++) {
            result[i].reserve(groups[i]);
        }
        for (int i = 0; i < N; i++) {
            result[roots[i]].push_back(i);
        }
        result.erase(
            remove_if(result.begin(), result.end(), [&](const vector<int>& v) { return v.empty(); }), result.end()
        );
        return result;
    }
private:
    int N;
    vector<int> par;
    vector<ll> A;
};

int main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> N >> M;
    A.assign(N, 0);
    rep(i, 0, N) cin >> A[i];
    DSU dsu(N, A);
    rep(i, 0, M){
        cin >> O >> P >> Q; P--; Q--;
        if(O & 1){
            dsu.merge(P, Q);
        } else {
            dsu.war(P, Q);
        }
    }
    auto ret = dsu.query();
    cout << ret.size() << endl;
    sort(all(ret));
    for(auto i: ret) cout << i << " ";
}
