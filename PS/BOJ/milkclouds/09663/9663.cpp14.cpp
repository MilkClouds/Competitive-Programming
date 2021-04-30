#include <bits/stdc++.h>
using namespace std;
int N,tot;
bool cross[40],cross2[40],C[20];
bool valid(int r,int c){
	if(C[c] or cross[r-c+16] or cross2[r+c])return 0;
	return 1;
}
void solve(int u){
	if(u==N+1){tot++;return;}
	for(int i=1;i<=N;i++){
		if(!valid(u,i))continue;
		C[i]=1;cross[u-i+16]=1;cross2[u+i]=1;
		solve(u+1);
		C[i]=0;cross[u-i+16]=0;cross2[u+i]=0;
	}
}
int main(){
	cin>>N;
	solve(1);
	cout<<tot;
}