#include <bits/stdc++.h>
using namespace std;
int T,a,b,c,x[3];
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>T;
	for(int i=1;i<=T;i++){
		cin>>a>>b>>c;
		x[0]=a;x[1]=b;x[2]=c;
		sort(x,x+3);
		if(x[2] >= x[0]+x[1]){printf("Case #%d: invalid!\n",i);continue;}
		if(a==b&&b==c)printf("Case #%d: equilateral\n",i);
		else if(a==b||b==c||c==a)printf("Case #%d: isosceles\n",i);
		else printf("Case #%d: scalene\n",i);
	}
}
