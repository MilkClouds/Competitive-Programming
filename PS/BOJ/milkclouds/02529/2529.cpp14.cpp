#include <iostream>
using namespace std;
int N,M,m;
char a[10];
inline bool bi(int n,int i){return n&(1<<i);}
bool solve(long long n,int cur,int v){
	if(cur==N){
		if(to_string(n).size()==N)cout<<0;
		cout<<n<<endl;
		return 1;
	}
	bool ret=0;
	if(a[cur]=='<'){
		for(int i=n%10+1;i<10;i++){
			if(ret)break;
			if(!bi(v,i))ret|=solve(n*10+i,cur+1,v|(1<<i));
		}
	}
	if(a[cur]=='>'){
		for(int i=0;i<n%10;i++){
			if(ret)break;
			if(!bi(v,i))ret|=solve(n*10+i,cur+1,v|(1<<i));
		}
	}
	return ret;
}
bool solve2(long long n,int cur,int v){
	if(cur==N){
		if(to_string(n).size()==N)cout<<0;
		cout<<n<<endl;
		return 1;
	}
	bool ret=0;
	if(a[cur]=='<'){
		for(int i=9;i>n%10;i--){
			if(ret)break;
			if(!bi(v,i))ret|=solve2(n*10+i,cur+1,v|(1<<i));
		}
	}
	if(a[cur]=='>'){
		for(int i=n%10-1;~i;i--){
			if(ret)break;
			if(!bi(v,i))ret|=solve2(n*10+i,cur+1,v|(1<<i));
		}
	}
	return ret;
}
int main(){
	cin>>N;
	for(int i=0;i<N;i++)cin>>a[i];
	for(int i=9;~i;i--)if(solve2(i,0,1<<i))break;
	for(int i=0;i<10;i++)if(solve(i,0,1<<i))break;
}