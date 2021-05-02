#include <bits/stdc++.h>
#define rep(i,a,b) for(int i = a; i < b; i++)
using namespace std;
int T;
string s,S;
unordered_map<string,char> mm;
int main(){
	cin>>T;
	mm[".-"] = 'A';
	mm["-..."] = 'B';
	mm["-.-."] = 'C';
	mm["-.."] = 'D';
	mm["."] = 'E';
	mm["..-."] = 'F';
	mm["--."] = 'G';
	mm["...."] = 'H';
	mm[".."] = 'I';
	mm[".---"] = 'J';
	mm["-.-"] = 'K';
	mm[".-.."] = 'L';
	mm["--"] = 'M';
	mm["-."] = 'N';
	mm["---"] = 'O';
	mm[".--."] = 'P';
	mm["--.-"] = 'Q';
	mm[".-."] = 'R';
	mm["..."] = 'S';
	mm["-"] = 'T';
	mm["..-"] = 'U';
	mm["...-"] = 'V';
	mm[".--"] = 'W';
	mm["-..-"] = 'X';
	mm["-.--"] = 'Y';
	mm["--.."] = 'Z';
	rep(TC,1,T+1){
		S="";
		rep(_,0,5){cin>>s;S+=mm[s];}
		cout<<"Case "<<TC<<": "<<S<<"\n";
	}
}