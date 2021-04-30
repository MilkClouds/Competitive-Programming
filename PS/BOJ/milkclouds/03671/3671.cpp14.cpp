#include <iostream>
#include <cmath>
#include <vector>
#include <cstring>
using namespace std;

const int m=1e7;
bool arr[m]={1,1};
bool c[10];
string str;
int ans=0;
bool check[m];

void dfs(string temp){
	int n=stoi(temp);
	if(not arr[n])
		if(not check[n]){
			check[n]=true;
			ans++;
// 			cout<<n<<" check"<<endl;
		}
	for(int i=0;i<str.size();i++){
		if(not c[i]){
			c[i]=1;
			dfs(temp+str[i]);
			c[i]=0;
		}
	}
}

int main(){
    int range=sqrt(m);
	for(int i=2;i<range;i++)if(not arr[i])for(long j=(long)i*i;j<m;j+=i)arr[j]=true;
	int t;
	cin>>t;
	while(t--){
		cin>>str;
		string temp="";
		ans=0;
		for(int i=0;i<str.size();i++){
			c[i]=1;
			dfs(temp+str[i]);
			c[i]=0;
		}
		cout<<ans<<"\n";
		memset(check, 0, sizeof(check));
	}
	return 0;
}
