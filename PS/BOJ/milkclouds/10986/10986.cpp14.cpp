#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ans,n,m,a,s,ma[1001]={1},v;
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a;
		ma[s=(s+a)%m]++;
	}
	while(m--){v=ma[m];ans+=v*(v-1)/2;}
	cout<<ans;
	return 0;
}