#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>
using namespace std;

int n,m,temp;
vector<int> a;
vector<int> pSum={0};

int main(){
	cin>>n>>m;
	for (int i = 0; i < n; ++i)
	{
		cin>>temp;
		a.push_back(temp);
		pSum.push_back(pSum[i]+temp);
	}
	int ret=0,temp=10000000;
	for (int i = m-1; i < n; ++i)
	{
		temp=min(temp,pSum[i-m+1]);
		ret=max(ret,pSum[i+1]-temp);
	}
	cout<<ret;
	

}