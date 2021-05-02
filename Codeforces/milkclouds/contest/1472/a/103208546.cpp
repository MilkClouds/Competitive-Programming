#include <bits/stdc++.h>
#define rep(a,b,c) for(ll a = b; a < c; a++)
#define pb push_back
 
using namespace std;
typedef long long ll;

ll TC, w, h, n;

int main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
	cin >> TC;
	while(TC--){
		cin >> w >> h >> n;
		ll a = 1, b = 1;
		while(w % 2 == 0){w /= 2; a *= 2;}
		w = h;
		while(w % 2 == 0){w /= 2; b *= 2;}
		cout << (a*b >= n ? "YES" : "NO") << "\n";
	}
}