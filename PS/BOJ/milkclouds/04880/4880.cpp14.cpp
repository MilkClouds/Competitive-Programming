#include<cstdio>
int main(){
    int a[3];
    for(;;){
        scanf("%d%d%d",&a[0],&a[1],&a[2]);
        if(a[0]==0&&a[1]==0&&a[2]==0) break;
        if(a[1]-a[0] == a[2]-a[1]) printf("AP %d\n",a[2]+a[2]-a[1]);
        else printf("GP %d\n",a[2]*a[2]/a[1]);
    }
    return 0;
}

