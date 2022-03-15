namespace CRT{
    using ull = unsigned long long;
    static constexpr ull MOD1 = 754974721, W1 = 11;  // 2^24
    static constexpr ull MOD2 = 167772161, W2 = 3;  // 2^25
    static constexpr ull MOD3 = 469762049, W3 = 3;  // 2^26 
    static constexpr ull M2M3 = MOD2 * MOD3;
    static constexpr ull M1M3 = MOD1 * MOD3;
    static constexpr ull M1M2 = MOD1 * MOD2;
    static constexpr ull M1M2M3 = MOD1 * MOD2 * MOD3;
    static constexpr ull i1 = 190329765;
    static constexpr ull i2 = 58587104;
    static constexpr ull i3 = 187290749;
    using mint1 = MINT<MOD1, W1>;
    using mint2 = MINT<MOD2, W2>;
    using mint3 = MINT<MOD3, W3>;
    mint CRT(mint1 a, mint2 b, mint3 c){
        return a.v * i1 * M2M3 + b.v * i2 * M1M3 + c.v * i3 * M1M2;
    }
}