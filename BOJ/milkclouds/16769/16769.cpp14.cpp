#include <bits/stdc++.h>
#define rep(a,b,c) for(int a=b;a<c;a++)
using namespace std;
int c[3],m[3],i,j;
int main(){
	rep(i,0,3)cin>>c[i]>>m[i];
	rep(_,0,100){
		j=(i+1)%3;
		if(c[j]-m[j]>=m[i]){
			m[j]+=m[i];
			m[i]=0;
		}
		else{
			m[i]-=c[j]-m[j];
			m[j]=c[j];
		}
		i=j;
	}
	printf("%d\n%d\n%d",m[0],m[1],m[2]);
}