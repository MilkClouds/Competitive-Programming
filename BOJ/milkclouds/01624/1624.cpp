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

const int MAX = 1000;
int N, A[MAX], B[MAX], j, ans, chk[MAX], l;
int main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> N;
    rep(i, 0, N) {
        cin >> A[i];
        B[i] = A[i];
    }
    sort(B, B + N);
    while(j < N){
        ans++;
        rep2(i, 0, N){
            if(A[i] == B[j] && !chk[i]) {
                chk[i] = 1;
                j++;
                l = i;
            }
        }
        rep(i, l, N){
            if(A[i] == B[j] && !chk[i]) {
                chk[i] = 1;
                j++;
            }
        }
    }
    cout << ans;
}