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
const ll MOD = 1e9 + 7, MAX = 1e5 + 3;

ll N, a;

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	while(cin >> N && N){
		ll ans = 0;
		for(;N;N/=10){
			a = N % 10; ans++;
			if(a == 1) ans += 2;
			else if (a == 0) ans += 4;
			else ans += 3;
		}
		cout << ans + 1 << "\n";
	}
}
	