#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int N,h,ret,a[1000005];
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>N;
	while(N--){
		cin>>h;
		if(a[h+1]==0)ret+=1;else a[h+1]--;
		a[h]++;
	}
	cout<<ret;
}