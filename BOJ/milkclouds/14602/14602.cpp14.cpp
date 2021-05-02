#include <bits/stdc++.h>
#define rep(i,a,b) for(int i = a; i < b; i++)
using namespace std;
typedef long long ll;
const int MAX=302;

int N,M,K,W,A[MAX][MAX];
int median(deque<int> deq){
	nth_element(deq.begin(),deq.begin()+deq.size()/2, deq.end());
	return deq[deq.size()/2];
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>M>>N>>K>>W;
	rep(i,0,M)rep(j,0,N)cin>>A[i][j];
	rep(i,0,M-W+1){
		deque<int> deq;
		rep(k1,0,W)rep(k2,0,W)deq.push_back(A[i+k2][k1]);
		rep(j,0,N-W+1){
			if(j){
				rep(_,0,W)deq.pop_front();
				rep(k,0,W)deq.push_back(A[i+k][j+W-1]);
			}
			cout<<median(deq)<<" ";
		}
		cout<<"\n";
	}
}