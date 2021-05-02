#include <iostream>
#include <set>
using namespace std;

multiset<int> mm;
int T,k,n;
char cmd;
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>T;
	while(T--){
		mm.clear();
		cin>>k;
		while(k--){
			cin>>cmd>>n;
			if(cmd=='I')mm.insert(n);
			else{
				if(!mm.empty())
				mm.erase(~n?--mm.end():mm.begin());
			}
		}
		if(mm.empty())cout<<"EMPTY\n";
		else cout<<*--mm.end()<<' '<<*mm.begin()<<'\n';
	}
	return 0;
}