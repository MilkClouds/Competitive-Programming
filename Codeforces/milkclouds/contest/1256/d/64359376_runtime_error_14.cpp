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
		vector<int> v;
		int cnt = 0, sum = 0;
		rep(i, 0, n){
			if(k==0) {v.pb(S[i]-'0'); continue;}
			if(S[i]=='1') cnt++;
			else{
				if(k>cnt){
					k -= cnt;
					v.pb(0);
				}
				else{
					rep(_,0,cnt-k)v.pb(1);
					v.pb(0);
					rep(_,0,k)v.pb(1);k = 0;
				}
			}
		}
		for(auto i:v){
			cout<<i;
		}
		rep(i,0,n-v.size())cout<<1;
		cout << "\n";
	}
}