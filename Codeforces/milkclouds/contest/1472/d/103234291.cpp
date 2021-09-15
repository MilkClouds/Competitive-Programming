#include <bits/stdc++.h>
#define rep(a,b,c) for(ll a = b; a < c; a++)
#define pb push_back
 
using namespace std;
typedef long long ll;
const int MAX = 2e5 + 1;

ll TC, n, a[MAX], A, B;

int main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
	cin >> TC;
	while(TC--){
		cin >> n;
		rep(i, 0, n) cin >> a[i];
		sort(a, a + n, greater<ll>());
		A = B = 0;
		rep(i, 0, n){
			((i & 1) ? B : A) += ((i % 2) ^ (a[i] & 1)) ? 0 : a[i];
		}
		if(A > B) cout << "Alice\n";
		else if (A < B) cout << "Bob\n";
		else cout << "Tie\n";
	}
}