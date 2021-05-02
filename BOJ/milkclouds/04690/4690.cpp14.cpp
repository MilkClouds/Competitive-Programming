#include <bits/stdc++.h>

using namespace std;

int main(){
	for(int a=2;a<=100;a++){
		for(int b=2;b<=a;b++){
			for(int c=b;c<=a;c++){
				for(int d=c;d<=a;d++)
					if(a*a*a==pow(b,3)+pow(c,3)+pow(d,3)){
						printf("Cube = %d, Triple = (%d,%d,%d)\n",a,b,c,d);
					}
			}
		}
	}
}