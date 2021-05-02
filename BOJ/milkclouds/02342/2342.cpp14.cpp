# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# include <bits/stdc++.h>
# define rep(a,b,c) for(int a=b;a<c;a++)
# define x first
# define y second
# define all(x) x.begin(),x.end()
# define pb push_back

using namespace std;
using ll=long long;
using pii=pair<ll,ll>;
const int MAX=1e5+5,INF=1e9;

int d[5][5],dist[5][5];

const int oppo[5]={0,3,4,1,2};

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	rep(i,1,5)dist[0][i]=2;
	rep(i,1,5){
		rep(j,1,5){
			dist[i][j]=i^j ? (oppo[i]^j?3:4):1;
		}
	}
	// d[i][j] : 한 발 i,j에 뒀을때 최소cost
	fill(d[0],d[5],INF);
	d[0][0]=0;
	while(true){
		int dir;
		cin>>dir;
		if(dir==0)break;
		int dtemp[5][5];
		fill(dtemp[0],dtemp[5],INF);
		rep(i,0,5){
			rep(j,0,5){
				if(d[i][j]==INF)continue;
				if(dir^j){
					if(d[i][j]+dist[i][dir]<dtemp[dir][j])
						dtemp[dir][j]=d[i][j]+dist[i][dir];
				}
				if(dir^i){
					if(d[i][j]+dist[j][dir]<dtemp[i][dir])
						dtemp[i][dir]=d[i][j]+dist[j][dir];
				}
			}
		}
		rep(i,0,5)rep(j,0,5)d[i][j]=dtemp[i][j];
	}
	int mn=INF;
	rep(i,0,5)rep(j,0,5)mn=min(mn,d[i][j]);
	cout<<mn;
}