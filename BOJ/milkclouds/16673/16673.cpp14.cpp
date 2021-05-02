#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int n,t;

int main(){
	// cin.tie(0);ios_base::sync_with_stdio(0);
	int n,a,b;
	cin>>n>>a>>b;
	// a*x+b*x**2
	cout<<n*(n+1)/2*a+b*n*(n+1)*(2*n+1)/6;
}