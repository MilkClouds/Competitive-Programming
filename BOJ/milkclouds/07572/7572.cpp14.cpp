#include <iostream>
using namespace std;

int n;
int main(){
	cin>>n;
	char a=65+(12+n-4)%12;
	cout<<a+to_string((10+n-4)%10);
}