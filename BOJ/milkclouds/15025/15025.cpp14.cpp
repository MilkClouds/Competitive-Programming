#include <bits/stdc++.h>
using namespace std;
int x,y;
int main(){
	cin>>x>>y;
	if(x==0&&y==0)cout<<"Not a moose";
	else if (x^y)cout<<"Odd "<<max(x,y)*2;
	else cout<<"Even "<<x*2;
} 