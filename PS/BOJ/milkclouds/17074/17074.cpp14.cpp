#include<iostream>
#define rep(a,b,c) for(int a=b;a<c;a++)
using namespace std;
const int MAX=1e5+5;
int N, a[MAX],b[MAX],c[MAX],cnt;

int main()
{  
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>N;
	rep(i,1,N+1)cin>>a[i];
	int t=a[1];
	b[0]=b[1]=c[N+1]=c[N]=1; a[0]=-1e9; a[N+1]=1e9;
	rep(i,2,N+1){
		b[i] = b[i-1] && ( a[i] >= t ) ; if(!b[i])break;
		t=a[i];
	}
	t=a[N];
	for(int i=N-1;i;i--){
		c[i] = c[i+1] && ( a[i] <= t ); if(!c[i])break;
		t=a[i];
	}
	rep(i,1,N+1){
		cnt+=b[i-1]&&c[i+1]&&(a[i-1]<=a[i+1]);
	}
	cout<<cnt;
}