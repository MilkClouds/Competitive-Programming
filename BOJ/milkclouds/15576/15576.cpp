#include <bits/stdc++.h>
#include <atcoder/convolution>
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

string S, T;
vector<ll> A, B;
ll tmp, i;

int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> S >> T;
    reverse(all(S));
    reverse(all(T));
    A.resize(S.size());
    B.resize(T.size());
    rep(i, 0, S.size()) A[i] = S[i] - '0';
    rep(i, 0, T.size()) B[i] = T[i] - '0';
    auto&& ret = atcoder::convolution_ll(A, B);
    do{
        if(i < ret.size()) tmp += ret[i];
        if(i < ret.size()) ret[i] = tmp % 10;
        else ret.eb(tmp % 10);
        tmp /= 10; i++;
    } while(tmp || i < ret.size());
    while(ret.back() == 0) ret.pop_back();
    if(ret.empty()) ret.eb(0);
    reverse(all(ret));
    for(auto i: ret) cout << i;
}
