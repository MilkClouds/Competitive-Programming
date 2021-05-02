#include <iostream>
#include <queue>
using namespace std;

int N,S,E,room,ret,n;
priority_queue<int> s,e;

int main()
{
	ios_base::sync_with_stdio(0);
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>n>>S>>E;
		s.push(-S);
		e.push(-E);
	}
	while(!s.empty()){
		int a=s.top(),b=e.top();
		if(a>b){
			s.pop();
			room++;
			ret=max(ret,room);
		}
		else{
			e.pop();
			room--;
		}
	}
	cout<<ret;
	return 0;
}