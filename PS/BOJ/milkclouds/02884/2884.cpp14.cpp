#include <iostream>
using namespace std;

int h,m,r;
int main(){
	cin>>h>>m;
	r=(h*60+m+24*60-45)%(24*60);
	printf("%d %d",r/60,r%60);
}