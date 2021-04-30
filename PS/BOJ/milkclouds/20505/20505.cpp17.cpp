#include <bits/stdc++.h>
#define rep(a,b,c) for(ll a = b; a < c; a++)

using namespace std;
typedef long long ll;
const ll MAX = 250009;
const ll MOD = 998244353;

string N;
ll mod[MAX], mod2[MAX], ans = 0;

int main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
	cin >> N;
	mod[0] = mod2[0] = 1;
	rep(i, 1, MAX - 2) {
		mod[i] = (mod[i - 1] * 11) % MOD;
		mod2[i] = (mod2[i - 1] * 2) % MOD;
	}
	rep(i, 0, N.length()){
		ans += ((((N[i] - '0') * mod[N.length() - i - 1]) % MOD) * mod2[i]) % MOD;
		ans %= MOD;
	}
	cout << ans;
}