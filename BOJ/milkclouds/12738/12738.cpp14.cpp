#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n,t;
vector<int> v;

int main(){
	cin.tie(0);ios_base::sync_with_stdio(0);
	cin>>n;
	while(n--){
		cin>>t;
		auto point=lower_bound(v.begin(),v.end(),t);
		if(point==v.end()){
			v.push_back(t);
		}
		else{
			*point=t;
		}
	}
	cout<<v.size();
}