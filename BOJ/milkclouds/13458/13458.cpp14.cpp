#include <bits/stdc++.h>
using namespace std;
const int MAX=1e6+1;
int N,A[MAX],B,C;
long long ans;
// 10:43 ~ 10:45 | 2 minute solve
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>N;
	for(int i=0;i<N;i++)cin>>A[i];
	cin>>B>>C;
	for(int i=0;i<N;i++){
		ans++;
		if(A[i]>B)ans+=(A[i]-B)/C+((A[i]-B)%C!=0);
	}
	cout<<ans;
}