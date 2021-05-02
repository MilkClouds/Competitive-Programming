#include <iostream>
using namespace std;

int t,n,m;
int main(){
	cin>>t;
	while(t--){
		int ans=0;
		cin>>n>>m;
		for(int i=n;i<=m;i++){
			string r=to_string(i);
			for(int s=0;r[s];s++)
				if(r[s]=='0')ans++;
		}
		cout<<ans<<endl;
	}
}