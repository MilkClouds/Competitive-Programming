#include <iostream>
#include <vector>
using namespace std;
int T,k;
const int M=1299710;
bool arr[M];
vector<int> pn={2};
int search(int start,int end,int value){
	while(start+1<end){
		int mid=(start+end)/2;
		if(pn[mid]>value)end=mid;
		else if(pn[mid]<value)start=mid;
		else return 0;
	}
	return pn[start+1]-pn[start];
}
int main(){
    fill(arr,arr+M,0);
	for (int i = 3; i < M; i=i+2)
	{
		if(arr[i]) continue;
		pn.push_back(i);
		for (long j = (long)i*i; j < M; j=j+2*i)
			arr[j]=true;
	}
	cin>>T;
	while(T--){
		cin>>k;
		if(k==1 or k==2)cout<<0<<'\n';
		else cout<<search(0,pn.size(),k)<<'\n';
	}
}