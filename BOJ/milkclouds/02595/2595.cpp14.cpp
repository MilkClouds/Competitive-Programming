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

int N,length=3e5,num;
vector<pi> ans_len;
vector<string> ans;

int f(int k){
	int t = k;
	rep(i, 0, N + 1){
		if(t % N == 0)return i + 1;
		t = (10 * t + k) % N;
	}
	return 0;
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> N;
	rep(k, 1, 10){
		int t = f(k);
		if(t) {
			if(length > t){
				length = t;
				num = k;
			}			
		}
	}
	if(num){rep(i,0,length)cout<<num; return 0;}
	rep(a,0,10){
		rep(b,a+1,10){
			bool flag=0;
			queue<int> Q;
			vector<bool> visit(N+1);
			vector<pi> prev(N+1);
			if(a){
				Q.push(a);visit[a]=1;
				prev[a]={-1,a};
			}
			Q.push(b);visit[b]=1;
			prev[b]={-1,b};
			while(!Q.empty()){
				int u = Q.front(); Q.pop();
				if(u == 0){flag=1;break;}
				int temp=-1;
				for(auto v:{(u*10+a)%N, (u*10+b)%N}){
					temp++;
					if(visit[v])continue;
					Q.push(v);
					visit[v]=1;
					prev[v]={u,temp?b:a};
				}
			}
			if(!flag)continue;
			int u=0;string s;
			while(~prev[u].x){s+=to_string(prev[u].y); u=prev[u].x;}
			s+=to_string(prev[u].y); reverse(s.begin(),s.end());
			ans.pb(s);
		}
	}
	sort(ans.begin(),ans.end(),[](string a,string b){return a.size()<b.size();});
	cout<<ans[0];
}