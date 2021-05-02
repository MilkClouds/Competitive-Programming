#include <iostream>
using namespace std;

const int a[]={31,28,31,30,31,30,31,31,30,31,30,31};
const string name[]={"Wednesday","Thursday", "Friday", "Saturday", "Sunday","Monday", "Tuesday"};
int main(){
	int D,M;
	cin>>D>>M;
	int ret=D;
	while(--M){
		ret+=a[M-1];
	}
	cout<<name[ret%7];
}