#include<bits/stdc++.h>
#define rep(a,b,c) for(int a=b;a<c;a++)
using namespace std;
const int dx[]={0,0,1,-1}, dy[]={1,-1,0,0};

typedef pair<int,int> pii;
struct ABC{
    int x,y;
    ABC operator + (ABC o){return {x+o.x, y+o.y};}
    ABC(int x,int y):x(x),y(y){}
    ABC():ABC(0,0){}
};

int N,M,a[1005][1005],cnt,reward[1000002],ans;
bool visit[1005][1005],chk[1005][1005];
inline bool can(int x,int y){
    return 0<=x && x<N && 0<=y && y<M;
}
vector<pii> v;
set<pii> set1;
map<pii, vector<int> > map1;
map<int, vector<pii> > map2;
ABC dfs(int x,int y){
    if(visit[x][y] || a[x][y]^2)return {0,0};
    visit[x][y]=1;
    ABC ret={1,0}; // x: reward y: cost
    rep(k,0,4){
        int nx=x+dx[k], ny=y+dy[k];
        if(can(nx,ny)){
            if(a[nx][ny]==2)
                ret=ret+dfs(nx,ny);
            else if (a[nx][ny]==0 && !chk[nx][ny]) {ret=ret+ABC(0,1); chk[nx][ny]=1; v.push_back({nx,ny});}
        }
    }
    return ret;
}
bool func(vector<pii> a, pii b,pii c){
	return (a[0]==b && a[1]==c) || (a[0]==c && a[1]==b);
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>N>>M;
    rep(i,0,N)rep(j,0,M)cin>>a[i][j];
    rep(i,0,N)rep(j,0,M){
        fill(chk[0],chk[25],0); v.clear();
        ABC t=dfs(i,j);
        if(t.y>2)continue;
        map2.insert({cnt,{}});
        for(auto i:v){
            set1.insert(i);
            if(map1.find(i)!=map1.end())
                map1[i].push_back(cnt);
            else map1[i]={cnt};
            map2[cnt].push_back(i);
        }
        reward[cnt++]=t.x;
    }
    for(auto i: set1){
        for(auto j: set1){
            set<int> cand;
	    int ret=0;
            for(auto k: map1[ i ] ) cand.insert(k);
            for(auto k: map1[ j ] ) cand.insert(k);        
            for(auto k: cand) {
		if(map2[k].size()==1) ret+=reward[k];
		else if ( func( map2[k], i, j ) ) ret+=reward[k];
	    }
	    ans=max(ans,ret);
	}
    }
    cout<<ans;
    return 0;
}
