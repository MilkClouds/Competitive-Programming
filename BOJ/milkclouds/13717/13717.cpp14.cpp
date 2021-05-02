# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>
#define rep(a,b,c) for(ll a=b;a<c;a++)
#define rep2(a,b,c) for(ll a=b;a>c;a--)
#define pb push_back
#define x first
#define y second
#define all(x) x.begin(), x.end()
using namespace std;
using ll=long long;
using ti=tuple<ll,ll,ll>;
using pi=pair<ll,ll>;
const ll MOD = 1e9 + 7, MAX = 1e5;

ll N, K[71], M, sum;
pi ans[71];
string P[71];

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> N;
	rep(i, 0, N){
		cin >> P[i] >> K[i] >> M;
		int t = max(0LL, M / (K[i] - 2) - 2);
		M -= (K[i] - 2) * t;
		while(M >= K[i]){
			M -= K[i] - 2;
			t++;
		}
		ans[i] = {-t, i};
		sum += t;
	}
	sort(ans, ans + N);
	cout << sum << "\n" << P[ans[0].y];
}
	