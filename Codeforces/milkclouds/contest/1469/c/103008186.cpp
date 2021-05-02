#include <bits/stdc++.h>
#define rep(a,b,c) for(ll a = b; a < c; a++)
#define pb push_back
 
using namespace std;
typedef long long ll;

const int MAX = 2e5 + 3;

int t, n, k, h[MAX], l, r, flag;

int main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);
	cin >> t;
	while(t--){
		cin >> n >> k;
		rep(i, 0, n) cin >> h[i];
		l = h[0]; r = h[0];
		flag = 0;
		rep(i, 1, n){
			if(h[i] >= r + k) { flag = 1; break;}
			r = min(h[i] + k - 1, r + k - 1);
			if(h[i] > l - k) l = h[i];
			else l = l - k + 1;
			if(l > r) {flag  =1 ; break;}

		}
		if(!flag && l <= h[n - 1] && h[n - 1] <= r) cout << "YES\n";
		else cout <<"NO\n";
	}
}