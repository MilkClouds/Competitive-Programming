#include <bits/stdc++.h>
#define rep(a,b,c) for(int a=b;a<c;a++)
using namespace std;
using ll=long long;
ll k,n,ans,stamp;
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	while(~scanf("%d %d",&n,&k)){
		ans=stamp=0;
		while(n){
			ans+=n;
			stamp+=n;
			n=stamp/k;stamp%=k;
		}
		cout<<ans<<"\n";
	}
}
