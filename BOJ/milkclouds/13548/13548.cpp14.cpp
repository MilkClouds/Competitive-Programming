#include <bits/stdc++.h>
using namespace std;
const int MAX=1e5+2;
int N,A[MAX],M,x,y,sz,save[MAX],cur,m[MAX],m2[MAX];
typedef tuple<int,int,int> ti;
ti Q[MAX];
void add(int i){
	m2[m[A[i]]]--;
	m[A[i]]++;
	m2[m[A[i]]]++;
	cur=max(cur,m[A[i]]);
}
void erase(int i){
	m2[m[A[i]]]--;
	if(m[A[i]]==cur && m2[m[A[i]]]==0)cur--;
	m[A[i]]--;
	m2[m[A[i]]]++;
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>N;sz=sqrt(N);
	for(int i=1;i<=N;i++)cin>>A[i];
	cin>>M;
	for(int i=0;i<M;i++){
		cin>>x>>y;
		Q[i]={i,x,y};
	}
	sort(Q,Q+M,[](ti A,ti B){
		auto [a,b,c]=A;auto [i,j,k]=B;
		return b/sz^j/sz ? b/sz<j/sz : c<k;
	});
	auto [a,b,c]=Q[0];
	for(int i=b;i<=c;i++)add(i);
	save[a]=cur;int lastb=b,lastc=c;
	for(int i=1;i<M;i++){
		auto [a,b,c]=Q[i];
		for(int i=b;i<lastb;i++)add(i);
		for(int i=lastc;i<c;i++)add(i+1);
		for(int i=lastb;i<b;i++)erase(i);
		for(int i=c;i<lastc;i++)erase(i+1);
		lastb=b;
		lastc=c;
		save[a]=cur;
	}
	for(int i=0;i<M;i++)cout<<save[i]<<"\n";
}