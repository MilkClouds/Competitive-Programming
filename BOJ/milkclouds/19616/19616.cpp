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

const int MAX = 2e5 + 11;
const ll INF = 1e18;
int N, M, K, a, c, NZ[MAX];
struct ABC{
    ll S;
    int x, y;
    vector<int> a;
    int operator [](int i){return a[i];}
    void push_back(int i){return a.pb(i);}
    int size(){return a.size();}
} V[MAX];
ll S, T;
struct Part{
    int i, cnt, sz, kth, value, prv = MAX;
    ll sum, S;
    Part(): Part(0, 0, 0, 0, 0, 0, 0){}
    Part(int i, ll sum, ll S): i(i), sum(sum), S(S) {
        if(0 <= i && i < M){
            cnt = 0; sz = V[i].x; kth = 0; value = sz - 1;
        } else{
            cnt = -1;
        }
    }
    Part(int i, int cnt, int sz, int kth, int value, ll sum, ll S, int prv = MAX): i(i), cnt(cnt), sz(sz), kth(kth), value(value), sum(sum), S(S), prv(prv){}
    vector<Part> nxts(){
        vector<Part> ret;
        if(!(0 <= i && i < M)) return ret;
        if(sz && value + 1 < V[i].size() && value + 1 < prv)
            ret.eb(i, cnt + 1, sz, kth, value + 1, sum + V[i][value + 1] - V[i][value], S, prv);
        if(sz && kth + 1 < sz && sz - kth <= value){
            ret.eb(i, cnt + 1, sz, kth + 1, sz - kth - 1, sum + V[i][sz - kth - 1] - V[i][sz - kth - 2], S, value);
        }
        if(sz - 1 - kth == value && sz < V[i].y){
            ret.eb(i, cnt + 1, sz + 1, 0, sz, sum + V[i][sz], S);
        }
        sort(all(ret), [&](Part &a, Part &b){return a.sum < b.sum;});
        rep(i, 1, ret.size()) ret[i].cnt++;
        return ret;
    }
    friend bool operator < (const Part& a, const Part& b){
        return a.sum > b.sum;
    }
};
ostream& operator << (ostream& os, Part& p){
    return os << p.i << " " << p.cnt << " " << p.sz << " " << p.kth << " " << p.value << " " << p.prv << " " << p.sum;
}
priority_queue<Part> pq;
inline void push(Part& p){
    if(~p.cnt) pq.push(p);
}
inline void push(Part&& p){
    if(~p.cnt) pq.push(p);
}
void nxt(Part an){
    int j = ~an.i ? NZ[an.i] : (V[0].y ? 0 : NZ[0]);
    if(0 <= j && j < M){
        if(an.i < M - 1){
            for(auto& p: Part(j, an.sum, an.sum).nxts()) push(p);
            if(an.cnt == 1) for(auto& p: Part(j, an.S, an.S).nxts()) push(p);
        }
    }
    if(0 <= an.i && an.i < M)
        for(auto& p: an.nxts()) push(p);
}
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> N >> M >> K;
    rep(i, 0, N){
        cin >> a >> c;
        V[a - 1].pb(c);
    }
    rep(i, 0, M) {
        cin >> V[i].x >> V[i].y; V[i].y = min(V[i].y, V[i].size());
        sort(all(V[i].a));
        if(V[i].x > V[i].size()){
            rep(j, 0, K) cout << "-1\n";
            return 0;
        }
        rep(j, 0, V[i].x) S += V[i][j];
    }
    rep(i, 0, M){
        auto tmp = Part(i, S, S);
        ll s = INF;
        for(auto& p: tmp.nxts()) s = min(s, p.sum);
        V[i].S = s - tmp.sum;
    }
    sort(V, V + M, [&](ABC& a, ABC& b){
        return a.S < b.S;
    });
    NZ[M] = M;
    rep2(i, 0, M){
        NZ[i] = NZ[i + 1];
        if(V[i + 1].y) NZ[i] = i + 1;
    }
    pq.push(Part(-1, 2, 0, 0, 0, S, S));
    rep(_, 0, K){
        if(pq.empty()){
            cout << "-1\n";
            continue;
        }
        auto P = pq.top(); pq.pop();
        cout << P.sum << "\n";
        nxt(P);
    }
}