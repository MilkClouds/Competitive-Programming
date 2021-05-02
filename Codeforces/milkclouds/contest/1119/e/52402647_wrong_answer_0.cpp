#include <bits/stdc++.h>
using namespace std;
const int MAX=3e5+1;
int N,a[MAX],ret,dealt;
vector<int> odd;
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>N;
	for(int i=1;i<=N;i++){cin>>a[i];if(a[i]&1)odd.push_back(i);}
	for(int i=N;i;i--){
		int remain=a[i]/2;
		for(int j=0;j<odd.size()&&j<remain;j++){
			if(odd.back()>=i){
				ret++;
				a[odd.back()]--;remain--;
			}
			odd.pop_back();
		}
		if(remain){
			for(int j=dealt;j<i;j++){
				if(remain>=a[j]/2)
				{
					dealt++;remain-=a[j]/2;ret+=a[j]/2;
				}
				else{
					remain=0;
					a[j]-=remain*2;ret+=remain;
				}
			}
		}
	}
	cout<<ret;
}