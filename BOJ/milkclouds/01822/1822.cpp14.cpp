#include <iostream>
#include <set>
using namespace std;

int main()
{
	cin.tie(0);
	int n,m,x,y;
	set<int> a;
	cin>>n>>m;
	while(n--){
		cin>>x;
		a.insert(x);
	}
	while(m--){
		cin>>y;
		a.erase(y);
	}
	cout<<a.size()<<endl;
	for(int x:a)
	cout<<x<<' ';
	return 0;
}