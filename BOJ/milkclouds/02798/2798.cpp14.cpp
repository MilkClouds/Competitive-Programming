#include <bits/stdc++.h>
using namespace std;
int N,M,A[101],k,ans=1e9;
int main(){
	cin>>N>>M;
	for(int i=0;i<N;i++){
		cin>>A[i];
	}sort(A,A+N);
	for(int i=0;i<N;i++){
		k=i+2;
		for(int j=i+1;j<N;j++){
			while(k+1<N && A[i]+A[j]<=M-A[k+1])k++;
			while(j<k && A[i]+A[j]>M-A[k])k--;
			if(j==k)break;
			int t=M-(A[i]+A[j]+A[k]);
			if(t<ans)ans=t;
		}
	}
	cout<<M-ans;
}