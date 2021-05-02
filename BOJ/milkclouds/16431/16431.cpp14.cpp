#include <bits/stdc++.h>
using namespace std;

int a,b,c,d,e,f,be,da;
int main()
{
	scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f);
	a=abs(e-a);c=abs(e-c);
	b=abs(f-b);d=abs(f-d);
	be=max(a,b);
	da=c+d;
	cout<<(be==da?"tie":(be>da?"daisy":"bessie"));
	return 0;
}