#include <bits/stdc++.h>
#define rep(a,b,c) for(int a=b;a<c;a++)
using namespace std;
using ll=long long;
using pii=pair<ll,ll>;
const ll MAX=3e5/2, ST_MAX=6e5, INF=2e9;

struct Line{
	int x1,y1,x2,y2;
	Line():Line(0,0,0,0){}
	Line(int a,int b,int c,int d):x1(a),y1(b),x2(c),y2(d){}
	bool operator < (const Line &o) const { return x1<o.x1; }
	// for wline
} wline[MAX];

struct SegTree{
	int minDepth[ST_MAX], root[ST_MAX], size, start;
	void init(int n){
		size=n; start=1; while(start<size) start<<=1;
		fill(minDepth, minDepth+MAX*2, INF);
		fill(root, root+MAX*2, -1);
	}
	void renewDepth(int pos, int v){
		pos+=start;
		minDepth[pos]=v;
		root[pos]=pos-start;
		while(pos>1){
			pos>>=1;
			int k=minDepth[pos*2]<=minDepth[pos*2+1] ? pos*2 : pos*2+1;
			minDepth[pos]=minDepth[k];
			root[pos]=root[k];
		}
	}
	pii getMinDepth(int l,int r){return getMinDepth(l,r,1,0,start);}
	pii getMinDepth(int l,int r,int node,int nl,int nr){
		if(r<=nl || nr<=l) return pii(INF,-1);
		if(l<=nl && nr<=r) return pii(minDepth[node],root[node]);
		int mid=nl+nr>>1;
		pii pl=getMinDepth(l,r,node*2, nl, mid);
		pii pr=getMinDepth(l,r,node*2+1, mid, nr);
		return pl.first <= pr.first ? pl : pr;
	}
} ST;
int N, K, X, lc[MAX], rc[MAX], par[MAX], w[MAX], h[MAX];
ll water[MAX];
bool leaked[MAX];

void makeTree(int l,int r,int node,int lx,int rx){
	w[node]=rx-lx;

	pii pl=ST.getMinDepth(l, node);
	if(~pl.second){
		int pivot=pl.second;
		lc[node]=pivot ; par[pivot]=node;
		makeTree(l,node,pivot,lx,wline[node].x1);
		h[lc[node]]=wline[lc[node]].y1-wline[node].y1;
	}
	pl=ST.getMinDepth(node+1, r);
	if(~pl.second){
		int pivot=pl.second;
		rc[node]=pivot ; par[pivot]=node;
		makeTree(node+1,r,pivot,wline[node].x2,rx);
		h[rc[node]]=wline[rc[node]].y1-wline[node].y1;
	}
}
void setWaterValue(int node){
	water[node]+=1LL*w[node]*h[node];
	if(~lc[node]){
		water[lc[node]]+=water[node];
		setWaterValue(lc[node]);
	}
	if(~rc[node]){
		water[rc[node]]+=water[node];
		setWaterValue(rc[node]);
	}
}
void decreaseWaterValue(int node,ll value){
	if(leaked[node])return;
	water[node]-=value;
	if(~lc[node]) decreaseWaterValue(lc[node],value);
	if(~rc[node]) decreaseWaterValue(rc[node],value);
}
void makeHole(int node,int child){
	if(leaked[node]) return;
	leaked[node]=1;
	if(~child){
		if(~lc[node] && lc[node]^child) decreaseWaterValue(lc[node],water[node]);
		else if (~rc[node] && rc[node]^child) decreaseWaterValue(rc[node],water[node]);
	}
	water[node]=0;
	int p=par[node];
	if(~p && !leaked[p]) makeHole(p, node);
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>N;
	int x1,y1,x2,y2,W=N/2-1; ST.init(W);
	rep(i,0,N){
		cin>>x2>>y2;
		if(i>0 && i%2==0){
			int ln=(i-1)/2;
			wline[ln]=Line(x1,y1,x2,y2);
			ST.renewDepth(ln, y1);
		}
		x1=x2; y1=y2;
	}
	X=wline[W-1].x2;
	pii pRoot=ST.getMinDepth(0,W); int rootLine=pRoot.second;
	w[rootLine]=X;
	h[rootLine]=pRoot.first;
	fill(par,par+W,-1); fill(lc,lc+W,-1); fill(rc, rc+W, -1);
	makeTree(0,W,rootLine,0,X);
	setWaterValue(rootLine);
	priority_queue<pii> pq;
	rep(i,0,W)
		if(lc[i]==-1 && rc[i]==-1) pq.push({water[i],i});
	cin>>K;
	ll result=0;
	rep(i,0,K){
		pii target(-1,-1);
		while(!pq.empty()){
			pii temp=pq.top(); pq.pop();
			if(water[temp.second] != temp.first) pq.push({water[temp.second], temp.second});
			else if (!leaked[temp.second]){target=temp;break;}
		}
		if(target.second==-1)break;
		result+=target.first;
		makeHole(target.second,-1);
	}
	cout<<result;
}