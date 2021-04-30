#include <bits/stdc++.h>
#define rep(i,a,b) for(int i = a; i < b; i++)
using namespace std;
int T,a[9][9],t,t2,flag;
int main(){
	cin>>T;
	rep(TC,1,T+1){
		flag=0;
		rep(i,0,9)rep(j,0,9){cin>>a[i][j];a[i][j]=a[i][j]*a[i][j];}
		rep(i,0,9){
			t=t2=0;
			rep(j,0,9){
				t+=a[i][j];
				t2+=a[j][i];
			}
			if(t^285||t2^285){flag=1;break;}
		}
		rep(i,0,9){
			t=0;
			rep(j,0,3)rep(k,0,3)t+=a[(i/3)*3+j][(i%3)*3+k];
			if(t^285){flag=1;break;}
		}
		printf("Case %d: %s\n", TC, flag?"INCORRECT":"CORRECT");
	}
}