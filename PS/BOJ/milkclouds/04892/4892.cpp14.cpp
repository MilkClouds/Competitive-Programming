#include <bits/stdc++.h>
using namespace std;
int n,idx;
int main(){
	while(idx++,scanf("%d",&n),n){
		printf("%d. %s %d\n",idx,n&1?"odd":"even",n/2);
	}
}