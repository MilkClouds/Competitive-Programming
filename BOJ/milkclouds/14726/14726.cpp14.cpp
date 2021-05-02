#include <stdio.h>
int main() {//
	int t;
	for (scanf("%d", &t); t--;) {
		int sum = 0;
		for (int i = 0, a; i < 16; i++) {
			scanf("%1d", &a);
			if (!(i % 2)) a *= 2;
			sum += a / 10 + a % 10;
		}
		if (sum % 10) puts("F");
		else puts("T");
	}
	return 0;
}