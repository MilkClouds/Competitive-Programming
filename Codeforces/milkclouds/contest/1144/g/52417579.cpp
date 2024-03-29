#include <bits/stdc++.h>
using namespace std;
const int MAX=2e5+1;
int N,a[MAX],ans[MAX];
vector<int> inc,decr;
bool able_inc(int i){
	return inc.empty() or inc.back()<i;
}
bool able_decr(int i){
	return decr.empty() or decr.back()>i;
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>N;
	for(int i=0;i<N;i++)
		cin>>a[i];
	for(int i=0;i<N;i++){
		if(able_inc(a[i])&&able_decr(a[i]))
		{
			if(i==N-1||a[i]<a[i+1]){
				inc.push_back(a[i]),ans[i]=0;
			} else {
				decr.push_back(a[i]),ans[i]=1;
			}
		} else if (able_inc(a[i])){
			inc.push_back(a[i]),ans[i]=0;
		} else if (able_decr(a[i])){
			decr.push_back(a[i]),ans[i]=1;
		} else {
			cout<<"NO";
			return 0;
		}
	}
	cout<<"YES\n";
	for(int i=0;i<N;i++){
		cout<<ans[i]<<" ";
	}
}