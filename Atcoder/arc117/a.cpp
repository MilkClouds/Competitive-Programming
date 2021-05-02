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

int A, B, N;
int main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> A >> B;
    N = A * B;
    N *= max(A / 2 * A / N, B / 2 * B / N) + 1;
    rep(i, 1, 1 + A / 2) cout << (N / A - i) << " " << (N / A + i) << " ";
    if(A & 1) cout << N / A << " ";
    rep(i, 1, 1 + B / 2) cout << -((N / B) - i) << " " << -((N / B) + i) << " ";
    if(B & 1) cout << -(N / B);
}
