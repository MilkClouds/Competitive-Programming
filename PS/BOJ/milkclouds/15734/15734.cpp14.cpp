#include <iostream>
using namespace std;


int main(){
	cin.tie(0);
	int a,b,c,t;
	cin>>a>>b>>c;
	if(a>b)swap(a,b);
	t=b-a;
	if(c<=t)cout<<(a+c)*2;
	else cout<<2*b+(c-t)/2*2;
}