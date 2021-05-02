#include <iostream>
#include <algorithm>
using namespace std;

int a[2000000];
int main()
{
	ios_base::sync_with_stdio(0);
	int n,m;
	cin>>n>>m;
	int l=n+m;
	for(int i=0;i<l;i++)cin>>a[i];
	sort(a,a+n+m);
	for(int i=0;i<l;i++)cout<<a[i]<<' ';
	return 0;
}