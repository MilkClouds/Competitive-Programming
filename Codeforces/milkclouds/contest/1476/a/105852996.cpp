#include <bits/stdc++.h>
#define rep(a,b,c) for(ll a = b; a < c; a++)
#define pb push_back
 
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;

ll t, n, k;
int main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
	cin >> t;
	while(t--){
		cin >> n >> k;
		k *= n/k + (n%k!=0);
		cout << k/n + (k%n!=0) << "\n";
	}
}