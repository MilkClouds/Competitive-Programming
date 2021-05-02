#include <bits/stdc++.h>
using namespace std;
int depth,n,t;
long long ret;
map<int,int> m;
int main()
{
	m[0]=-1,m[3000001]=-1;
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>t;
		auto p=m.lower_bound(t);
		int tt=p--->second;
		depth=max(p->second,tt)+1;
		ret+=m[t]=depth;
		cout<<ret<<'\n';
	}
	return 0;
}