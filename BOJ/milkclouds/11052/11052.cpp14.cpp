#include <bits/stdc++.h>
using namespace std;
int N,P[1001],memo[1001];
int solve(int left){
	if(left<=0)return left==0?0:-100000000;
	if(memo[left])return memo[left];
	int ret=0;
	for(int i=0;i<N;i++)ret=max(ret,solve(left-i-1)+P[i]);
	return memo[left]=ret;
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>N;
	for(int i=0;i<N;i++)cin>>P[i];
	cout<<solve(N);
}