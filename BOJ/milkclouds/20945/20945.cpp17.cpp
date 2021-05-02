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

const int MAX = 1e5;
int N, K, A[MAX * 2], l, r, ans;
set<int> S;
int M(){return *(--S.end());}
int m(){return *S.begin();}

int main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> N >> K;
    rep(i, 0, N) {
        cin >> A[i];
        A[i + N] = A[i];
    }
    ans = K;
    S.insert(A[l]);
    while(l < N){
        ans = min(ans, K - (r - l + 1));
        if(S.count(A[r + 1])){
            S.erase(A[l++]);
            continue;
        }
        S.insert(A[r + 1]);
        if(M() - m() < K) r++;
        else {
            S.erase(A[r + 1]);
            S.erase(A[l++]);
        }
    }
    cout << ans;
}
