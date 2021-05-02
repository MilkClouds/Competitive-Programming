#include <iostream>
#include <algorithm>
#include <vector>
#define endl '\n'
using namespace std;

struct test
{
    int idx;
	int naE;
	string name;
};

bool d(test a,test b){
    if (a.naE==b.naE){
        return a.idx<b.idx;
    }
	return a.naE<b.naE;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
	int N,naE;
	string name;
	cin>>N;
	test tt[N];
	for (int i = 0; i < N; ++i)
	{
		cin>>naE>>name;
		tt[i].idx=i;
		tt[i].naE=naE;
		tt[i].name=name;
	}
	sort(tt, tt+N, d);
	for (int i = 0; i < N; ++i)
	{
		cout<<tt[i].naE<<" "<<tt[i].name<<endl;
	}
	return 0;
}