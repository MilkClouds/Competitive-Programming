#include <bits/stdc++.h>
using namespace std;
const int MAX=3e5+1;
int N,a[MAX],ret,dealt;
vector<int> odd;
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>N;dealt=1;
	for(int i=1;i<=N;i++){cin>>a[i];if(a[i]&1)odd.push_back(i);}
	for(int i=N;i;i--){
		int remain=a[i]/2;a[i]-=remain*2;
		if(remain==0)continue;
		if(!odd.empty())
		for(int j=0;j<odd.size()&&remain;j++){
			if(odd.back()<=i){
				ret++;
				a[odd.back()]--;remain--;
			}
			odd.pop_back();
		}
		if(remain){
			for(int j=dealt;j<=i;j++){
				if(remain==0)break;
				if(remain>=a[j])
				{
					dealt++;remain-=a[j];ret+=a[j];
				}
				else{
					a[j]-=remain;ret+=remain;remain=0;if(a[j]&1)odd.push_back(j);
				}
			}
		}
	}
	cout<<ret;
}