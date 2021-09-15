# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
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

string solve(){
    string S;
    cin >> S;
    vector<pair<char, int>> A;
    vector<int> cnt(26);
    string T(S.size(), 1);
    rep(i, 0, S.size()) A.eb(S[i], i), cnt[S[i] - 'a']++;
    sort(all(A));
    int bias = *max_element(all(cnt));
    rep(i, 0, S.size()){
        T[A[i].y] = A[(i + bias) % S.size()].x;
    }
    rep(i, 0, S.size()) if(S[i] == T[i]) return "IMPOSSIBLE";
    return T;
}

int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    int TC;
    cin >> TC;
    rep(tc, 0, TC){
        cout << "Case #" << tc + 1 << ": " << solve() << "\n";
    }
}

