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

ll Q, a, b, n, S;

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> Q;
	while(Q--){
		cin >> a >> b >> n >> S;
		ll t = S / n;
		if(t<=a){
			cout << (S % n > b ? "NO" : "YES") << "\n";
		}
		else {
			cout << (S - a * n > b ? "NO": "YES") << "\n";
		}
	}
}