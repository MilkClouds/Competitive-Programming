#include <iostream>
#include <string>
using namespace std;

int a(int x){
    if(x>=0)return x/(-2);
    return x%2 ? x/(-2)+1 : x/(-2);
}
int b(int x){
    if(x>=0)return x%(-2);
    return x+2*a(x);
}

string conv(int n){
	string ret;
	while(n){
		ret=to_string(b(n))+ret;
		n=a(n);
	}
	return ret;
}

int main(){
	int n;
	cin>>n;
	if(n==0){
	    cout<<0;
	    return 0;
	}
	cout<<conv(n);
}