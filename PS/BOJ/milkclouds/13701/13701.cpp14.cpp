#include <bits/stdc++.h>

using namespace std;

int t;
unsigned int bit[1048577];
int main(){
	const int mod=1<<5;
	while(~scanf("%d",&t)){
		if(bit[t/mod]&(1<<(t%mod)))continue;
		bit[t/mod]|=1<<(t%mod);
		printf("%d ",t);
	}
}