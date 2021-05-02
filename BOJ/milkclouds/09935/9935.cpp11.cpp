#include <stdio.h>
#include <string.h>
 
int n, m, pos;
char A[1000010], B[40], ans[1000010];
 
bool isMatching(int s) {
  for (int i = s ; i < s + m ; ++i) {
    if (ans[i] != B[i - s]) {
      return false;
    }
  }
  return true;
}
 
int main() {
  scanf("%s%s", A, B);
  n = (int)strlen(A);
  m = (int)strlen(B);
  for (int i = 0 ; i < n ; ++i) {
    ans[pos++] = A[i];
    if (pos - m >= 0 && isMatching(pos - m)) {
      pos -= m;
    }
  }
  ans[pos] = '\0';
  printf("%s\n", pos ? ans : "FRULA");
}