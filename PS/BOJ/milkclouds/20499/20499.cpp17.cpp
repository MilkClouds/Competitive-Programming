#include <bits/stdc++.h>

using namespace std;
typedef long long ll;



int main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
	ll K, D, A;
	scanf("%d/%d/%d", &K, &D, &A);
	if((K + A < D) or (D == 0)) cout << "hasu";
	else cout << "gosu";
}