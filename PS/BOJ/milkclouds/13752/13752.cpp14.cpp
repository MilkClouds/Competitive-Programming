#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int n,t;

int main(){
	cin.tie(0);ios_base::sync_with_stdio(0);
	cin>>n;
	while(n--){
		cin>>t;
		while(t--)
			cout<<'=';
		cout<<"\n";
	}
}