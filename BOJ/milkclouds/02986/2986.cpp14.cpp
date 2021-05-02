#include <bits/stdc++.h>
using namespace std;
int n;
int main(){
	cin>>n;
	int b=sqrt(n);
	for(int i=2;i<=b;i++)if(n%i==0){cout<<n-n/i;return 0;}
	cout<<n-1;
}