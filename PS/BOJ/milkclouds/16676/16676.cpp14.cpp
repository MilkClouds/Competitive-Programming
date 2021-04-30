#include <iostream>
using namespace std;
int n;
int main(){
	cin>>n;
	if(n<=10)cout<<1;
	else if(n<=110)cout<<2;
	else if(n<=1110)cout<<3;
	else if(n<=11110)cout<<4;
	else if (n<= 111110) 
 			cout<<5; 
 		else if (111111 <= n && n <= 1111110) 
 			cout<<6; 
 		else if (1111111 <= n && n <= 11111110) 
 			cout<<7; 
 		else if (11111111 <= n && n <= 111111110) 
 			cout<<8; 
 		else if (111111111 <= n && n <= 1111111110) 
 			cout<<9; 

}