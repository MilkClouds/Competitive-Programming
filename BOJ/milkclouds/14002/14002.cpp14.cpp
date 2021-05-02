#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

typedef pair<int,int> pii;
int n,t;
vector<int> v;
vector<pii> ans;
stack<int> st;

int main(){
	cin.tie(0);ios_base::sync_with_stdio(0);
	cin>>n;
	while(n--){
		cin>>t;
		auto point=lower_bound(v.begin(),v.end(),t);
		if(point==v.end()){
		    ans.push_back(make_pair(v.size(),t));
			v.push_back(t);
		}
		else{
		    //ans.push_back(make_pair(v.size(),t));
			*point=t;
			ans.push_back(make_pair(point-v.begin(),t));
		}
	}
 	cout<<v.size()<<endl;
    int t=v.size()-1;
    while(not ans.empty()){
        auto a=ans.back();
        ans.pop_back();
        if(a.first==t){
            t--;
            st.push(a.second);
        }
    }
    while(!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }
}