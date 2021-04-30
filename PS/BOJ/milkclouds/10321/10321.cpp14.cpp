#include <bits/stdc++.h>
using namespace std;
int T,N,x,y;
typedef long long ll;
struct Point{
	int x,y,p,q;
	Point():Point(0,0){}
	Point(int x,int y):x(x),y(y){}
	bool operator < (Point& o) const{
		if(p*o.q!=q*o.p)return p*o.q>q*o.p;
		if(y!=o.y)return y<o.y;
		return x<o.x;
	}
	Point operator - (Point& o) const{
		return Point(x-o.x,y-o.y);
	}
} p[10000];
int ccw(Point A,Point B){
	return A.x*B.y-B.x*A.y; //ccw면 >0
}
int ccw(Point A,Point B,Point C){
	return ccw(B-A,C-A);
}
bool chk(int A,int B,int C,int D){
	return ccw(p[A]-p[B],p[C]-p[D])>=0;
}
inline ll triangle(int a,int b,int c){
	return abs(p[a].x*p[b].y+p[b].x*p[c].y+p[c].x*p[a].y-(p[a].y*p[b].x+p[b].y*p[c].x+p[c].y*p[a].x));
}
inline ll square(int a,int b,int c,int d){
	return triangle(a,b,c)+triangle(a,c,d);
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>T;
	while(T--){
		cin>>N;
		for(int i=0;i<N;i++)cin>>p[i].x>>p[i].y;
		swap(p[0],*min_element(p,p+N));
		for(int i=1;i<N;i++){
			p[i].p=p[i].x-p[0].x;
			p[i].q=p[i].y-p[0].y;
		}
		sort(p+1,p+N);
		vector<int> hull({0,1});
		for(int i=2;i<N;i++){
			while(hull.size()>1){
				int first=*(hull.end()-1);hull.pop_back();
				int second=*(hull.end()-1);
				if(ccw(p[second],p[first],p[i])>0){
					hull.push_back(first);break;
				}
			}
			hull.push_back(i);
		}
		ll ret=0,p,q;
		for(int i=0;i<hull.size();i++){
			p=i+1;q=i+1;
			for(int j=i+1;j<hull.size();j++){
				ll tt=0,temp=0,temp2;
				for(tt=triangle(hull[i],hull[p],hull[j]);p<j;p++,tt=temp2){
					temp2=triangle(hull[i],hull[p+1],hull[j]);
					if(tt>=temp2)break;
				}
				for(temp=triangle(hull[j],hull[q],hull[i]);q+1<hull.size();q++,temp=temp2){
					temp2=triangle(hull[j],hull[q+1],hull[i]);
					if(temp>=temp2)break;
				}
				ret=max(ret,tt+temp);
			}
		}
		cout<<ret/2<<(ret&1?".5":"")<<"\n";
	}
}