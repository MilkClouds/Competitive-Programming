#include <bits/stdc++.h>
using namespace std;

int N;
string st,t;
map<string,bool> mm;
int main(){
	ios_base::sync_with_stdio(0);
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>st>>t;
		mm[st]^=1;
	}
	for(auto iter=mm.rbegin();iter!=mm.rend();iter++)
	if(iter->second)cout<<iter->first<<"\n";
}