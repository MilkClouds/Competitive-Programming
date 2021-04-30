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

ll N;

ll f(ll x){
	return x - (x / 3 + x / 5) + x / 15;
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> N;
	ll lo = 1, hi = 1e12;
	while(lo < hi){
		ll m = lo + hi >> 1;
		if(f(m) < N) lo = m + 1;
		else hi = m;
	}
	cout << lo << endl;
}