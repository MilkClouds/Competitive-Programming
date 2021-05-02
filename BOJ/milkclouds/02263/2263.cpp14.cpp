#include <bits/stdc++.h>
using namespace std;

int n,t;
vector<int> in,post;
unordered_map<int,int> rev;
void v(int n){
	if(n)cout<<n<<" ";
}
void solution(int a,int b,int c,int d){
	if(b-a==1){v(in[a]);return;}
	int root=post[d-1],idx=rev[root];
	v(root);
	if(idx-a!=0)
		solution(a,idx,c,c+idx-a);
	if(b-idx!=1)
		solution(idx+1,b,c+idx-a,d-1);
}
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=0;i<n;i++){cin>>t;in.push_back(t);rev[t]=i;}
	for(int i=0;i<n;i++){cin>>t;post.push_back(t);}
	solution(0,n,0,n);
	return 0;
}