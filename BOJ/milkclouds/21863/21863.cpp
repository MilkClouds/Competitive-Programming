#include "CUSTOM_BITSET.h"

CUSTOM_BITSET sum(CUSTOM_BITSET& a, CUSTOM_BITSET& b, int d){
	CUSTOM_BITSET c = a;
	c &= b;
	c <<= 1; c.setbit(0, 0);
	a ^= b;
    if(d == 0) return a;
	return sum(a, c, d - 1);
}

int __builtout_popcount(CUSTOM_BITSET& a){
	for(int i = 0, shift = 1; i < 16; i++, shift <<= 1){
        CUSTOM_BITSET mask;
        for(int j = 0, c = 1; j < MAX_BIT_N; j += 1 << i, c ^= 1){
            for(int k = 0; k < (1 << i); k++) mask.setbit(j + k, c);
        }
		CUSTOM_BITSET b = a;
        b &= mask;
        a >>= shift;
        a &= mask;
        a = sum(a, b, i + 1);
	}
    int ans = 0;
    for(int i = 0; i < 17; i++) if(a.getbit(i)) ans |= 1 << i;
    return ans;
}