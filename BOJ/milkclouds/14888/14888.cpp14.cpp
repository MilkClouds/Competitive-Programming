//#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int n,arr[12],op[4],m,M;
void solve(int c,int a){
	if(c==n){
		m=min(m,a);
		M=max(M,a);
		return;
	}
	if(op[0]){
		op[0]--;
		solve(c+1,a+arr[c]);
		op[0]++;
	}
	if(op[1]){
		op[1]--;
		solve(c+1,a-arr[c]);
		op[1]++;
	}
	if(op[2]){
		op[2]--;
		solve(c+1,a*arr[c]);
		op[2]++;
	}
	if(op[3]){
		op[3]--;
		solve(c+1,a/arr[c]);
		op[3]++;
	}
}
int main(){
	cin>>n;
	m=1000000005;
	M=-m;
	for(int i=0;i<n;i++)cin>>arr[i];
	for(int i=0;i<4;i++)cin>>op[i];
	solve(1,arr[0]);
	cout<<M<<endl<<m;
}