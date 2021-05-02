#include <stdio.h>
int main()
{
    int a[5];
    for(int i=0;i<5;++i)scanf("%d",&a[i]);
    for(int i=1;i<5;++i){
        for(int j=1;j<5;++j){
            if(a[j-1]>a[j]){
                int t=a[j-1];
                a[j-1]=a[j];
                a[j]=t;
                for(int k=0;k<5;++k)printf("%d ",a[k]);
                puts("");
            }
        }
        
    }
}