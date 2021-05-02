#include <bits/stdc++.h>
#define rep(a,b,c) for(int a=b;a<c;a++)
using namespace std;

const int INF=1e9;
int N,dist[53][53],cnt;
char P,T,Q;

inline int conv(char s){
	return s>='a'? s-'a'+26: s-'A';
}
inline char rev(int i){
	return i>=26?'a'+i-26:'A'+i;
}

int main(){
	cin>>N;
	fill(dist[0],dist[53],INF);
	rep(i,0,N){
		scanf("%s => %s",&P,&Q);
		dist[conv(P)][conv(Q)]=0;
	}
	rep(m,0,52)rep(s,0,52)rep(e,0,52)
		if(dist[s][e]>dist[s][m]+dist[m][e])dist[s][e]=0;
	rep(i,0,52)rep(j,0,52)
		if((i^j)&&dist[i][j]==0)cnt++;
	printf("%d\n",cnt);
	rep(i,0,52)rep(j,0,52)
		if((i^j)&&dist[i][j]==0)printf("%c => %c\n",rev(i),rev(j));
}