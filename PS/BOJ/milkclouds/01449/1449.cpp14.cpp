#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int N,L,a[1001],ans,cur,last;
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>N>>L;
	for(int i=0;i<N;i++)cin>>a[i];
	sort(a,a+N);
	cur=L;last=a[0];ans=1;
	for(int i=1;i<N;i++){
		if(a[i]-last+1<=cur){
			cur-=a[i]-last;
		}
		else{
			ans++;cur=L;
		}
		last=a[i];
	}
	cout<<ans;
}