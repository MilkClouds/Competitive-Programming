#include <bits/stdc++.h>
using namespace std;

multimap<int,string> m;
int main(){
	m.insert({1967,"DavidBowie"});
m.insert({1969,"SpaceOddity"});
m.insert({1970,"TheManWhoSoldTheWorld"});
m.insert({1971,"HunkyDory"});
m.insert({1972,"TheRiseAndFallOfZiggyStardustAndTheSpidersFromMars"});
m.insert({1973,"AladdinSane"});
m.insert({1973,"PinUps"});
m.insert({1974,"DiamondDogs"});
m.insert({1975,"YoungAmericans"});
m.insert({1976,"StationToStation"});
m.insert({1977,"Low"});
m.insert({1977,"Heroes"});
m.insert({1979,"Lodger"});
m.insert({1980,"ScaryMonstersAndSuperCreeps"});
m.insert({1983,"LetsDance"});
m.insert({1984,"Tonight"});
m.insert({1987,"NeverLetMeDown"});
m.insert({1993,"BlackTieWhiteNoise"});
m.insert({1995,"1.Outside"});
m.insert({1997,"Earthling"});
m.insert({1999,"Hours"});
m.insert({2002,"Heathen"});
m.insert({2003,"Reality"});
m.insert({2013,"TheNextDay"});
m.insert({2016,"BlackStar"});
	int n;
	cin>>n;
	while(n--){
		int a,b,cnt=0;
		cin>>a>>b;
		for(int i=a;i<=b;i++){
			for(auto iter=m.equal_range(i).first; iter->first==i;iter++){cnt++;}
		}
		cout<<cnt<<"\n";
		for(int i=a;i<=b;i++){
			for(auto iter=m.equal_range(i).first; iter->first==i;iter++){cout<<i<<" "<<iter->second<<"\n";}
		}
	}
}