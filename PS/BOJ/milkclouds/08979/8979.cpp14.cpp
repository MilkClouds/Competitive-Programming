#include <cstdio>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
 
typedef struct medal{
    int q;
    int g;
    int s;
    int b;
}medal;
 
int n,k;
 
 
bool comp(medal a, medal b){
    if(a.g!=b.g)
        return a.g>b.g;
    else if(a.s!=b.s)
        return a.s>b.s;
    else if(a.b!=b.b)
        return a.b>b.b;
    else{
        return a.q==k;
    }
}
 
vector<medal> v;
 
int main(){
 
    int z,g,s,b;
    medal zz;
 
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++){
        scanf("%d%d%d%d",&zz.q,&zz.g,&zz.s,&zz.b);
        v.push_back(zz);
    }
 
    sort(v.begin(),v.end(),comp);
    for(int i=0;i<n;i++){
        if(v[i].q==k){
            printf("%d",i+1);
            return 0;
        }
    }
}