#include <bits/stdc++.h>

using namespace std;

char c;
int main(){
	int cur=0;
	while(scanf("%c",&c)!=EOF){
		if("UCPC"[cur]==c)cur++;
		if(cur==4){
			cout<<"I love UCPC";
			return 0;
		}
	}
	cout<<"I hate UCPC";	
}