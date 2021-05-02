#include <bits/stdc++.h>
#define rep(a,b,c) for(int a=b;a<c;a++)
using namespace std;
using ld=long double;
int T,N;
ld x1,yy1,x2,y2;

struct Vector{
	int x,y;
	Vector():Vector(0,0){}
	Vector(ld x,ld y):x(x),y(y){}
	ld inner_product(Vector& o){
		return (x*o.x+y*o.y);
	}
	ld size(){return sqrt(x*x+y*y);}
};

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>T;
	const ld PI=acos(-1);
	while(T--){
		cin>>N;
		ld ret=0;
		rep(i,0,N){
			cin>>x1>>yy1>>x2>>y2;
			if(x1*y2==x2*yy1)continue;
			Vector a(x1,yy1),b(x2,y2);
			ret+=acos(a.inner_product(b)/a.size()/b.size());
		}
		ret/=2*PI;
		printf("%.05Lf\n",round(ret*1e5)/1e5);
	}
}