#include<bits/stdc++.h>
using namespace std;
const int MAX=2e6;
int arr[MAX];
vector<int> pn={2};
void erato(){
	for(int i=3;i<MAX;i+=2){
		if(arr[i])continue;
		pn.push_back(i);
		arr[i]=1;
		for(long long j=1LL*i*i;j<MAX;j+=i)arr[j]=1;
	}
}
inline bool pal(int K){
	int T=K;
	string S;
	while(T){
		S+=to_string(T%10);
		T/=10;
	}
	for(int i=0;i<S.size();i++){
		if(S[i]!=S[S.size()-i-1])return 0;
	}
	return 1;
}
int N;
int main(){
	cin>>N;
	erato();
	auto pos=lower_bound(pn.begin(),pn.end(),N);
	while(!pal(*pos))pos++;
	cout<<*pos;
}