#include <iostream>
#include <cmath>
using namespace std;

int n,m;
int main(){
	cin>>n>>m;
	int mi=123456789,sum=0;
	for(int i=sqrt(n);i<=sqrt(m);i++){
		if(n<=pow(i,2) and pow(i,2)<=m){
			sum+=pow(i,2);mi=min(mi,(int)pow(i,2));
		}
	}
	if(sum==0){
	    cout<<-1;
	    return 0;
	}
	cout<<sum<<endl<<mi<<endl;
}