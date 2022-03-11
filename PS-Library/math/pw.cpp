using ll = long long;


template<typename T>
T pw(T a, ll b){
    T ret = T(1);
    for(; b; b >>= 1, a *= a) ret *= a;
    return ret;
}