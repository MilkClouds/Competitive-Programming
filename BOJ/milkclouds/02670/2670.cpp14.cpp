#include <iostream>
using namespace std;

int N;
double t=1,MAX,a;

int main(){
	cin>>N;
	while(N--){
		cin>>a;
		t*=a;
		MAX=max(MAX,t);
		if(t<1)t=1;
	}
	printf("%.3lf\n",MAX);
}