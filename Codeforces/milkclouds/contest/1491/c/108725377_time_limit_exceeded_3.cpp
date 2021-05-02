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

const int MAX = 5000;
int TC, N, S[MAX], c;
ll ans;
int main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> TC;
    while(TC--){
        cin >> N;
        ans = 0;
        rep(i, 0, N) cin >> S[i];
        rep(i, 0, N){
            if(i < N - 1 && S[i] > N - i - 1){
                ans += S[i] - (N - i - 1);
                S[i] = N - i - 1;
            }
            int lim = S[i] - 1;
            rep(_, 0, lim){
                c = i; ans++;
                while(c < N){
                    if(S[c] == 1) c += 1;
                    else c += S[c]--;
                }
            }
        }
        cout << ans << "\n";
    }
}
