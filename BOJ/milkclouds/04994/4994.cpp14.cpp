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

string solution(int N){
	int a=0, b=1;
	bool flag=0;
	queue<int> Q;
	vector<bool> visit(N+1);
	vector<pi> prev(N+1);
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
	int u=0;string s;
	while(~prev[u].x){s+=to_string(prev[u].y); u=prev[u].x;}
	s+=to_string(prev[u].y); reverse(s.begin(),s.end());
	return s;
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	while((cin >> N) && N){
		cout << solution(N) << "\n";
	}
}