
int lcs(std::string A, std::string B) {
  int N = A.size(), M = B.size();
  int sz = (M >> 6) + 1;

  std::vector<ulint> S[256];
  for(int c = 0; c < 256; c++) S[c].resize(sz);
  for(int j = 0; j < M; j++) set(S[B[j]], j);
  
  std::vector<ulint> row(sz);
  for(int j = 0; j < M; j++) if(A[0] == B[j]) { set(row, j); break; }

  for(int i = 1; i < N; i++) {
    ulint shl_carry = 1;
    ulint minus_carry = 0;
    
    for(int k = 0; k < sz; k++) {
      // Compute k-th block of x == S[A[i]] OR D[i-1]
      ulint x_k = S[A[i]][k] | row[k];

      // Compute k-th block of "(D[i-1] << 1) | 1"
      ulint term_1 = (row[k] << 1) | shl_carry;
      shl_carry = row[k] >> 63;

      // Compute k-th block of "x - ((D[i-1] << 1) | 1)"
      auto sub_carry = [](ulint &x, ulint y){
        ulint tmp = x;
        return (x = tmp - y) > tmp;
      };
      ulint term_2 = x_k;
      minus_carry = sub_carry(term_2, minus_carry);
      minus_carry += sub_carry(term_2, term_1);
      
      row[k] = x_k & (x_k ^ term_2);
    }

    row[M >> 6] &= (1llu << (M & 63)) - 1;
  }

  int ret = 0;
  for(int j = 0; j < M; j++) if(get(row, j)) ret += 1;
  return ret;
}