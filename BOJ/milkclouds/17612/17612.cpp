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
using ti = tuple<int, int, int>;

const int MAX = 1e5;
int N, k, cnt;
ll ans;
pi A[MAX];
deque<pi> B[MAX * 20 + 1];
multiset<int> T;
void insert(deque<pi>& deq, pi o){
    if(deq.empty()) deq.pb(o);
    else{
        if(deq.front() < o) deq.pb(o);
        else 
    }
}
int main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> N >> k;
    rep(i, 0, N) cin >> A[i].y >> A[i].x;
    rep(i, 0, k) {
        B[0].pb({i, 0});
        T.insert(0);
    }
    rep(i, 0, N){
        int time = *T.begin(), cash, r;
        T.erase(T.find(time));
        tie(cash, r) = *B[time].rbegin();
        B[time].erase(B[time].rbegin());
        int ntime = time + A[i].x;
        T.insert(ntime);
        B[ntime].
    }
}
