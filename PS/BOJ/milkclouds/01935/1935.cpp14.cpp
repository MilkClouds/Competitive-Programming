#include <bits/stdc++.h>
using namespace std;

int N,a[26];
string EV;
stack<double> st;

double eval(double x,double y,char c){
	if(c=='+')return x+y;
	else if (c=='-')return x-y;
	else if (c=='*')return x*y;
	else if (c=='/')return x/y;
}
int main(){
	cin>>N>>EV;
	for(int i=0;i<N;i++)cin>>a[i];
	for(auto i:EV){
		if(i<'A'){
			double x=st.top();st.pop();double y=st.top();st.pop();
			st.push(eval(y,x,i));
		}
		else{
			i-='A';
			st.push(a[i]);
		}
	}
	printf("%.2lf",st.top());
}