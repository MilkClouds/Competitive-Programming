#include <iostream>
#include <algorithm>
using namespace std;

int n,l;
int h[10000];

int main(){
	cin.tie(0);
	cin>>n>>l;
	for(int i=0;i<n;i++)
		cin>>h[i];
	sort(h,h+n);
	for(int i=0;i<n;i++){
		if(h[i]<=l)
			l+=1;
		else{
			cout<<l;
			return 0;
		}
	}
	cout<<l;
	return 0;
}