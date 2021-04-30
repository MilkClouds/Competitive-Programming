#include <bits/stdc++.h>
using namespace std;
typedef pair<long long,int> pii;
long long T,n,h,ans;
stack<pii> st;
int main(){
	while(scanf("%d",&n) && n){
		ans=0;
		for(int i=0;i<n;i++){
			scanf("%d",&h);int idx=i;
			while(!st.empty() and st.top().first>=h){
				ans=max(ans,st.top().first*(i-st.top().second));
				idx=st.top().second;
				st.pop();
			}
			st.push({h,idx});
		}
		while(!st.empty()){
			ans=max(ans,(n-st.top().second)*st.top().first);
			st.pop();
		}
		printf("%lld\n",ans);
	}
}