#include <bits/stdc++.h>
using namespace std;
 
int n,m,a[205],b[205];
unordered_map<int,bool> mm;
int main(){
    cin>>n;
    for(int i=0;i<n;i++){cin>>a[i];mm[a[i]]=1;}
    cin>>m;
    for(int i=0;i<m;i++){cin>>b[i];mm[b[i]]=1;}
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mm[a[i]+b[j]]==0){
                cout<<a[i]<<" "<<b[j];
                return 0;
            }
        }
    }
}
