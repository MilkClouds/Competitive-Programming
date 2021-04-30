#include <bits/stdc++.h>
using namespace std;
int main(){
	int a,b=-1000000;
	while(~scanf("%d",&a)){
		if(a<b){cout<<"Bad";return 0;}
		b=a;
	}
	cout<<"Good";
}