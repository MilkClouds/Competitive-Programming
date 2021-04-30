#include <cstdio>
#include <cstring>

using namespace std;

#define SLOVA 26
#define NIZ 300000
#define RIJECI 4000
#define LEN 100
#define MOD 1337377

char niz[NIZ+1];
int dp[NIZ+1];

struct node {
   char flag;
   int p[SLOVA];
   void clear() { memset( p, -1, sizeof p ); flag = 0; }
};
node dict[RIJECI*LEN];
int new_node() {
   static int mem_ptr = 0;
   dict[mem_ptr].clear();
   return mem_ptr++;
}

int main( void ) {
   int n, m;
   gets( niz );
   m = strlen( niz );
   scanf( "%d", &n );

   int root = new_node();
   for( int i = 0; i < n; ++i ) {
      static char buff[LEN+1];
      scanf( "%s", buff );

      int t = root;
      for( char *c = buff; *c; ++c ) {
         if( dict[t].p[*c-'a'] == -1 ) dict[t].p[*c-'a'] = new_node();
         t = dict[t].p[*c-'a'];
      }
      dict[t].flag = 1;
   }

   dp[m] = 1;

   for( int i = m-1; i >= 0; --i ) {
      int t = root;
      for( int j = i; j < m; ++j ) {
         t = dict[t].p[niz[j]-'a'];
         if( t == -1 ) break;

         if( dict[t].flag ) dp[i] = ( dp[i] + dp[j+1] ) % MOD;
      }
      dp[i] %= MOD;
   }

   printf( "%d\n", dp[0] );

   return 0;
}
