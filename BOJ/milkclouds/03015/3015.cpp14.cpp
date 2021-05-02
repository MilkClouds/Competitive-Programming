#include <iostream>
#include <stack>
using namespace std;

struct cu{int c,v;cu(int a,int b):c(a),v(b){}};
stack<cu> st;
int n,t;
long long ans;
int main()
{
	cin>>n;
	while(n--){
		cin>>t;
		while(!st.empty()&&st.top().v<t){ans+=st.top().c;st.pop();}
		if(!st.empty()&&st.top().v>t){ans++;}
		int c=0;
		if(!st.empty()&&st.top().v==t)
		{c=st.top().c;ans+=c;st.pop();
		if(!st.empty())ans+=1;}
		st.push(cu(c+1,t));
	}
	cout<<ans;
	return 0;
}