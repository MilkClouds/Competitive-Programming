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

ll TC, N, K, P[31];

int main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> TC;
    rep(tc, 1, TC + 1){
        cin >> N >> K;
        rep(i, 0, N) cin >> P[i];
        sort(P, P + N);
        if(N == 1){
            printf("Case #%d: %lf\n", tc, (double) (K - 1) / K);
            continue;
        }
        priority_queue<pl> pq;
        rep(i, 1, N){
            pq.push({P[i] - P[i - 1], i});
        }
        ll ans = 0, aaa = pq.top().x - 1;
        pq.push({2 * (P[0] - 1), 0});
        pq.push({2 * (K - P[N - 1]), N});
        if(pq.top().x <= 1) {
            ans = 0;
        } else {
            pi tmp = pq.top(); pq.pop();
            if(pq.top().x <= 1){
                if(tmp.x & 1) ans++;
            }
            ans += tmp.x / 2  + pq.top().x / 2;
        }
        printf("Case #%d: %lf\n", tc, (double) max(aaa, ans) / K);
    }
}
