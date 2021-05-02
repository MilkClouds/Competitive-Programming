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

ll n,p;
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> n >> p;
	for(ll c = 1; ;c++){
		ll t = n - p * c;
		if(t < 0 && p >= 0){cout << -1; return 0;}
		if(t < 0)continue;
		if(__builtin_popcountll(t) <= c){
			cout << c;
			return 0;
		}
	}
}