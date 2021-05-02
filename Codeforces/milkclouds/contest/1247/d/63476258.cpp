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
const int MAX=1e5+1;

ll n,k,arr[MAX],a[MAX], ans;
vector<ll> pn = {2};
unordered_map<ll,ll> m;
void erato(){
	for(ll i=3;i<=MAX;i+=2){
		if(arr[i])continue;
		pn.pb(i);arr[i]=1;
		for(ll j=i*i;j<=MAX;j+=i)arr[j]=1;
	}
}
pi f(ll n){
	ll ret=1, m = 1;
	for(auto i:pn){
		if( i*i > n)break;
		ll cnt = 0;
		while(n%i==0){
			cnt++; n/=i;
		}
		cnt %= k;
		ret *= pow(i, cnt);
		if(cnt) m *= i;
	}
	if(n>1) {ret *= n; m *= n;}
	return {ret, m};
}
ll gcd(ll a,ll b){return a%b ? gcd(b,a%b):b;}
ll lcm(ll a,ll b){return a*b/gcd(a,b);}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	erato();
	cin >> n >> k;
	rep(i, 0, n){
		cin >> a[i];
		pi t = f(a[i]); a[i] = t.x;
		if(log10(t.y)*k-log10(t.x) >5)continue;
		ans += m[ pow(t.y, k) / t.x ];
		m[a[i]]++;
		//cout << a[i] <<" " << ans << " "<<t.y<< endl;
	}
	cout << ans;
}