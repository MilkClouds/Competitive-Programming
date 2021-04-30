#include<bits/stdc++.h>
#define rep(a,b,c) for(int a=b;a<c;a++)
using namespace std;
int N,p,i;
vector<int> v;
int main(){
	cin>>N;
	rep(i,1,N+1) v.push_back(i);p--;
	while(v.size()>1){
		i++;
		p=(p+(long long)i*i*i)% v.size();
		v.erase(v.begin() + p);p--;
	}
	cout<<v[0];
}