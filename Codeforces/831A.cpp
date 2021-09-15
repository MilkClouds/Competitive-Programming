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

int N, A[101], a, b, c;
int main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> N;
    rep(i, 0, N) cin >> A[i];
    rep(i, 1, N){
        if(A[i - 1] < A[i]) {
            a++;
            if(b || c){
                cout << "NO\n";
                return 0;
            }
        }
        else if(A[i - 1] == A[i]) {
            b++;
            if(c){
                cout << "NO\n";
                return 0;
            }
        }
        else if(A[i - 1] > A[i]) {
            c++;
        }
    }
    cout << "YES\n";
}
