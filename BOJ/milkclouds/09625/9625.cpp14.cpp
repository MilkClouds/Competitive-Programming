#include <iostream>
using namespace std;
int d[2],p[2]={1,0},K;
int main(){
	cin>>K;
	while(K--){
		d[0]=p[1];d[1]=p[0]+p[1];
		p[0]=d[0];p[1]=d[1];
	}
	printf("%d %d",d[0],d[1]);
}