#include <bits/stdc++.h>
using namespace std;
bool arr[1<<11][1<<11];
int N;
//2*(1<<N)-3
void solve(int N,int x,int y){
	if(N==1){
		arr[x][y]=1;return;
	}
	int idx=0,S=2*(1<<N)-3,SY=(1<<N)-1,C=S;
	if(N&1){
		for(int i=0;i<S;i++)arr[x+i][y+SY-1]=1;
		while(C>0){
			C-=2;idx++;
			arr[x+idx][y+SY-idx-1]=arr[x+S-idx-1][y+SY-idx-1]=1;
			if((C-2)*2==(S-3))solve(N-1,x+idx+1,y+SY-idx-1);
		}
	}
	else {
		for(int i=0;i<S;i++)arr[x+i][y]=1;
		while(C>0){
			C-=2;idx++;
			arr[x+idx][y+idx]=arr[x+S-idx-1][y+idx]=1;
			if((C-2)*2==(S-3))solve(N-1,x+idx+1,y+idx-SY+(1<<N-1)+1);
		}
	}
}
int main()
{
	cin>>N;
	int S=2*(1<<N)-3,SY=(1<<N)-1;
	solve(N,0,0);
	for(int i=0;i<SY;i++){
		for(int j=0;j<(N%2?S-SY+i+1:S-i);j++)cout<<(arr[j][i]?'*':' ');
		if(i<SY-1)cout<<"\n";
	}
}