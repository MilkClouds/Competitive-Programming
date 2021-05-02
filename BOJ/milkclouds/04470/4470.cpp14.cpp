#include <iostream>
using namespace std;

int n;
string str;

int main(){
	cin>>n;
	getline(cin,str);
	for(int i=1;i<=n;i++){
		getline(cin,str);
		cout<<i<<". "<<str<<"\n";
	}
}