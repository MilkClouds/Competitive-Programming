using ll = long long;


template<typename T>
T pw(T a, ll b){
    T ret = T(1);
    for(; b; b >>= 1, a *= a) if(b & 1) ret *= a;
    return ret;
}

ll pw(ll a, ll b, ll M){
    ll ret = 1;
    for(; b; b >>= 1, a = (a * a) % M) if(b & 1) ret = (a * ret) % M;
    return ret;
}