#include <bits/stdc++.h>
using namespace std;

double a,b,c;
int main(){
	cin>>a>>b>>c;
	printf("%d",(int)max(a*b/c,a/b*c));
}