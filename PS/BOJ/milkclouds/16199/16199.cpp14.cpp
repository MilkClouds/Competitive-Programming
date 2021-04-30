#include <bits/stdc++.h>

using namespace std;

int a,b,c,x,y,z;
int main(){
	cin>>a>>b>>c;
	cin>>x>>y>>z;
	cout<<x-a+((y>b or (y==b and z>=c))?1:0)-1<<'\n';
	cout<<x-a+1<<'\n';
	cout<<x-a<<'\n';
}