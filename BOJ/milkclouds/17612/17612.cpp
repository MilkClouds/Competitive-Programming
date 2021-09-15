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
using tl = tuple<ll, ll, ll>;
using pl = pair<ll, ll>;
using pi = pair<int, int>;
using ld = long double;
using ti = tuple<int, int, int>;

const int MAX = 1e5;
int N, k;
ll ans, tim, cash, ppl, cnt;
pi A[MAX];
priority_queue<tl> pq;
set<int> cashier;
void checkout(){
    tie(tim, cash, ppl) = pq.top(); pq.pop();
    ans += (++cnt) * ppl;
    cashier.insert(cash);
}
int main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> N >> k;
    rep(i, 0, N) cin >> A[i].x >> A[i].y;
    rep(i, 0, k) {
        cashier.insert(i);
    }
    rep(i, 0, N){
        while(cashier.empty() || (!pq.empty() && tim == get<0>(pq.top()))) checkout();
        cash = *cashier.begin();
        cashier.erase(cashier.begin());
        pq.push({tim - A[i].y, cash, A[i].x});
    }
    while(!pq.empty()) checkout();
    cout << ans << endl;
}
