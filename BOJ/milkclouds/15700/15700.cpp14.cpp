#include <iostream>
#include <cmath>
using namespace std;

int main(){
	int n,m;
	cin>>n>>m;
	if(n&1 && m&1){
		cout<<((long)n*m-1)/2;
	}
	else
		cout<<(long)n*m/2;
	return 0;
}