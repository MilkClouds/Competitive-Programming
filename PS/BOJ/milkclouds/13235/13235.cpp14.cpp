#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

char c;
vector<char> v,u;

int main()
{
	while(~scanf("%c",&c))if('a'<=c and c<='z')v.push_back(c);
	u=v;reverse(v.begin(), v.end());
	cout<<(u==v?"true":"false");
}