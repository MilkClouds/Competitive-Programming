#include <bits/stdc++.h>
#define rep(a,b,c) for(ll a = b; a < c; a++)
#define pb push_back
 
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;

ll f(ll n){
	if(n == 0)return 0;
	if(n == 1)return 1;
	return f(n/2)*2 + (n + 1)/2;
}

int main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
	ll a, b;
	cin >> a >> b;
 	cout << f(b) - f(a - 1);
}