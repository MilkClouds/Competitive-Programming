#include <iostream>
using namespace std;

int a,b,c,r;

int main(){
	for(int i=0;i<3;i++){
		cin>>a>>b>>c;
		r=(a*60+b)*60+c;
		cin>>a>>b>>c;
		r=(a*60+b)*60+c-r;
		printf("%d %d %d\n",r/3600,r/60%60,r%60);
	}
}