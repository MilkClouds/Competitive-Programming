#include <bits/stdc++.h>
using namespace std;
int N,L,A[5000000];
deque<pair<int,int> > deq;
int main(){
	ios_base::sync_with_stdio(0);
	cin>>N>>L;
	for(int i=0;i<N;i++)cin>>A[i];
	for(int i=0;i<N;i++){
		if(!deq.empty()){
			if(deq.front().first <= i-L ) deq.pop_front();
			while(!deq.empty() and deq.back().second > A[i]) deq.pop_back();
		}
		deq.push_back({i,A[i]});
		cout<<deq.front().second<<" ";
	}
}