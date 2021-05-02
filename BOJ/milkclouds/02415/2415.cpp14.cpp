#include <cstdio>
#include <math.h>
#include <algorithm>
using namespace std;
#define MN 1505
typedef long long ll;
int n, m;
struct Point {
	int x, y;
	bool operator == (const Point p1) const {
		return (p1.x == x && p1.y == y);
	}
} p[MN], A, B, C;
struct Edge {
	Point a, b;
	ll length;
} e[MN*MN/2];
inline bool cmp(Edge e1, Edge e2) {
	if (e1.length == e2.length) return (e1.a.x+e1.b.x) < (e2.a.x+e2.b.x);
	return e1.length < e2.length;
}
inline double dist(Point p1, Point p2) {
	return (double)(sqrt((double)(p1.x-p2.x)*(p1.x-p2.x)+(double)(p1.y-p2.y)*(p1.y-p2.y)+1e-5));
}
int main() {
	scanf("%d",&n);
	for (int i = 1; i <= n; i++) {
		scanf("%d%d",&p[i].x,&p[i].y);
		for (int j = 1; j < i; j++) {
			e[++m].a = p[j]; e[m].b = p[i];
			e[m].length = (ll)(e[m].a.x-e[m].b.x)*(e[m].a.x-e[m].b.x)+(ll)(e[m].a.y-e[m].b.y)*(e[m].a.y-e[m].b.y);
		}
	}
	sort(e+1, e+m+1, cmp);
	int dx, dy, fx, fy;
	double res = 0;
	double area;
	for (int i = 1; i <= m; i++) {
		for (int j = i+1; j <= m; j++) {
			if (e[i].a == e[j].a || e[i].a == e[j].b || e[i].b == e[j].a || e[i].b == e[j].b) continue;
			if (e[i].length != e[j].length || e[i].a.x+e[i].b.x != e[j].a.x+e[j].b.x) break;
			if (e[i].a.y+e[i].b.y == e[j].a.y+e[j].b.y) {
				area =  dist(e[j].a, e[i].a)*dist(e[j].b, e[i].a)+(1e-5);
				if (res < area) res = area;
			}
		}
	}
	printf("%.0lf",res);
}

