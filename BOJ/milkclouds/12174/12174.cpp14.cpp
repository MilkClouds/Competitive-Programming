#include <bits/stdc++.h>

using namespace std;

int T,B;

int main(){
	cin.tie(0);ios_base::sync_with_stdio(0);
	cin>>T;
	for(int i=1;i<=T;i++){
		cin>>B;
		cout<<"Case #"<<i<<": ";
		while(B--)
		{
			char target=0;
			char c;
			for(int i=0;i<8;i++)
			{
				cin>>c;
				target=target*2+(c=='I'?1:0);
			}
			cout<<target;
		}
		cout<<'\n';
	}
}