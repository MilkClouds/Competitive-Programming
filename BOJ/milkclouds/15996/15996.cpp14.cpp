#include <bits/stdc++.h>
using namespace std;
int N,A,r;
int main(){
	cin>>N>>A;
	while(N)
	{
		r+=N/A;
		N/=A;
	}
	cout<<r;
}