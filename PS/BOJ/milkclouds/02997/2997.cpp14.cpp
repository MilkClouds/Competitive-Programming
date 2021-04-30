#include <bits/stdc++.h>
using namespace std;

int a,b,c;
int main(){
	ios_base::sync_with_stdio(0);
	cin>>a>>b>>c;
	if(a>b)swap(a,b);
	if(b>c)swap(b,c);
	if(a>b)swap(a,b);
	if(2*b==a+c)cout<<c-b+c;
	else{
		if((b-a)*2+b==c)cout<<(b-a)+b;
		else cout<<(c-b)+a;
	}
}
