#include <iostream>
using namespace std;

int main(){
	int Q,a;
	ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>Q;
    for (int i = 0; i < Q; ++i)
    {
    	cin>>a;
    	cout<<((a&-a)==a)<<"\n";
    }
}