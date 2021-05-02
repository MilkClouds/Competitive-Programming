#include <bits/stdc++.h>
using namespace std;

int N,a[100001],ret,i;
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>N;
	for(int i=0;i<N;i++)cin>>a[i];
	sort(a,a+N);
	for(i=N-3;i>=0;i-=3)ret+=a[i+1]+a[i+2];
	ret+=(i+1>=0?a[i+1]:0)+(i+2>=0?a[i+2]:0);
	cout<<ret;
}
