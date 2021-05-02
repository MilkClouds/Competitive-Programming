#include <bits/stdc++.h>
using namespace std;
int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	int a, b, c, p, q, r;
	cin >> a >> b >> c >> p >> q >> r;
	cout << max(0, p - a) + max(0, q - b) + max(0, r - c);
}