#include <iostream>
#include <algorithm>
using namespace std;
int n,t;
int main(){
	cin.tie(0);ios_base::sync_with_stdio(0);
	cin>>n;
	t=n;
	int a[1000000];
	while(t--)
		cin>>a[t];
	sort(a,a+n,greater<int>());
	while(n--)
		cout<<a[n]<<"\n";
}