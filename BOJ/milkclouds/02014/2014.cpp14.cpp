#include <iostream>
#include <queue>
using namespace std;

int k,n,idx,t;
priority_queue<int,vector<int>,greater<int> > pq;
int pr[100];
int main()
{
	cin>>k>>n;
	for(int i=0;i<k;i++)cin>>pr[i];
	pq.push(1);
	while(idx++<n){
		t=pq.top();
		pq.pop();
		//cout<<t<<endl;
		for(int i=0;i<k;i++){
			if((long long)t*pr[i]>=((long)1<<31))continue;
			pq.push(t*pr[i]);
			if(t%pr[i]==0)break;
		}
	}
	cout<<pq.top();
	return 0;
}