#include <bits/stdc++.h>
using namespace std;
int n,t,ret;
int main(){
	cin>>n;
	for(int i=0;i<5;i++){
		cin>>t;
		if(t==n)ret++;
	}
	cout<<ret;
}