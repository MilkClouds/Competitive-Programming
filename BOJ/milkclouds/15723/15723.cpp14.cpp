#include <bits/stdc++.h>
#define rep(a,b,c) for(int a=b;a<c;a++)
using namespace std;

int N,dist[26][26],M;
char P,T,Q;

inline int conv(char s){return s-'a';}

int main(){
	cin>>N;
	fill(dist[0],dist[26],1);
	rep(i,0,N){
		scanf("%s is %s",&P,&Q);
		dist[conv(P)][conv(Q)]=0;
	}
	rep(m,0,26)rep(s,0,26)rep(e,0,26)
		if(dist[s][e]>dist[s][m]+dist[m][e])dist[s][e]=0;
	cin>>M;
	while(M--){
		scanf("%s is %s",&P,&Q);
		printf("%c\n", dist[conv(P)][conv(Q)]?'F':'T');
	}
}