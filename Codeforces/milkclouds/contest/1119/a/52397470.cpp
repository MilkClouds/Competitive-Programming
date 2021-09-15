#include <bits/stdc++.h>
using namespace std;
int N,a[300001],ret;
bool chk[300001];
typedef pair<int,int> pii;
deque<pii> deq;
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>N;
	for(int i=0;i<N;i++){cin>>a[i];
		if(deq.size()>1 && deq.front().second==a[i]){
			ret=max(ret,i-deq[1].first);
		}
		if(!deq.empty()&&deq.front().second^a[i])ret=max(ret,i-deq[0].first);
		if(!chk[a[i]])deq.push_back({i,a[i]}),chk[a[i]]=1;
	}
	cout<<ret;
}