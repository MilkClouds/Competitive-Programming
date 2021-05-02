#include <bits/stdc++.h>
using namespace std;
const int MAX=1e6+2,INF=1e9+5;
int N,x,y,px,py,sx,sy,idx,ans,ans2,fx,fy,start;
pair<int,int> v[MAX];
struct par{
	int x,sx,idx;
	bool operator < (par o) const{
		return x<o.x;
	}
};
set<par> parset;
bool chk[MAX],chk2[MAX];
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>N;sx=INF;
	for(int i=0;i<N;i++)cin>>v[i].first>>v[i].second;
	for(int i=0;i<=N;i++){
		if(v[i].second<0){start=i;break;}
	}
	for(int cnt=0,i=start;cnt<=N;cnt++,i=(i+1)%N)
	{
		if(cnt==N)i=start;
		x=v[i].first;y=v[i].second;
		if(py<0&&y>0)
			sx=x;
		if(sx!=INF&&py>0&&y<0){
			if(x>sx)swap(x,sx);
			parset.insert({x,sx,0});
			sx=INF;
		}
		py=y;
	}
	//표준 출력으로, 입력으로 주어진 직교다각형에 의해서 나타나는 봉우리 패턴에서 "다른 봉우리에 의해 포함되지 않는 봉우리 개수"와 "다른 봉우리를 포함하지 않는 봉우리 개수"를 공백을 사이에 두고 출력한다.
	stack<par> S;
	for(auto i=parset.begin();i!=parset.end();i++){
		par cur=*i;x=cur.x;sx=cur.sx;cur.idx=idx;
		while(!S.empty()&&S.top().sx<=x){
			S.pop();
		}
		if(S.empty())ans++;
		auto n=i;n++;
		if(n==parset.end()||n->x>sx)ans2++;
		S.push(cur);
		idx++;
	}
	//for(int i=0;i<parset.size();i++){if(chk[i]==0)ans++;if(chk2[i]==0)ans2++;}
	cout<<ans<<" "<<ans2;
}
