#include <bits/stdc++.h>
using namespace std;
int n,t;
int main(){
	cin>>n;
	while(n--){
		long long ret=0;
		for(int i=0;i<24;i++){scanf("%1d",&t);ret=ret*2+t;}
		cout<<ret<<'\n';
	}
}