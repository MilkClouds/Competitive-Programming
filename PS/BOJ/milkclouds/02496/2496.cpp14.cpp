#include<stdio.h>
#include<algorithm>
using namespace std;
typedef struct {
	int x;
	int y;
	int inc;
	int dec;
}point;
int abs(int a){ if(a > 0) return a; return -a; }
bool compare(const point &a, const point &b){ if(a.inc == b.inc) return a.y < b.y; return a.inc > b.inc; }
int maxt, maxX, maxY, T, K;
point Jew[101];
void countDia(int x, int y){
	int i, MDx = x, MDy = y - K / 2, cnt = 0;
	if(MDx < 0 || MDy < 0) return;
	for(i = 0; i < T; i++){
		if(abs(MDx - Jew[i].x) + abs(MDy - Jew[i].y) <= K / 2)
			cnt++; 
	}
	if(cnt > maxt){
		maxt = cnt; maxX = MDx; maxY = MDy;
	}
}
int main(){
	int N, M, i, j;
	
	scanf("%d %d %d %d", &N, &M, &T, &K);
	for(i = 0; i < T; i++){
		scanf("%d %d", &Jew[i].x, &Jew[i].y);
		Jew[i].inc = Jew[i].y - Jew[i].x; Jew[i].dec = Jew[i].x + Jew[i].y;
	}
	sort(Jew, Jew + T, compare);
	maxX = Jew[0].x; maxY = Jew[0].y; maxt = 1;
	for(i = 0; i < T; i++){
		for(j = 0; j < i; j++){
			int x = Jew[i].dec - Jew[j].inc, y = Jew[i].dec + Jew[j].inc;
			if(abs(Jew[i].x - Jew[j].x) + abs(Jew[i].y - Jew[j].y) > K) continue;
			if(x / 2 < Jew[i].x && x / 2 < Jew[j].x)
				y += K;
			if(x % 2 == 1 && y % 2 == 1){ countDia((x + 1) / 2, (y + 1) / 2); countDia((x + 1) / 2, (y - 1) / 2); countDia((x - 1) / 2, (y + 1) / 2); countDia((x - 1) / 2, (y - 1) / 2); }
			if(x % 2 == 1){ countDia((x + 1) / 2, y / 2); countDia((x - 1) / 2, y / 2); }
			if(y % 2 == 1){ countDia(x / 2, (y + 1) / 2); countDia(x / 2, (y - 1) / 2); }
			if(x % 2 == 0 && y % 2 == 0) countDia(x / 2, y / 2);
		}
	}
	printf("%d %d\n%d\n", maxX, maxY, maxt);
	return 0;
}


