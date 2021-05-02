#include <bits/stdc++.h>
#define rep(a,b,c) for(int a=b;a<c;a++)
#define x first
#define y second
using namespace std;
using ll=long long;
using pll=pair<ll,ll>;
int x[4],ret=1e9;
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	rep(i,0,4)cin>>x[i];
	do{
		ret=min(ret,abs(x[0]+x[1]-x[2]-x[3]));
	}while(next_permutation(x,x+4));
	cout<<ret;
}