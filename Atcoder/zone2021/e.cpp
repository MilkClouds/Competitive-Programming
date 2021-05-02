# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>
#define rep(i,a,b) for(int i = (a); i < (b); i++)
#define rep2(i,a,b) for(int i = (b) - 1; i >= (a); i--)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define pb push_back
#define x first
#define y second
using namespace std;
using ll = long long;
using tl = tuple<ll, ll, ll, ll>;
using pl = pair<ll, ll>;
using pi = pair<int, int>;
using ld = long double;
using vi = vector<int>;

inline int readChar();
template<class T = int> inline T readInt();
template<class T> inline void writeInt(T x, char end = 0);
inline void writeChar(int x);
inline void writeWord(const char *s);
static const int buf_size = 1 << 18;
inline int getChar(){
    #ifndef LOCAL
    static char buf[buf_size];
    static int len = 0, pos = 0;
    if(pos == len) pos = 0, len = fread(buf, 1, buf_size, stdin);
    if(pos == len) return -1;
    return buf[pos++];
    #endif
}
inline int readChar(){
    #ifndef LOCAL
    int c = getChar();
    while(c <= 32) c = getChar();
    return c;
    #else
    char c; cin >> c; return c;
    #endif
}
template <class T>
inline T readInt(){
    #ifndef LOCAL
    int s = 1, c = readChar();
    T x = 0;
    if(c == '-') s = -1, c = getChar();
    while('0' <= c && c <= '9') x = x * 10 + c - '0', c = getChar();
    return s == 1 ? x : -x;
    #else
    T x; cin >> x; return x;
    #endif
}
static int write_pos = 0;
static char write_buf[buf_size];
inline void writeChar(int x){
    if(write_pos == buf_size) fwrite(write_buf, 1, buf_size, stdout), write_pos = 0;
    write_buf[write_pos++] = x;
}
template <class T>
inline void writeInt(T x, char end){
    if(x < 0) writeChar('-'), x = -x;
    char s[24]; int n = 0;
    while(x || !n) s[n++] = '0' + x % 10, x /= 10;
    while(n--) writeChar(s[n]);
    if(end) writeChar(end);
}
inline void writeWord(const char *s){
    while(*s) writeChar(*s++);
}
struct Flusher{
    ~Flusher(){ if(write_pos) fwrite(write_buf, 1, write_pos, stdout), write_pos = 0; }
}flusher;

const int INF = 2e9;
int R, C, A[510][510], B[510][510], X[510][510], Y[510][510];

struct ABC{
    pi v; int d;
    ABC(): ABC({0, 0}, 0) {}
    ABC(pi v, int d): v(v), d(d) {}
    bool operator < (ABC o) const {
        return d > o.d;
    }
};

vector<ABC> vABC;

void adj(pi u){
    int r = u.x, c = u.y;
    if(c < C){
        vABC.pb(ABC({r, c + 1}, A[r][c]));
    }
    if(c > 1){
        vABC.pb(ABC({r, c - 1}, A[r][c - 1]));
    }
    if(r < R){
        vABC.pb(ABC({r + 1, c}, B[r][c]));
    }
    rep(i, 1, r) vABC.pb(ABC({r - i, c}, 1 + i));
}

int dijkstra(pi S) {
    priority_queue<ABC> pq;
    register vector<vi> dist(R + 1, vi(C + 1, INF));
    dist[S.x][S.y] = 0;
    pq.push(ABC(S, 0));
    while (!pq.empty()) {
        int d, dd; pi u, v;
        u = pq.top().v; d = pq.top().d; pq.pop();
        if(d != dist[u.x][u.y]) continue;
        vABC.clear();
        adj(u);
        for(ABC& tmp : vABC) {
            v = tmp.v;
            dd = tmp.d;
            int nd = d + dd;
            if (dist[v.x][v.y] > nd) {
                dist[v.x][v.y] = nd;
                pq.push(ABC(v, nd));
            }
        }
    }
    return dist[R][C];
}

int get(int r, int c){
    cout << r << " " << c << endl;
    if(X[r][c] < INF) return X[r][c];
    if(r < R){
        get(r + 1, c);
        X[r][c] = Y[r + 1][c];
    }
    if(r > 1) X[r][c] = min(X[r][c], get(r - 1, c) + B[r - 1][c]);
    if(c > 1) X[r][c] = min(X[r][c], get(r, c - 1) + A[r][c]);
    if(c < C) X[r][c] = min(X[r][c], get(r, c + 1) + A[r][c + 1]);
    Y[r][c] = min(Y[r + 1][c], X[r][c] + 1);
    return X[r][c];
}

int main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    freopen("in.txt", "r", stdin);
    R = readInt();
    C = readInt();
    rep(i, 1, R + 1) rep(j, 1, C) A[i][j] = readInt();
    rep(i, 1, R) rep(j, 1, C + 1) B[i][j] = readInt();
    fill(X[0], X[R + 2], INF);
    fill(Y[0], Y[R + 2], INF);
    X[0][0] = Y[0][0] = 0;
    get(R, C);
    //cout << dijkstra({1, 1});
}
