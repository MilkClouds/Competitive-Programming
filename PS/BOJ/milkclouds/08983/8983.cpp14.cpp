#include <bits/stdc++.h>
using namespace std;

const int MAX=1e5+5;
int N,M,L,a[MAX],x,y,ans;

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>M>>N>>L;
	for(int i=0;i<M;i++)cin>>a[i];
	sort(a,a+M);
	for(int i=0;i<N;i++){
		cin>>x>>y;
		if(y>L)continue;
		auto pos=lower_bound(a,a+M,x);
		int temp=1000000000;
		if(pos==a+M)temp=x-*(pos-1);
		else if (pos==a)temp=(*pos)-x;
		else temp=min(x-*(pos-1),(*pos)-x);
		if(y+temp>L)continue;
		ans++;
	}
	cout<<ans;
}