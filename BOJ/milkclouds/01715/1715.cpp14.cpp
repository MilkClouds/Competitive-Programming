#include <iostream>
#include <set>
using namespace std;

multiset<int> mm;
int N,t,ret,m;

int main(){
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>t;
		mm.insert(t);
	}
	while(mm.size()>1){
	    int a=*mm.begin(),b=*++mm.begin();
	    ret+=a+b;
	    mm.erase(mm.begin());
	    mm.erase(mm.begin());
	    mm.insert(a+b);
	}
	cout<<ret;
}