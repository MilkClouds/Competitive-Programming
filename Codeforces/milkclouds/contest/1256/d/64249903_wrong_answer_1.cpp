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
		int st = 0;
		rep(i, 0, n){
			if(k==0) {v.pb(S[i]-'0'); continue;}
			if(S[i]=='1') st++;
			else{
				if(k>=st){
					k -= st;
					v.pb(0);
					if(i == n-1) v.pb(st);
				}
				else{
					v.pb(st-k);
					v.pb(0);
					v.pb(k);k = 0;
				}
			}
		}
		for(auto i:v){
			if(i==0)cout << "0";
			else rep(k,0,i)cout << "1";
		}
		cout << "\n";
	}
}