#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> v(10000);
int main(){
	ios_base::sync_with_stdio(0);
	cin>>N;
	for(int i=0;i<N;i++)cin>>v[i];
	if(prev_permutation(v.begin(),v.begin()+N)){
		for(int i=0;i<N;i++)cout<<v[i]<<" ";
	}
	else cout<<-1;
}