#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,e[1000001]={0},max=0,t;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>t;
		e[t]=e[t-1]+1;
		max=max<e[t]?e[t]:max;
		}
	cout<<n-max;
	return 0;
}