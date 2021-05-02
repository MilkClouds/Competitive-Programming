#include <bits/stdc++.h>
using namespace std;
int N,K,a[1005],A,B,idx,flag;
string s;
int c(string u){
    int ret=0;
    for(int i=0;i<K;i++)ret+=(s[i]=='1')*(1<<(K-i-1));
    return ret;
}
int dist(int u,int v){
    int t=u^v;
    if(t==0)return 0;
    if((t&(t-1))==0)return 1;
    return 100;
}
int main(){
	cin>>N>>K;
	for(int i=0;i<N;i++){cin>>s;a[i]=c(s);}
	cin>>A>>B;A--;B--;
    queue<int> Q;
	Q.push(A);
	vector<bool> visit(N+1);visit[A]=1;
	vector<int> prev(N+1);
	while(!Q.empty()){
		int sz=Q.size();idx++;
		for(int i=0;i<sz;i++){
			int u=Q.front();Q.pop();
			if(u==B){flag=1;break;}
			for(int v=0;v<N;v++){
				if(visit[v])continue;
				if(dist(a[u],a[v])==1){
					visit[v]=1;
					prev[v]=u;
					Q.push(v);
				}
			}
		}
		if(flag)break;
	}
	if(flag){
		stack<int> S;
		for(int i=B;i!=A;i=prev[i])S.push(i);cout<<A+1<<" ";
		while(!S.empty())cout<<S.top()+1<<" ",S.pop();
	}
	else cout<<-1;
}