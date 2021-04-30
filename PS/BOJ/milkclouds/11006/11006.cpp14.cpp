#include <iostream>
using namespace std;

int t,n,m;
int main(){
	cin>>t;
	while(t--){
		cin>>n>>m;
		cout<<m*2-n<<" "<<n-m<<'\n';
	}
}