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

ll arr[MAX], fac[MAX], N, K, ans;

void erato(){
	for(ll i = 2; i < MAX; i++){
		if(arr[i])continue;
		for(ll j = i; j < MAX; j += i){
			arr[j] = 1;
			fac[j] = i;
		}
	}
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	erato();
	cin >> N >> K;
	rep(i, 1, N + 1){
		ans += fac[i] <= K;
	}
	cout << ans << endl;
}
	