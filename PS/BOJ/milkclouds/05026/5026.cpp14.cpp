#include <iostream>
using namespace std;

int main(){
	int n;
	cin>>n;
	while(n--){
		string r;
		cin>>r;
		if(r=="P=NP"){
			cout<<"skipped"<<endl;
			continue;
		}
		int a,b;
		string c="",d="";
		bool boo=0;
		for(int i=0;i<r.size();i++){
			if(!boo){
				if(r[i]=='+')
					boo=1;
				else
					c+=r[i];
			}
			else
			    d+=r[i];
		}
		cout<<stoi(c)+stoi(d)<<endl;
	}
}