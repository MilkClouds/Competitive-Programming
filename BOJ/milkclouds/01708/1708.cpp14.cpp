#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
struct Point{
    ll x,y,p,q;
    Point():Point(0,0,0,0){}
    Point(ll x,ll y):Point(x,y,0,0){}
    Point(ll x,ll y,ll p,ll q):x(x),y(y),p(p),q(q){}
    bool operator <(Point& o) const{
        if(q*o.p != p*o.q) return q*o.p<p*o.q;
	if(y != o.y)return y<o.y;
	return x<o.x;
    }
};

inline ll ccw(Point& A,Point& B,Point& C){
    return (B.y-C.y)*(A.x-B.x)-(A.y-B.y)*(B.x-C.x);
}
ll N,x,y;

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>N;
	Point p[100000];
	for(int i=0;i<N;i++){cin>>p[i].x>>p[i].y;}
	sort(p,p+N);
	for(int i=1;i<N;i++){
		p[i].p=p[i].x-p[0].x;
		p[i].q=p[i].y-p[0].y;
	}
	sort(p+1,p+N);
	stack<int> S({0,1});
	for(int i=2;i<N;i++){
		while(S.size()>1){
			ll first=S.top();S.pop();
			ll second=S.top();
			if(ccw(p[second],p[first],p[i])>0){S.push(first);break;}
		}
		S.push(i);
	}
	cout<<S.size();
}