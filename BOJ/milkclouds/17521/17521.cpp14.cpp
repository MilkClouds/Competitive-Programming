#include <bits/stdc++.h>
#define rep(a,b,c) for(int a=b;a<c;a++)
#define x first
#define y second
using namespace std;
using ll=long long;
using pii=pair<int,int>;

// since 7:25

ll n,W,s[16],coin;
int main(){
	cin>>n>>W;
	rep(i,0,n)cin>>s[i];
	rep(i,0,n-1){
		if(s[i+1]>s[i]) //상승세! 사자
			coin+=W/s[i], W=W%s[i];
		else // 현금으로!
			W+=s[i]*coin, coin=0;
		//printf("%d %d\n",coin,W);
	}
	cout<<(W+s[n-1]*coin);
}