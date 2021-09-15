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

int K, A[14], B[13 * 200000 + 1], S, ans;
int main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> K;
    rep(i, 0, K) cin >> A[i];
    rep(i, 0, K) S += A[i];
    rep(ii, 0, pow(3, K)){
        int i = ii, j = 0, tmp = 0;
        while(i){
            if(i % 3 == 1) tmp += A[j];
            else if(i % 3) tmp -= A[j];
            i /= 3;
            j++;
        }
        if(tmp > 0) B[tmp]++;
    }
    rep(i, 1, S + 1){
        ans += B[i] == 0;
    }
    cout << ans;
}
