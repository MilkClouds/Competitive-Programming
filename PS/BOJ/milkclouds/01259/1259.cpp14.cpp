#include <bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(0);
	int n;
	while(1){
		cin>>n;
		if(!n)break;
		int t=0,temp=n;
		while(temp){
			t=t*10+temp%10;
			temp/=10;
		}
		cout<<(t==n?"yes":"no")<<'\n';
	}
}