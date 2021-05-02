#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,int> pii;
ll T,n,h,ans,m;
stack<pii> st;
int main(){
	while(scanf("%d %d",&n,&m) && n){
		ans=0;int save[1001]={0,};
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				scanf("%d",&h);int idx=j;
				save[j]=(save[j]+1)*h;
				while(!st.empty() and st.top().first>=save[j]){
					ans=max(ans,st.top().first*(j-st.top().second));
					idx=st.top().second;
					st.pop();
				}
				st.push({save[j],idx});
			}
			while(!st.empty()){
				ans=max(ans,(m-st.top().second)*st.top().first);
				st.pop();
			}
		}
		printf("%d\n",ans);
	}
}