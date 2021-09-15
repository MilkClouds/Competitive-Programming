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

ll A, B, C;
int cmp(ll A, ll B){
    if(A < B) return 1;
    else if(A > B) return -1;
    return 0;
}
int solve(ll A, ll B, ll C){
    if(C & 1){
        return cmp(A, B);
    } return cmp(abs(A), abs(B));
}
int main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> A >> B >> C;
    int tmp = solve(A, B, C);
    cout << (tmp ? (tmp < 0 ? ">" : "<") : "=");
}
