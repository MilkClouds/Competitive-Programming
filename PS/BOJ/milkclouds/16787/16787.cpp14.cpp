#include <iostream>
#define x first
#define y second
#define pb push_back
#define all(x) x.begin(), x.end()
#define rep(a,b,c) for(int a=b;a<c;a++)
using namespace std;

string S;
int n,a,b;
inline int f(char x){return x=='O'?0:1;}
int main(){
	cin>>n>>S;
	a=f(S[0]);
	rep(i,1,n){
		if(a^f(S[i])) {
			b++;
			i++;
		}
		a=f(S[i]);
	}
	cout<<b;
}