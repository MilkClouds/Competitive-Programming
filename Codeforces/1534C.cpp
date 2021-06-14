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

const int MOD = 1e9 + 7;

template<class T> struct mi {
	T val;
	mi() { val = 0; }
	mi(const ll& v) {
		val = (-MOD <= v && v <= MOD) ? v : v % MOD;
		if (val < 0) val += MOD;
	}
	mi operator + (const mi& m) {
		T tmp = (val + m.val) % MOD;
		return tmp + (tmp < 0 ? MOD : 0);
	}
	mi operator - (const mi& m) {
		T tmp = (val - m.val) % MOD;
		return tmp + (tmp < 0 ? MOD : 0);
	}
	mi operator * (const mi& m) {
		T tmp = (val * m.val) % MOD;
		return tmp;
	}
	mi& operator += (const mi& m) {
		if ((val += m.val) >= MOD) val -= MOD;
		return *this;
	}
	mi& operator -= (const mi& m) {
		if ((val -= m.val) < 0) val += MOD;
		return *this;
	}
	mi& operator *= (const mi& m) {
		val = (val * m.val) % MOD;
		return *this;
	}
};
struct DSU {
    // if u is root : par[u] = -(size of tree)
    // else: par[u] = parent of u
public:
    int grps;
    DSU() : N(0) {}
    explicit DSU(int N) : N(N), par(N, -1), grps(N) {}
    int merge(int u, int v) {
        assert(0 <= u && u < N);
        assert(0 <= v && v < N);
        u = find(u); v = find(v);
        if (u == v) return u;
        if (-par[u] < -par[v]) swap(u, v);
        par[u] += par[v];
        grps--;
        par[v] = u;
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
};


ll solve(){
    int N, cnt = 0;
    mi<ll> ans = 1;
    cin >> N;
    vector<pi> A(N);
    rep(i, 0, N) cin >> A[i].x;
    rep(i, 0, N) cin >> A[i].y;
    DSU dsu(N);
    rep(i, 0, N) {
        if(A[i].x == A[i].y) { cnt++; continue; }
        dsu.merge(A[i].x - 1, A[i].y - 1);
    }
    rep(_, 0, dsu.grps - cnt) ans *= 2;
    return ans.val;
}

int TC;
int main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> TC;
    while(TC--) cout << solve() << "\n";
}
