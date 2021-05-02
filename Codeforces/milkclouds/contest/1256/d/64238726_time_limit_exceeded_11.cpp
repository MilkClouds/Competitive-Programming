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

int q, n, k;
string S;

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> q;
	while(q--){
		cin >> n >> k;
		cin >> S;
		int cur = 1;
		while(k && cur < n){
			if(cur && S[cur-1] == '1' && S[cur] == '0'){
				k--;
				swap(S[cur], S[cur-1]);
				cur--;
			}
			else cur++;
		}
		cout << S << "\n";
	}
}