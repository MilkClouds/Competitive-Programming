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
const ll INF = 1e9, MOD = 1e9 + 7, MAX = 4e6 + 1;

bool arr[MAX];
vector<ll> pn;
void erato(){
	for(ll i = 2; i < MAX; i++){
		if(arr[i])continue;
		pn.pb(i);
		for(ll j = i; j < MAX; j += i) arr[j] = 1;
	}
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	erato();
	ll A, B, D, cnt = 0, flag;
	cin >> A >> B >> D;
	for(auto i = lower_bound(pn.begin(), pn.end(), A); i!=pn.end() && (*i <=B);i++){
		ll t = *i;
		flag = 0;
		while(t){if(t%10==D)flag=1;t/=10;}
		cnt += flag;
	}
	cout << cnt;
}
	