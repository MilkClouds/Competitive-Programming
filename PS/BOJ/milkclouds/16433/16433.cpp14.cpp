#include <iostream>
using namespace std;

int n,r,c;

int main(){
	cin.tie(0);
	cin>>n>>r>>c;
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++){
			if((i+r)&1){
				if((j+c)&1)
					cout<<'v';
				else
					cout<<'.';
			}
			else{
				if((j+c)&1)
					cout<<'.';
				else
					cout<<'v';
			}
		}
		puts("");
	}
	return 0;
}