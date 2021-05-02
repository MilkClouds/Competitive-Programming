#include <iostream>
using namespace std;

int n;
int main()
{
	cin>>n;
	n/=3;n--;
	cout<<n*(n-1)/2;
	return 0;
}