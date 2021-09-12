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


ll gcd(ll x, ll y){
    if(min(x, y) == 0) return max(x, y);
    if(x % y == 0) return y;
    return gcd(y, x % y);
}
ll N, M;
int main(){
    cin >> N >> M;
    ll g = gcd(N, M), G = g * g;
    N /= g; M /= g;
    if((N + M) % 2 == 0) G <<= 1;
    cout << G << endl;
}