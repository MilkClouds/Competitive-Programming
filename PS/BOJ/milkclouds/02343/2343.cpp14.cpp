#include <bits/stdc++.h>

using namespace std;

int N,M,a[100005];
int start=0,mid;
bool cmp(int st){
	int sum=0,tot=1;
	for(int i=0;i<N;i++){
		if(sum+a[i]>st){
			sum=0;
			if(++tot>M)return 1;
		}
		sum+=a[i];
	}
	return 0;
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>N>>M;
	for(int i=0;i<N;i++){cin>>a[i];start=max(start,a[i]);}
	int end=1e9+1;
	start--;
	while(start+1<end){
		mid=(start+end)/2;
		if(cmp(mid))start=mid;
		else end=mid;
	}
	cout<<end;
}