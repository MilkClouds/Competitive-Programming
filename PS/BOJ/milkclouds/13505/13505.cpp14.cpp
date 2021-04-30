#include <bits/stdc++.h>
#define rep(a,b,c) for(int a=b;a<c;a++)
using namespace std;

const int MAX=1e5+5;

int N,A[MAX],ans;
char c[33];

struct Trie{
	Trie* nxt[2];
	Trie(){
		memset(nxt,0,sizeof(nxt));
	}
	~Trie(){
		rep(i,0,2)if(nxt[i])delete(nxt[i]);
	}
	void insert(const char* key){
		if(*key){
			int next=*key-'0';
			if(!nxt[next])nxt[next]=new Trie;
			nxt[next]->insert(key+1);
		}
	}
	void query(char* key){
		if(*key){
			int next=*key-'0'; next^=1;
			if(nxt[next]){
				*key='1';
				nxt[next]->query(key+1);
			}
			else{
				*key='0';
				nxt[next^1]->query(key+1);
			}
		}
	}
} Root;

int main(){
	cin>>N;
	rep(i,0,N){cin>>A[i];
		rep(j,0,32){
			c[31-j]=((A[i]&(1<<j))>0)+'0';
		}
		Root.insert(c);
	}
	rep(i,0,N){
		rep(j,0,32){
			c[31-j]=((A[i]&(1<<j))>0)+'0';
		}
		Root.query(c);
		char *t=c;
		int x=0;
		while(*t){
			x=x*2+*t-'0';
			t++;
		}
		ans=max(ans,x);
	}	
	cout<<ans;
}