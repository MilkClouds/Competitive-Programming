#include<bits/stdc++.h>
#define rep(a,b,c) for(int a=b;a<c;a++)
#define x first
#define y second
using namespace std;
const int dx[]={0,0,1,-1}, dy[]={1,-1,0,0};

typedef pair<int,int> pii;
struct ABC{
    int x,y;
    ABC operator + (ABC o){return {x+o.x, y+o.y};}
    ABC(int x,int y):x(x),y(y){}
    ABC():ABC(0,0){}
};

int N,M,a[1005][1005],ans,one[1005][1005],two[1005][1005];
bool visit[1005][1005],chk[1005][1005];
inline bool can(int x,int y){
    return 0<=x && x<N && 0<=y && y<M;
}
vector<pii> v;
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
map<pair<pii,pii>, int> mmm;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>N>>M;
    rep(i,0,N)rep(j,0,M)cin>>a[i][j];
    rep(i,0,N)rep(j,0,M){
        v.clear();
	if(visit[i][j] || a[i][j]^2)continue;
        ABC t=dfs(i,j);
	for(auto i:v) chk[i.x][i.y]=0;
        if(t.y>2)continue;
	if(t.y==1){
	    int i=v[0].x, j=v[0].y;
	    one[i][j]+=t.x;
	    continue;
	}
	sort(v.begin(), v.end());
	if( mmm.find({v[0],v[1]}) != mmm.end() ){
		for(auto [i,j]:v)
		two[i][j]+=t.x;
	}
	else {
	    for(auto [i,j]: v)two[i][j]=max(two[i][j], t.x);
	    mmm.insert({ {v[0],v[1]}, 1 });
	}
    }
    vector<int> li;
    rep(i,0,N)rep(j,0,M){
	li.push_back(-one[i][j]);
    }
    sort(li.begin(), li.end());
    rep(i,0,2){
	if( li.size()<=i ) break;
	ans-=li[i];
    }
    // 2 for one component
    rep(i,0,N)rep(j,0,M){
	ans=max(ans, two[i][j]+one[i][j]);
    }
    cout<<ans;
    return 0;
}
