#include <bits/stdc++.h>
#define rep(i,a,b) for(ll i = (a); i < (b); i++)
#define x first
#define y second
using namespace std;
using ll = long long;
using ld = long double;
using pl = pair<ll, ll>;


// Maximum CHT. 1차항 계수 단조증가 가정했고, get(x_i)의 x_i도 단조증가해야함. O(N)
// insert 함수는 최악 O(N)이 될 수도 있으니 주의. 아래의 O(logN) 풀이가 더 안정적일 듯하니 권장함.
struct CHT{
	vector<ll> a, b, c;
    CHT(): CHT(0){}
    CHT(int N): a(N), b(N), c(N){}
	int pv = 0, top = 0;

	ll f(int idx, ll x){
		return a[idx]*x + b[idx];
	}

	void insert(ll aa, ll bb, ll cc){
		if(top >= 1 && aa == a[top-1]){
			c[top-1] = cc; return;
		}
		while(top >= 2 && (b[top-1] - b[top-2]) * (a[top-2] - aa) >= (bb - b[top-2]) * (a[top-2] - a[top-1])) top--;
		a[top] = aa;
		b[top] = bb;
		c[top] = cc;
		top++;
		if(pv >= top) pv = top - 1;
	}

	pl get(ll x){
		while(pv+1 < top && f(pv + 1, x) > f(pv, x)) pv++;
		return {f(pv, x), c[pv]};
	}
} cht;

// get(x_i)의 x_i는 단조증가 필요없음. O(NlogN)
typedef pair<ll, ll> Line;
struct CHT{
	vector<Line> lines;
	vector<int> idx;
    CHT(): CHT(0){}
    CHT(int N): lines(N), idx(N) {}
	int top = 0;

	ll f(Line line, ll x){
		return line.x * x + line.y;
	}
	ld intersect(Line a, Line b){ // aware div-by-0
		return (ld) (b.y - a.y) / (a.x - b.x);
	}

	int nth(Line line){
		// 기울기가 전과 같아서 평행한 경우는 안 구현함. strictly increasing 가정
		int l = 0, r = top;
		while (l < r)
		{
			int m = l + r >> 1;
			if(intersect(line, lines[m - 1]) < intersect(lines[m - 1], lines[m])) r = m;
			else l = m + 1;
		}
		return l;
	}
	void insert(Line line, int i){
		top = nth(line);
		lines[top] = line;
		idx[top] = i;
		top++;
	}

	pl get(ll x){
		int l = 0, r = top;
		while(l + 1 < r){
			int m = l + r >> 1;
			if(intersect(lines[m], lines[m - 1]) < x) l = m;
			else r = m;
		}
		return {f(lines[l], x), idx[l]};
	}
} cht;


/*
	// get함수 삼분탐색 버전
	pl get(ll x){
		int l = 0, r = top;
		while(l + 2 < r){
			int p = (2 * l + r) / 3, q = (2 * r + l) / 3;
			if(f(p, x) > f(q, x)) r = q;
			else l = p;
		}
		int ansI = r;
		rep(i, l, r){
			if(f(i, x) > f(ansI, x)){
				ansI = i;
			}
		}
		return {f(ansI, x), c[ansI]};
	}
*/