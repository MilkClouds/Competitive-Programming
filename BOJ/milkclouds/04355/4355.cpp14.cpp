# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>
#define rep(a,b,c) for(int a=b;a<c;a++)
#define rep2(a,b,c) for(ll a=b;a>c;a--)
#define pb push_back
#define x first
#define y second
#define all(x) x.begin(), x.end()
using namespace std;
using ll=long long;
using ti=tuple<ll,ll,ll>;
using pi=pair<ll,ll>;
const ll MAX = 1e6;

ll N, arr[MAX];
vector<ll> pn = {2};

void erato(){
	for(ll i = 3; i <= MAX; i += 2){
		if(arr[i])continue;
		pn.pb(i);
		for(ll j = i * i; j <= MAX; j += i) arr[j] = 1;
	}
}

ll totient(ll N){
	ll ret = 1;
	for(auto p : pn){
		if(N % p == 0){
			ll cur = 1;
			while(N % p == 0) {N /= p; cur *= p;}
			ret *= cur - cur / p;
		}
	}
	if(N > 1) ret *= N - 1;
	return ret;
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	erato();
	while((cin >> N) && N){
		cout << totient(N) << "\n";
	}
}
	
