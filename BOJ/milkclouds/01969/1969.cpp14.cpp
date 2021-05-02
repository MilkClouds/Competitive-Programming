#include <bits/stdc++.h>
#define x first
#define y second
#define pb push_back
#define all(x) x.begin(), x.end()
#define rep(a,b,c) for(int a=b;a<c;a++)
using namespace std;
int N,M,cnt;
string S[1005],ans;
map<char,int> m;
int main(){
	cin>>N>>M;
	rep(i,0,N)cin>>S[i];
	rep(i,0,M){
		m['T']=0;m['G']=0;m['C']=0;m['A']=0;
		rep(j,0,N)m[S[j][i]]++;
		int M=0;char c;
		for(auto [u,v]:m)if(v>M){
			M=v;
			c=u;
		}
		ans+=c;
		cnt+=N-M;
	}
	cout<<ans<<'\n'<<cnt;
}