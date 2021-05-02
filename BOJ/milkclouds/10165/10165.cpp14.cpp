#include <bits/stdc++.h>
using namespace std;

typedef tuple<int,int,int> tiii;
int save;
int N,M,a,b,lastEnd=-1,i,irrA=1e9,irrB;
vector<tiii> v;
vector<tiii> v_irr;
set<int> ans;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>N>>M;
	for(int i=1;i<=M;i++){
		cin>>a>>b;
		if(a>b){
		    irrA=min(irrA,a);
		    irrB=max(irrB,b);
		    v_irr.push_back({a,-(N+b),i});
		}
		else{
		    v.push_back({a,-b,i});
		}
	}
	sort(v.begin(),v.end());
	sort(v_irr.begin(),v_irr.end());
	for(auto cur:v){
	    tie(a,b,i)=cur;
	    b=-b;
	    if(irrA<=a) continue;
	    if(b<=irrB) continue;
	    if(b<=lastEnd)continue;
	    lastEnd=b;
	    ans.insert(i);
	}
	lastEnd=-1;
	for(auto cur:v_irr){
	    tie(a,b,i)=cur;
	    b=-b;
	    if(b<=lastEnd)continue;
	    lastEnd=b;
	    ans.insert(i);
	}
	for(auto i:ans)cout<<i<<" ";
}