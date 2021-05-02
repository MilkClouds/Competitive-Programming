#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll a,b;
int main(){
	cin >> a >> b;
	if( a+1 == b) {
		printf("%d %d", a, b);
	}
	else if (a == b) {
		printf("%d1 %d2", a, b);
	} else cout<<-1;
}