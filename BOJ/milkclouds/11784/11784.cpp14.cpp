#include <bits/stdc++.h>
using namespace std;
char c[255];
int cv(int i){
	return i>='A'?i-'A'+10:i-'0';
}
int main(){
	for(int i=0;i<255;i++)c[i]=0;
	while(scanf("%s",&c)!=EOF){
		for(int i=0;c[i];i+=2){
			printf("%c",cv(c[i])*16+cv(c[i+1]));
		}
		for(int i=0;i<255;i++)c[i]=0;
		printf("\n");
	}
}