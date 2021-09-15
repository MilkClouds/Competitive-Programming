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

ll T,n,k,d,x,cnt,ans;
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>T;
	while(T--){
		cnt = 0; ans = 1e10;
		cin >> n >> k >> d;
		unordered_map<int,int> m;
		queue<int> Q;
		rep(i, 0, n){
			cin >> x;
			if(m[x] == 0) cnt++;
			m[x]++; Q.push(x);
			if(i >= d){
				if(m[Q.front()]==1) cnt--;
				m[Q.front()]--;
				Q.pop();
			}
			if(i >= d - 1) ans = min(ans, cnt);
		}
		cout << ans << "\n";
	}
}