#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
struct Point{
    ll x,y,p,q;
    Point():Point(0,0,0,0){}
    Point(ll x,ll y,ll p,ll q):x(x),y(y),p(p),q(q){}
    Point(ll x,ll y):Point(x,y,0,0){}
    bool operator <(Point& o) const{
        if(q*o.p != p*o.q) return q*o.p<p*o.q;
    if(y != o.y)return y<o.y;
    return x<o.x;
    }
    Point operator -(Point& o){
        return Point(x-o.x,y-o.y);
    }
    void get(){
    	cin>>x>>y>>p>>q;
    }
};
ll ccw(Point A,Point B){
    return A.x*B.y-A.y*B.x;
}
ll ccw(Point A,Point B,Point C){
    return ccw(B-A,C-A);
}
ll N,x,y,T,l,r,m;
Point p[30000],init[30000];

bool chk(int A,int B,int C,int D){
    return ccw(p[A]-p[B],p[C]-p[D])>=0;
}
inline ll dist(int u,int v){
    ll dx=p[u].x-p[v].x;
    ll dy=p[u].y-p[v].y;
    return dx*dx+dy*dy;
}

ll solution(ll time){
	for(int i=0;i<N;i++){
		p[i].x=init[i].x+init[i].p*time;
		p[i].y=init[i].y+init[i].q*time;
	}
	swap(p[0],*min_element(p,p+N));
    for(int i=1;i<N;i++){
        p[i].p=p[i].x-p[0].x;
        p[i].q=p[i].y-p[0].y;
    }
    sort(p+1,p+N);
    vector<int> hull({0,1});
    for(int i=2;i<N;i++){
        while(hull.size()>1){
            ll first=hull[hull.size()-1];hull.pop_back();
            ll second=hull[hull.size()-1];
            if(ccw(p[second],p[first],p[i])>0){hull.push_back(first);break;}
        }
        hull.push_back(i);
    }
    ll ret=0,p=0;
    for(int i=0;i<hull.size();i++){
        while(p+1<hull.size() and chk(hull[i],hull[i+1],hull[p],hull[p+1]))
            ret=max(ret,dist(hull[i],hull[p++]));
        ret=max(ret,dist(hull[i],hull[p]));
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>N>>T;
    for(int i=0;i<N;i++){init[i].get();}
    l=0,r=T;
	while(l+2<r){
		ll first=(r+l*2)/3,second=(l+r*2)/3;
		if(solution(first)>solution(second))l=first+1;
		else r=second;
	}
	ll ans=1e18,idx=l;
	for(ll i=l;i<=r;i++){
		ll temp=solution(i);
		if(temp<ans){
			ans=temp;
			idx=i;
		}
	}
	cout<<idx<<"\n"<<ans;
}