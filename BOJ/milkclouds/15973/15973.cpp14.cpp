#include <bits/stdc++.h>
using namespace std;
struct rec{
	long long a,b,c,d;
	void in(){cin>>a>>b>>c>>d;}
	bool point(rec o){
		if((o.a==c && o.b==d)||(c==o.a && b==o.d)||(a==o.c && d==o.b)||(o.c==a && o.d==b))return 1;return 0;
	}
	void exec(rec o){
		int p=-max(a,o.a)+min(c,o.c);
		int q=-max(b,o.b)+min(d,o.d);
		if(p<0||q<0)cout<<"NULL";
		else if(p==0||q==0)cout<<"LINE";
		else cout<<"FACE";
	}
} r[2];
int main(){
	r[0].in();r[1].in();
	if(r[0].point(r[1])){cout<<"POINT";}
	else r[0].exec(r[1]);
}