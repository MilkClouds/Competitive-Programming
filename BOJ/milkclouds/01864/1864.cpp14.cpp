#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
typedef long long lld;
lld convert(char a){
    char t[] = "/-\\(@?>&%/\0";
    for(int i = 0 ; t[i] != NULL ; i++)
        if(t[i]==a) return i-1; 
}
 
int main(){
    while(1){
        lld res = 0;
        char str[1111];        
        scanf("%s",str);
        if(str[0] == '#') break;               
        for(int i = strlen(str)-1, co = 0 ; i >= 0 ; i--){
            lld coef = convert(str[co++]);
            res += coef * pow(8,i);            
        } 
        printf("%lld\n",res);
    }
    return 0;
}
 

