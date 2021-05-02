#include <bits/stdc++.h>
using namespace std;

int N,cnt;
string st;
unordered_map<string,int> mm;
int main(){
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>st;
		if(i-mm[st]<mm[st])cnt++;
		mm[st]++;
	}
	cout<<cnt;
}