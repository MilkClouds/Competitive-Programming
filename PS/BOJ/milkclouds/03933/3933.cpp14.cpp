#include <bits/stdc++.h>
#define rep(a,b,c) for(int a=b;a<c;a++)
#define x first
#define y second
#define all(x) x.begin(),x.end()
#define pb push_back
using namespace std;
using ll=long long;
using pii=pair<ll,ll>;
int n,chk[1<<17];
vector<int> v;
ll solve(int n,int m,int point){
	if(m==1)return chk[n]&&n>=v[point];
	ll cnt=0;
	rep(i,point,v.size()){
		if(n-v[i]<=0)break;
		cnt+=solve(n-v[i],m-1,i);
	}
	return cnt;
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	rep(i,1,1<<8){
		v.pb(i*i);chk[i*i]=1;
	}
	while(~scanf("%d",&n)&&n){
		cout<<solve(n,4,0)+solve(n,3,0)+solve(n,2,0)+solve(n,1,0)<<"\n";
	}
}
	