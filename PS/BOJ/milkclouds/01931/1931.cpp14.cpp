#include <iostream>
#include <queue>
using namespace std;

//끝나는 시간 빠르게, 같으면 시작시간 빠르게

int N,a,b,last,ans;
typedef pair<int,int> pii;
priority_queue<pii> pq;

int main(){
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>a>>b;
		pq.push({-b,-a});
	}
	while(!pq.empty()){
		b=-pq.top().first;a=-pq.top().second;pq.pop();
		if(a<last)continue;
		last=b;
		ans++;
	}
	cout<<ans;
}