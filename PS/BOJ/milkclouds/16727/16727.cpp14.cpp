#include <bits/stdc++.h>
using namespace std;
int a,b,c,d;
int main(){
	cin>>a>>b>>c>>d;
	if(a+d>b+c || (a+d==b+c && d>b))cout<<"Persepolis";
	else if (a+d<b+c || (a+d==b+c && d<b))cout<<"Esteghlal";
	else cout<<"Penalty";
}