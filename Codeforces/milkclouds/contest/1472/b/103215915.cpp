#include <bits/stdc++.h>
#define rep(a,b,c) for(ll a = b; a < c; a++)
#define pb push_back
 
using namespace std;
typedef long long ll;

ll TC, n, a[101], x, y;

int main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
	cin >> TC;
	while(TC--){
		cin >> n;
		x = y = 0;
		rep(i, 0, n) {cin >> a[i]; (a[i] == 1 ? x : y)++;}
		if((x & 1) || (x == 0 && (y & 1))) {cout << "NO\n"; continue;}
		cout << "YES\n";
	}
}