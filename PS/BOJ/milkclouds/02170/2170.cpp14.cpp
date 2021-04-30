#include <bits/stdc++.h>
using namespace std;

int N,a,b,ret,last,par,i,j;
typedef pair<int,int> pii;
vector<pii> v;

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>a>>b;
		v.push_back({a,1});
		v.push_back({b,-1});
	}
	sort(v.begin(), v.end());
	for(pii t:v){
		i=t.first,j=t.second;
		if(j==-1){
			par--;
			if(par==0)ret+=i-last;
		}
		else{
			if(par==0)last=i;
			par++;
		}
	}
	cout<<ret;
}