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

int TC, N, M, K, A[101], B[101];
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> TC;
    while(TC--){
        vector<int> ans;
        cin >> K >> N >> M;
        rep(i, 0, N) cin >> A[i];
        rep(j, 0, M) cin >> B[j];
        int i = 0, j = 0;
        bool flag = 0;
        do{
            while(i < N && A[i] == 0) ans.pb(A[i]), i++, K++;
            while(j < M && B[j] == 0) ans.pb(B[j]), j++, K++;
            if(i == N || j == M) break;
            if(A[i] < B[j]){
                if(A[i] > K) flag = 1;
                else ans.pb(A[i]), i++;
            } else {
                if(B[j] > K) flag = 1;
                else ans.pb(B[j]), j++;
            }
        } while(!flag && i < N && j < M);
        while(i < N && !flag){
            if(A[i] > K) flag = 1;
            ans.pb(A[i]), i++;
            if(A[i] == 0) K++;
        }
        while(j < M && !flag){
            if(B[j] > K) flag = 1;
            ans.pb(B[j]), j++;
            if(B[j] == 0) K++;
        }
        if(flag) cout << -1;
        else for(auto i: ans) cout << i << " ";
        cout << endl;
    }
}
