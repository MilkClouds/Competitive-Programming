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

ll n, m, d, c[2005], dump;
vector<int>ans;
deque<int> remain;
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> n >> m >> d;
	rep(i, 0, m)cin >> c[i];
	int last = 0, cur = 0;
	rep(i, 1, n + 1){
		if(ans.size()>=i) last=i;
		else if(i - last >= d){
			if(cur == m){
				cout << "NO";
				return 0;
			}
			if(n + 1 < i + c[cur]) {
				rep(k,0,i + c[cur] - n -1)remain.pb(cur+1);
			}
			rep(k,0,c[cur])ans.pb(cur + 1);
			last = i; cur++;
		}
		else ans.pb(0);
	}
	cout << "YES\n";
	rep(i,cur,m)rep(k,0,c[i])remain.pb(i+1);
	while(!remain.empty()){
		rep(i,0,ans.size())if(ans[i]==0){ans.erase(ans.begin()+i);break;}
		ans.pb(remain.front()); remain.pop_front();
	}
	rep(i,0,n) cout << ans[i]<<" ";
}