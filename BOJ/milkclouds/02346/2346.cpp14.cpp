#include <bits/stdc++.h>
#define x first
#define y second
#define pb push_back
#define all(x) x.begin(), x.end()
#define rep(a,b,c) for(int a=b;a<c;a++)
using namespace std;

int N,t,p,v[1005];

int main(){
	cin>>N;
	rep(i,0,N)cin>>v[i];
	rep(i,1,N){
		cout<<p+1<<' ';
		int d=(v[p]>0)-(v[p]<0),l=abs(v[p]);v[p]=0;
		for(int cnt=0;cnt<l;p=(N+p+d)%N){
			if(v[(N+p+d)%N]) cnt++;
		}
	}
	cout<<p+1;
}