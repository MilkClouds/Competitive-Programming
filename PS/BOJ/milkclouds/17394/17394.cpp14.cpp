#include <bits/stdc++.h>
#define rep(a,b,c) for(int a=b;a<c;a++)
#define x first
#define y second
#define all(x) x.begin(),x.end()
using namespace std;
using ll=long long;
using pii=pair<ll,ll>;
const int MAX=3e6+3;
int arr[MAX],pn[MAX],T,A,B,N,visit[MAX];
vector<int> pnlist;
void sieve(){
	pn[2]=1;
	pnlist.push_back(2);
	for(ll i=3;i<MAX;i+=2){
		if(arr[i])continue;
		arr[i]=1; pn[i]=1; pnlist.push_back(i);
		for(ll j=(ll)i*i;j<MAX;j+=i)arr[j]=1;
	}
}
int calc(int n,int k){
	if(k==1)return n/2;
	if(k==2)return n/3;
	if(k==3)return n+1;
	return n-1;
}
int BFS(){
	queue<pii> Q;
	Q.push({N,0});
	while(!Q.empty()){
		int cur=Q.front().x, dist=Q.front().y; Q.pop();
		//printf("%d %d\n", cur,dist);
		if(A<=cur&&cur<=B&&pn[cur]) return dist;
		rep(k,1,5){
			int suc=calc(cur,k);
			if(1<=suc){
				if( visit[suc]==T+1 ) continue;
				visit[suc]=T+1;
				if(A<=suc&&suc<=B&&pn[suc]) return dist+1;
				Q.push({suc,dist+1});
			}
		}
	}
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	sieve();
	cin>>T;
	while(T--){
		cin>>N>>A>>B;
		auto pos1=lower_bound(all(pnlist),A);
		if(*pos1 <= B){
			cout<<BFS()<<"\n";
		}
		else cout<<"-1\n";
	}
}