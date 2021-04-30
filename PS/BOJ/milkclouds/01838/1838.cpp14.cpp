#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
vector<int> v;
vector<int> k;
int main()
{
    scanf("%d",&n);
    v.resize(n,0);
    for(int i=0;i<n;++i){
        int x;
        scanf("%d",&x);
        v[i] = x;
    }
    k=v;
    sort(v.begin(),v.end());
    int ans = 0;
    for(int i=0;i<n;++i){
    	//cout<<upper_bound(v.begin(),v.end(),k[i])-v.begin()<<endl;
        ans = max(ans, i-(int)(upper_bound(v.begin(),v.end(),k[i])-v.begin())+1);
    }
    printf("%d",ans);
}