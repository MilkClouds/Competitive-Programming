#include <bits/stdc++.h>
using namespace std;

vector<int> adj[10001];
vector<int> sccI;
vector<int> sccId[10001];
vector<int> discovered;
stack<int> st;
int sccCounter,vertexCounter;
int A,B,V,E;

int scc(int here){
	int ret=discovered[here]=vertexCounter++;
	st.push(here);
	for(auto there:adj[here]){
		if(discovered[there]==-1)
			ret=min(ret,scc(there));
		else if(sccI[there]==-1)
			ret=min(ret,discovered[there]);
	}
	if(ret==discovered[here]){
		while(true){
			int t=st.top();st.pop();
			sccI[t]=sccCounter;
			sccId[sccCounter].push_back(t);
			if(t==here)break;
		}
		++sccCounter;
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin>>V>>E;
	for(int i=0;i<E;i++){
		cin>>A>>B;
		adj[A].push_back(B);
	}
	sccI=discovered=vector<int>(V+1,-1);
	sccCounter=vertexCounter=0;
	for(int i=1;i<=V;i++)if(discovered[i]==-1) scc(i);
	cout<<sccCounter<<"\n";
	for(int i=0;i<sccCounter;i++) sort(sccId[i].begin(),sccId[i].end());
	sort(sccId,sccId+sccCounter,[](vector<int> a,vector<int> b){return a[0]<b[0];});
	for(int i=0;i<sccCounter;i++){
		for(int e:sccId[i]) cout<<e<<" ";
		cout<<"-1\n";
	}
}