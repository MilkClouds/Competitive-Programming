#include <bits/stdc++.h>
#define x first
#define y second
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;

typedef pair<int,int> pii;
int solve(){
	int n,x,d,h,cnt=0;
	cin>>n>>x;
	vector<pii> kill, deal;
	for(int i=0;i<n;i++){
		cin>>d>>h;
		kill.pb({d,i});
		deal.pb({d-h,i});
	}
	sort(all(kill), greater<pii>());
	sort(all(deal), greater<pii>());
	int t=max(0,(x-kill[0].x));
	if(t>0 && deal[0].x<=0)return -1;
	return 1+ t/deal[0].x + (t%deal[0].x>0);
}
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	int Q;
	cin>>Q;
	while(Q--){
		cout<<solve()<<'\n';
	}
	return 0;
}