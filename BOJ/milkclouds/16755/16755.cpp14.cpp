#include <iostream>
using namespace std;

string S,t="HONI";
int a,b;
int main(){
	cin>>S;
	for(auto i:S){
		if(t[b]==i)b++;
		if(b==4){b=0;a++;}
	}
	cout<<a;
}