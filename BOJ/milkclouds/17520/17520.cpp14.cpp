#include <bits/stdc++.h>
#define rep(a,b,c) for(int a=b;a<c;a++)
#define x first
#define y second
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const ll MOD=16769023;
ll ret,n;
int main(){
	vector<ll> x={1,0,1};
	cin>>n;
	rep(i,1,n){
		vector<ll> y={x[1],(x[0]+x[2])%MOD,x[1]};
		x=y;
	}
	for(auto i:x)ret=(ret+i)%MOD;
	cout<<ret;
}