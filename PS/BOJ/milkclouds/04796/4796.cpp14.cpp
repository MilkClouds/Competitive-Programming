#include <bits/stdc++.h>
using namespace std;
int L,P,V,i;
int main(){
	cin>>L>>P>>V;
	while(L+P+V){
		printf("Case %d: %d\n",++i,(V/P)*L+min(L,V%P));
		cin>>L>>P>>V;
	}
}