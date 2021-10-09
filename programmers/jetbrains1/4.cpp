#include <bits/stdc++.h>
#define rep(i,a,b) for(int i = (a); i < (b); i++)
#define rep2(i,a,b) for(int i = (b) - 1; i >= (a); i--)
#define cinA(A, N) rep(i, 0, N) cin >> A[i];
#define coutA(A, N) rep(i, 0, N) cout << A[i] << " ";
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

const int MOD = 1e9 + 7;

long long poww(long long a, long long b) {
	long long ret = 1;
	while (b) {
	if (b & 1) ret *= a;
		a *= a;
		a %= MOD;
		ret %= MOD;
		b >>= 1;
	}
	return ret;
}

inline int bytwo(ll u, ll v){
    rep(i, 0, 32){
        if(u == (1LL << i) * v) return i;
    }
    return -1;
}

const int MAX = 2e5 + 1;
array<int, 31> dp[MAX];

vector<int> solution(vector<int> a, vector<int> s) {
    vector<int> answer(s.size(), 0);
    int bias = 0, i = 0;
    for(auto n: s){
        vector<ll> S(n + 1, 0), b(a.begin() + bias, a.begin() + n + bias); b.insert(b.begin(), 0);
        rep(i, 0, n + 1) dp[i].fill(0);
        map<ll, ll> M;
        dp[0][0] = 1;
        S[0] = 0;
        M[0] = 0;
        rep(i, 1, n + 1){
            S[i] = S[i - 1] + b[i];
            M[S[i]] = i;
            rep(e, 0, 31) dp[i][0] += dp[i - 1][e], dp[i][0] %= MOD;
            rep(e, 1, 31){
                if(dp[i][e - 1] == 0) break;
                ll tmp = S[i] - b[i] * (1LL << e - 1);
                if(M.find(tmp) == M.end()) break;
                if(M.find(S[i] - b[i] * poww(2, e)) == M.end()) break;
                int tmp2 = bytwo(b[i] * (1LL << e - 1), b[M[tmp]]);
                if(tmp2 == -1 || dp[M[tmp]][tmp2] == 0) break;
                rep(d, 0, 31) dp[i][e] = (dp[i][e] + dp[M[(S[i] - b[i] * poww(2, e))]][d]) % MOD;
            }
        }
        rep(j, 0, 31) answer[i] = ((ll)answer[i] + dp[n][j]) % MOD;
        i++;
        bias += n;
    }
    return answer;
}