#include<bits/stdc++.h>
using namespace std;
const int MAX=5e5+1;
// since 3:58
int N,a[MAX];
deque<int> ans;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>N;
    for(int i=0;i<N;i++)cin>>a[i];
    sort(a,a+N);
    for(int i=N-1;~i;i--){
        if(i&1)ans.push_front(a[i]);
        else ans.push_back(a[i]);
    }
    for(int i=0;i<N;i++)cout<<ans[i]<<" ";
    return 0;
}