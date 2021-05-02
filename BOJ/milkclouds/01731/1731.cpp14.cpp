#include <bits/stdc++.h>
using namespace std;

int N,a[50],be;
int main(){
	cin>>N;
	for(int i=0;i<N;i++)cin>>a[i];
	int c=a[1]-a[0];
	for(int i=2;i<N;i++){
		if(a[i]-a[i-1]!=c){be=1;break;}
	}
	cout<<(be?a[1]/a[0]*a[N-1]:a[N-1]+c);
}