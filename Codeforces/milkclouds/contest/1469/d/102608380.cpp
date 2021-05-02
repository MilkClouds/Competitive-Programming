#include <bits/stdc++.h>
#define rep(a,b,c) for(ll a = b; a < c; a++)
 
using namespace std;
typedef long long ll;

pair<ll, ll> ans[250000];
ll TC, n, k;
vector<ll> v;
bool a[250000];
int main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
	cin >> TC;
	while(TC--){
		k = 0;
		cin >> n;
		ll temp = n;
		v.clear();
		fill(a, a + 250000, 0);
		while(temp > 2){
			a[temp] = 1;
			v.push_back(temp);
			temp = ceil(sqrt(temp));
		}
		v.push_back(temp); a[temp] = 1;
		rep(i, 2, n + 1) if(!a[i]) ans[k++] = {i, n};
		rep(i, 0, v.size() - 1){
			ans[k++] = {v[i], v[i + 1]};
			ans[k++] = {v[i], v[i + 1]};
		}
		cout << k << "\n";
		rep(i, 0, k){
			cout << ans[i].first << " " << ans[i].second << "\n";
		}
	}	
}

