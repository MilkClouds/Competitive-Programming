#include <iostream>
#include <queue>
#include <vector>
#include <map>
#define p make_pair
using namespace std;

map<int,bool> memo[100000];
queue< pair<int,int> > q;

int check(int a,int b){
	if(memo[a][b])
		return 0;
	q.push(p(a,b));
	memo[a][b]=true;
	return 1;
}

int main(){
	int a,b,c,d,idx=0,t;

	cin>>a>>b>>c>>d;
// 	a=3;b=7;c=3;d=2;
	q.push(p(0,0));
	memo[0][0]=true;
	while(q.size()>0){
		t=q.size();
		for(int i=0;i<t;i++){
			pair<int,int> pp;
			pp=q.front();
// 			cout<<idx<<" "<<pp.first<<" "<<pp.second<<endl;
			if(pp.first==c and pp.second==d){
				cout<<idx;
				return 0;
			}
			q.pop();
			if(pp.first!=a) check(a,pp.second);
			if(pp.second!=b) check(pp.first,b);
			if(pp.first!=0) check(0,pp.second);
			if(pp.second!=0) check(pp.first,0);
			if(pp.second+pp.first>b){
			    check(pp.first-b+pp.second,b);
			} else {
			    check(0,pp.first+pp.second);
			}
			if(pp.second+pp.first>a){
			    check(a,pp.second-a+pp.first);
			} else {
			    check(pp.first+pp.second,0);
			}
		}
		idx++;
	}
	cout<<-1;
	return 0;
}