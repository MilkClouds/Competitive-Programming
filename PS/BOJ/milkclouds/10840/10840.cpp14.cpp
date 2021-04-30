#include <iostream>
#include <vector>
#define mp make_pair

using namespace std;

string n,m;
int nlen,mlen,ret;
const int MOD=524287;
vector< pair<int,int> > mm[MOD];

int pn[52]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137,139,149,151,157,163,167,173,179,181,191,193,197,199,211,223,227,229,233,239};

int main(){
	cin.tie(0);//ios_base::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=0;i<n.size();i++)
	{
		int x,y;
		x=y=1;
		for(int j=i;j<n.size();j++)
		{
			int temp=n[j]-'a';
			int len=j-i+1;
			x=x*pn[temp]%MOD;
			y=y*pn[temp+26]%MOD;
			mm[x].push_back({y,len});
		}
	}
	for(int i=0;i<m.size();i++)
	{
		int x,y;
		x=y=1;
		for(int j=i;j<m.size();j++)
		{
			int temp=m[j]-'a';
			int len=j-i+1;
			x=x*pn[temp]%MOD;
			y=y*pn[temp+26]%MOD;
			if(len<ret)continue;
			for(int i=0;i<mm[x].size();i++)
				if(mm[x][i]==mp(y,len))
					ret=max(ret,len);
		}
	}
	cout<<ret;
}