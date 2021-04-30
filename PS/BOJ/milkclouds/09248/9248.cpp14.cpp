#include <bits/stdc++.h>
using namespace std;
const int MAX=500005, MAX_N=100005;

int SA[MAX],g[MAX],tg[MAX],t;
int r[MAX],LCP[MAX];
bool cmp(int x,int y){
    return g[x]^g[y] ? g[x]<g[y] : g[x+t]<g[y+t];
}
void build_SA(const char* S){
    t=1;
    int N=(int)strlen(S);
    for(int i=0;i<N;i++){
        SA[i]=i;
        g[i]=S[i]-'a';
    }
    while(t<=N){
        g[N]=-1;
        sort(SA,SA+N,cmp);
        tg[SA[0]]=0;
        for(int i=1;i<N;i++)
            tg[SA[i]]=tg[SA[i-1]]+cmp(SA[i-1], SA[i]);
        for(int i=0;i<N;i++) g[i]=tg[i];
        t<<=1;
    }
}
void build_LCP(const char* S){
	int N=(int)strlen(S),l=0;
	for(int i=0;i<N;i++) r[SA[i]]=i;
	for(int i=0;i<N;i++){
		int k=r[i];
		if(k){
			int j=SA[k-1];
			while(S[j+l]==S[i+l])l++;
			LCP[k]=l;
			if(l)l--;
		}
	}
}

//int N;
//string S[MAX_N];
char P[MAX];

int main(){
//    cin>>N;
//    for(int i=0;i<N;i++)
//        cin>>S[i];
    cin>>P;
    build_SA(P);
    build_LCP(P);
    for(int i=0;P[i];i++)cout<<SA[i]+1<<" ";
    cout<<"\nx ";
    for(int i=1;P[i];i++)cout<<LCP[i]<<" ";
}