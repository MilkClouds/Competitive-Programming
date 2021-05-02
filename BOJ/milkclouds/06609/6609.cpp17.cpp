#include <bits/stdc++.h>
int main(){
        long long f,p,l,e,r,s,n,f_p,i;
        while(~scanf(" %ld %ld %ld %ld %ld %ld %ld", &f, &p, &l, &e, &r, &s, &n)){
                for(i=1;i<=n;i++){
                        f_p = f;
                        f=p/s;
                        p=l/r;
                        l=e*f_p;
                }
                printf("%ld\n", f);
        }
        return 0;
}