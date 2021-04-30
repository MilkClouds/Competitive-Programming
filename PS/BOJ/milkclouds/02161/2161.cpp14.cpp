#include <iostream>
#include <cmath>
#include <deque>
using namespace std;

int main(){
	int N;
	deque<int> v;
	cin>>N;
	for(int i=1;i<=N;i++)
		v.push_back(i);
	while(v.size()){
		cout<<v.front()<<" ";
		v.pop_front();
		v.push_back(v.front());
		v.pop_front();
	}
	return 0;
}
