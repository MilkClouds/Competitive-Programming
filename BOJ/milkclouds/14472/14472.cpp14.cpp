#include <bits/stdc++.h>
#define x first
#define y second
#define pb push_back
#define all(x) x.begin(), x.end()
#define rep(a,b,c) for(int a=b;a<c;a++)
using namespace std;
typedef vector<int> vi;
int N,M,D,ans;
string S[105];
vi r[105],c[105];
int func(vi& a){
	int ret=0;
	for(auto i:a) if(i>=D) ret+=i-D+1;
	return ret;
}
int main(){
	cin>>N>>M>>D;
	rep(i,0,N)cin>>S[i];
	rep(i,0,N){
		int t=0;
		rep(j,0,M){
			if(S[i][j]=='#') {r[i].pb(t); t=0;}
			else t++;
		}
		if(t) r[i].pb(t);
	}
	rep(j,0,M){
		int t=0;
		rep(i,0,N){
			if(S[i][j]=='#') {c[j].pb(t); t=0;}
			else t++;
		}
		if(t) c[j].pb(t);
	}
	rep(i,0,N)ans+=func(r[i]);
	rep(j,0,M)ans+=func(c[j]);
	cout<<ans;
}