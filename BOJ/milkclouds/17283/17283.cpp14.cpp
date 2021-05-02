#include <bits/stdc++.h>
#define rep(a,b,c) for(int a=b;a<c;a++)
using namespace std;

int L,R;
long long ans,i;
int main(){
	cin>>L>>R;
	while(L*R/100>5){i++;
		L=L*R/100;
		ans+=L*(1<<i);
	}
	cout<<ans;
}