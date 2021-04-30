#include <iostream>
using namespace std;

int main()
{
	int a,d,k;
	cin>>a>>d>>k;
	//a+(n-1)*d
	if((k-a)%d==0 and (k-a)/d>=0){
		cout<<(k-a)/d+1;
		}
	else cout<<"X";

	return 0;
}