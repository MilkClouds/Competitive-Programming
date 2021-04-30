#include <bits/stdc++.h>
using namespace std;

map<int,int> m;
int N,R,L,T,a,b;

int main(){
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>a>>b;
		m[a]=b;
	}
	cin>>R;
	while(R--){
		cin>>L;
		int fail=0,A[100];
		for(int i=0;i<L;i++){cin>>A[i];if(m.find(A[i])==m.end())fail=1;}
		if(fail)cout<<"YOU DIED";
		else for(int i=0;i<L;i++) cout<<m[A[i]]<<" ";
		cout<<"\n";
	}
}