#include <iostream>
using namespace std;

int N,T,a[100001],l,r,m,b[100000];
bool possible(int diff){
	int ret=0;
	for(int i=0;i<N;i++)b[i]=a[i];
	for(int i=1;i<N;i++){
		if(b[i-1]+diff<b[i]){
			ret+=b[i]-b[i-1]-diff;
			b[i]=b[i-1]+diff;
		}
	}
	for(int i=N-2;~i;i--){
		if(b[i+1]+diff<b[i]){
			ret+=b[i]-b[i+1]-diff;
			b[i]=b[i+1]+diff;
		}
	}
	return ret<=T;
}
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>N>>T;
	for(int i=0;i<N;i++)cin>>a[i];
	r=1e9;
	while(l<r){
		m=l+r>>1;
		if(possible(m))r=m;
		else l=m+1;
	}
	possible(r);
	for(int i=0;i<N;i++)cout<<b[i]<<' ';
	return 0;
}