#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int a,b;
int main(){
	cin >> a >> b;
	if(a == 9 && b == 1) {printf("9 10"); return 0;}
	if( a+1 == b) {
		printf("%d %d", a, b);
	}
	else if (a == b) {
		printf("%d1 %d2", a, b);
	} else cout<<-1;
}