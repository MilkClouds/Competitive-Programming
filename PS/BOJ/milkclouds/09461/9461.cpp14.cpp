#include <iostream>
#include <algorithm>
#include <vector>

long arr[101]={0,1, 1, 1, 2, 2, 3, 4, 5, 7, 9};

using namespace std;

int main() {
	int n,t;
	for(int i=11;i<101;i++){
		arr[i]=arr[i-1]+arr[i-5];
		}
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>t;
		cout<<arr[t]<<endl;
		}
}