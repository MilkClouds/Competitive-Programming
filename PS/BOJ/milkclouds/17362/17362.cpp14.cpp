#include <bits/stdc++.h>
#define rep(a,b,c) for(int a=b;a<c;a++)
using namespace std;
int n,a[]={2,1,2,3,4,5,4,3,2,1};
int main(){
	cin>>n;
	cout<<a[n%8];
}