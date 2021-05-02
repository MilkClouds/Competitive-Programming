# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>
#define rep(a,b,c) for(ll a=b;a<c;a++)
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;
using ll=long long;
using lll=__int128_t;
const ll MAX=1e6;

ll N, arr[MAX];
vector<lll> pn = {4};

void sieve(){
	for(ll i = 3; i < MAX; i += 2){
		if(arr[i])continue;
		arr[i] = 1; pn.pb(i * i);
		for(ll j = i * i; j < MAX; j += i) arr[j]=1;
	}
}

ll count(ll limit, ll num, ll i){
	if(num > limit)return 0;
	ll ret = limit / num;
	for(; num * pn[i] <= limit; i++)
		ret -= count(limit, num * pn[i], i + 1);
	return ret;
}

int main(){
	sieve();
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> N;
	ll lo = 1, hi = 25505460948;
	while(lo < hi){
		ll m = lo + hi >> 1;
		ll t = m - count(m, 1, 0);
		if(t < N) lo = m + 1;
		else if (t > N) hi = m -1;
		else hi = m;
	}
	cout << lo;
}