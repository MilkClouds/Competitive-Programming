# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
# include <bits/stdc++.h>
# define rep(a,b,c) for(int a=b;a<c;a++)
# define x first
# define y second
# define all(x) x.begin(),x.end()
# define pb push_back

using namespace std;
using ll=long long;
using pii=pair<ll,ll>;

int N,a,b,A[105];
string S;

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>N;
	rep(i,0,N){
		cin>>S;
		if(S=="KBS1")a=i;
		else if (S=="KBS2")b=i;
	}
	A[a]=1;A[b]=2;
	rep(i,0,a){
		cout<<1;
	}
	rep(i,0,a){
		cout<<4;
		swap(A[a-i],A[a-i-1]);
	}
	int j=0;
	for(;j<N;j++){
		if(A[j]==2)break;
		cout<<1;
	}
	rep(i,0,j-1)cout<<4;
}
	