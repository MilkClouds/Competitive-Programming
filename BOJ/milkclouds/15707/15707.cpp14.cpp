#include <iostream>
#include <vector>
#define EL printf("\n")
#define pb push_back
#define FOR(i,l,r) for (int i=l;i<=r;i++)
#define FORD(i,r,l) for (int i=r;i>=l;i--)
#define ll long long
using namespace std;

const int base=1e9;

typedef vector<int> BigInt;
void Set(BigInt &a) {
    while (a.size() > 1 && a.back() == 0) a.pop_back();
}
BigInt init(string s) {
    BigInt ans;
    if (s[0] == '-') return ans;
    if (s.size() == 0) {ans.pb(0); return ans;}
    while (s.size()%9 != 0) s = '0'+s;
    for (int i=0;i<s.size();i+=9) {
        int v = 0;
        for (int j=i;j<i+9;j++) v = v*10+(s[j]-'0');
        ans.insert(ans.begin(),v);
    }
    Set(ans);
    return ans;
}
bool operator < (BigInt a, BigInt b) {
	Set(a);Set(b);
    if (a.size() != b.size()) return (a.size() < b.size());
    FORD(i,a.size()-1,0)
        if (a[i] != b[i]) return (a[i] < b[i]);
    return false;
}
bool operator > (BigInt a, BigInt b) {
    return (b < a);
}
BigInt operator * (BigInt a,BigInt b){
	BigInt ans(a.size()+b.size(),0);
	FOR(i,0,a.size()-1) {
        ll carry = 0ll;
        for (int j=0;j<b.size() || carry > 0;j++) {
            ll s = ans[i+j] + carry + (ll)a[i]*(j<b.size()?(ll)b[j]:0ll);
            ans[i+j] = s%base;
            carry = s/base;
        }
    }
    Set(ans);
    return ans;
}
string str(BigInt a){
	string ret;
	Set(a);
	for(auto i:a)ret+=to_string(i);
	return ret;
}
void Print(BigInt a) {
    Set(a);
    printf("%d", (a.size() == 0) ? 0 : a.back());
    FORD(i,a.size()-2,0) printf("%09d", a[i]); EL;
}


int main(){
	string a,b,r;
	cin>>a>>b>>r;
	if(init(a)*init(b)>init(r))
		cout<<"overflow";
	else
		Print((init(a)*init(b)));
}