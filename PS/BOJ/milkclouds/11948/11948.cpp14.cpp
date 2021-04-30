#include <iostream>
#include <algorithm>
using namespace std;
int v[6];
int main(){
	for(int i=0;i<6;i++)cin>>v[i];
	sort(v,v+4);sort(v+4,v+6);
	cout<<v[1]+v[2]+v[3]+v[5];
}