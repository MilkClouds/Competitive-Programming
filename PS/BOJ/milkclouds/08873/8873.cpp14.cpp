#include <bits/stdc++.h>
using namespace std;


int lo( long long x ){
  int s = 0;
  while( x > 0 ){
    s++;
    x /= 2;
  }
  return s;
}

vector<long long> vars( int H, int W, int a[500][500], int sz ){
  vector<long long> v(0);
  for( int i = sz; i < H-sz; i++ ){
    for( int j = sz; j < W-sz; j++ ){
      int ave = 0;
      for( int y = -sz; y <= sz; y++ ){
        for( int x = -sz; x <= sz; x++ ){
          ave += a[i+y][j+x];
        }
      }
      ave /= (sz*2+1)*(sz*2+1);
      long long res = 0;
      for( int y = -sz; y <= sz; y++ ){
        for( int x = -sz; x <= sz; x++ ){
          long long d = ( ave - a[i+y][j+x] );
          res += d * d;
        }
      }
      v.push_back( res );
    }
  }
  return v;
}


int style( int H, int W, int R[500][500], int G[500][500], int B[500][500] ){
  int a[500][500];
  for( int i = 0; i < H; i++ ){
    for( int j = 0; j < W; j++ ){
      a[i][j] = R[i][j] + G[i][j] + B[i][j];;
    }
  }
  vector<long long> v = vars(H,W,a,1);
  sort( v.begin(), v.end() );
  long long sum = 0;
  for( int i = 0; i < v.size(); i++ ){
    sum += v[i];
  }
  int s = lo( sum );
  int t = lo(v[v.size()/2]);
  if( s <= 29 ){
    return 4;
  }
  if( t <= 11 ){
    return 1;
  }
  v = vars(H,W,a,32);
  sort( v.begin(), v.end() );
  int u = lo(v[int(v.size()*0.1)]);
  if( u <= 25 ){
    return 2;
  }
  return 3;
}



int main(){
	int H,W,R[500][500],G[500][500],B[500][500];
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>H>>W;
	for(int i=0;i<H;i++)for(int j=0;j<W;j++)cin>>R[i][j];
	for(int i=0;i<H;i++)for(int j=0;j<W;j++)cin>>G[i][j];
	for(int i=0;i<H;i++)for(int j=0;j<W;j++)cin>>B[i][j];
	cout<<style(H,W,R,G,B);
}