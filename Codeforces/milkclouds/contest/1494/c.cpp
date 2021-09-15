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

using vi = vector<ll>;

const int MAX = 2e5 + 2, INF = 1e9 + 1;
ll TC, N, M, x;

ll solution(vi& A, vi& B){
    map<ll, ll> mapS, mapA, mapB, pre;
    pre[INF] = 0;
    ll ans = 0, cnt = 0;
    rep(i, 0, A.size()){
        mapS[A[i] - 1 - i] = i;
        mapA[A[i]] = i;
    }
    rep2(i, 0, B.size()) {
        if(mapA.find(B[i]) != mapA.end()) pre[B[i]] = ++cnt;
    }
    cnt = 0;
    mapB[INF] = B.size();
    rep(i, 0, B.size()){
        mapB[B[i]] = ++cnt;
    }
    rep(i, 0, B.size()){
        auto pos = mapS.upper_bound(B[i] - 1);
        if(pos == mapS.begin()) continue;
        int tmp = B[i] + ((--pos) -> y);
        ans = max(ans, ((--mapB.upper_bound(tmp)) -> y) - i + (pre.upper_bound(tmp) == pre.end() ? 0 : (pre.upper_bound(tmp) -> y)));
    }
    return ans;
}

int main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> TC;
    while(TC--){
        cin >> N >> M;
        vi A1, A2, B1, B2;
        rep(i, 0, N) {
            cin >> x;
            (x < 0 ? A2 : A1).pb(abs(x));
        }
        rep(i, 0, M) {
            cin >> x;
            (x < 0 ? B2 : B1).pb(abs(x));
        }
        reverse(all(A2)); reverse(all(B2));
        cout << solution(A1, B1) + solution(A2, B2) << "\n";
    }
}
