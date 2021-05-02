#include <bits/stdc++.h>
using namespace std;

int n,a[200002],b[200002];
vector<int> inc,decr;

bool solution(int i){
	if(i==n){
		return 1;
	}
	if(inc.empty()||inc.back()<a[i]){
		inc.push_back(a[i]);
		b[i]=0;
		if(solution(i+1))return 1;
		inc.pop_back();
	}
	if(decr.empty()||decr.back()>a[i]){
		decr.push_back(a[i]);
		b[i]=1;
		if(solution(i+1))return 1;
		decr.pop_back();
	}
	return 0;
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	if(solution(0)){
		cout<<"YES\n";
		for(int i=0;i<n;i++)cout<<b[i]<<" ";
	}
	else cout<<"NO";
}