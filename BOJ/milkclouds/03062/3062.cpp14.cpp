#include <iostream>
#include <cmath>
using namespace std;
int t,n;
int rev(int n){
	int ret=0,idx=1;
	int zarisu=1;
	while(pow(10,zarisu)<=n)zarisu++;
	while(n){
		ret+=pow(10,zarisu-idx)*(n%10);
		n/=10;
		idx++;
	}
	return ret;
}
string check(int n){
    return (rev(n)==n)?"YES":"NO";
}
int main(){
	cin>>t;
	while(t--){
		cin>>n;
		cout<<check(n+rev(n))<<endl;
	}
}