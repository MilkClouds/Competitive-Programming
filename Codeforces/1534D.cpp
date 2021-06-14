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

int N;
vector<pi> ans;
vector<int> A(2000), P, Q, chk(2000);
void query(int t){
    if(chk[t]) return;
    chk[t] = 1;
    cout << "? " << t + 1 << endl;
    rep(i, 0, N) cin >> A[i];
    rep(i, 0, N) if(A[i] == 1 && !chk[i]) ans.emplace_back(t + 1, i + 1);
}
int main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> N;
    query(0);
    rep(i, 1, N) (A[i] % 2 ? P : Q).pb(i);
    if(P.size() > Q.size()) swap(P, Q);
    for(auto i: P) query(i);
    cout << "!" << endl;
    for(auto p: ans) cout << p.x << " " << p.y << "\n";
}
