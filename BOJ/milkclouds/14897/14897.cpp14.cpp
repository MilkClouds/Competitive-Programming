#include <bits/stdc++.h>
#define rep(a,b,c) for(int a=b;a<c;a++)
using namespace std;
const int MAX=1e6+5;
int N,A[MAX],Q,l,r,sz,cnt,ans[MAX],chk[MAX];
struct ABC{
	int l,r,i;
	bool operator < (ABC& o) const{
		if(l/sz==o.l/sz) return r<o.r;
		return l/sz < o.l/sz;
	}
} qu[MAX];

void mo_add(int x){
	x=A[x];
	if(chk[x]==0)cnt++;
	chk[x]++;
}
void mo_erase(int x){
	x=A[x];
	if(chk[x]==1)cnt--;
	chk[x]--;
}
unordered_map<int,int> chk2;
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>N;sz=sqrt(N);
	rep(i,0,N){cin>>A[i];
		A[i]=chk2[A[i]] ? chk2[A[i]]: chk2[A[i]]=i+1;
	}
	cin>>Q;
	rep(i,0,Q){
		cin>>l>>r;
		qu[i]={l-1,r-1,i};
	}
	sort(qu,qu+Q);
	int lo=0, hi=0;
	rep(i,0,Q){
		int l=qu[i].l, r=qu[i].r, idx=qu[i].i;
		if(i==0){
			rep(k,l,r+1) mo_add(k);
			ans[idx]=cnt; lo=l; hi=r;
			continue;
		}
		while(lo < l) mo_erase(lo++);
		while(l < lo) mo_add(--lo);
		while(r < hi) mo_erase(hi--);
		while(hi < r) mo_add(++hi);
		ans[idx]=cnt; lo=l; hi=r;
	}
	rep(i,0,Q)cout<<ans[i]<<'\n';
}