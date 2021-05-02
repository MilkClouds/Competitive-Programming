#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Point{
	ll x,y,p,q;
	Point():Point(0,0,0,0){}
	Point(ll x,ll y,ll p,ll q):x(x),y(y),p(p),q(q){}
	bool operator < (Point o) const{
		if(p*o.q != q*o.p)return p*o.q>q*o.p;
		if(y!=o.y)return y<o.y;
		return x<o.x;
	}
	Point operator - (Point o){
		return Point(x-o.x,y-o.y,0,0);
	}
} p[200005];

ll ccw(Point A,Point B){
	return A.x*B.y-A.y*B.x;
}
ll ccw(Point A,Point B,Point C){
	return ccw(B-A,C-A);
}
bool check(int A,int B,int  C,int D){
	return ccw(p[A]-p[B],p[C]-p[D])>=0;
}
ll dist(int A,int B){
	ll dx=p[A].x-p[B].x,dy=p[A].y-p[B].y;
	return dx*dx+dy*dy;
}

int T,N;

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>T;
	while(T--){
		cin>>N;
		for(int i=0;i<N;i++){cin>>p[i].x>>p[i].y;p[i].p=p[i].q=0;}
		swap(p[0],*min_element(p,p+N));
		for(int i=1;i<N;i++){
			p[i].p=p[i].x-p[0].x;
			p[i].q=p[i].y-p[0].y;
		}
		sort(p+1,p+N);
		vector<int> hull={0,1};
		for(int i=2;i<N;i++){
			while(hull.size()>1){
				int first=hull.back();hull.pop_back();
				int second=hull.back();
				if(ccw(p[second],p[first],p[i])>0){
					hull.push_back(first);
					break;
				}
			}
			hull.push_back(i);
		}
		ll ret=0;
		Point A,B;
		for(int i=0,c=0;i<hull.size();i++){
			do{
				ll temp=dist(hull[i],hull[c]);
				if(ret<temp){
					A=p[hull[i]];B=p[hull[c]];
					ret=temp;
				}
			}while(c+1<hull.size() and check(hull[i],hull[i+1],hull[c],hull[c+1])and ++c);
		}
		cout<<A.x<<" "<<A.y<<" "<<B.x<<" "<<B.y<<"\n";
	}
}