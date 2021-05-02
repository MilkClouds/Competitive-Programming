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
int R, C, A[510][510], B[510][510];

struct Node{
    int r, c, dim;
    Node(): Node(0, 0, 0) {}
    Node(int r, int c): Node(r, c, 0) {}
    Node(int r, int c, int dim): r(r), c(c), dim(dim) {}
    bool operator <(const Node& o) const {return make_tuple(r, c, dim) < make_tuple(o.r, o.c, o.dim);}
};

struct ABC{
    Node v; int d;
    ABC(): ABC({0, 0, 0}, 0) {}
    ABC(Node v, int d): v(v), d(d) {}
    bool operator < (const ABC& o) const {
        return d > o.d;
    }
};

struct distance_object{
    map<Node, int> m;
    int get(Node k){
        if(m.find(k) != m.end()) return m[k];
        return INF;
    }
    void set(Node v, int d){
        m[v] = d;
    }
} dist;

vector<ABC> adj(Node u){
    int r = u.r, c = u.c;
    vector<ABC> vABC;
    if(u.dim == 1){
        vABC.pb(ABC({r, c, 0}, 0));
        if(r > 1) vABC.pb(ABC({r - 1, c, 1}, 1));
        return vABC;
    }
    if(c < C){
        vABC.pb(ABC({r, c + 1}, A[r][c]));
    }
    if(c > 1){
        vABC.pb(ABC({r, c - 1}, A[r][c - 1]));
    }
    if(r < R){
        vABC.pb(ABC({r + 1, c}, B[r][c]));
    }
    vABC.pb({{r, c, 1}, 1});
    return vABC;
}

int dijkstra(Node S) {
    priority_queue<ABC> pq;
    dist.set(S, 0);
    pq.push(ABC(S, 0));
    while (!pq.empty()) {
        int d, dd; Node u, v;
        u = pq.top().v; d = pq.top().d; pq.pop();
        if(d != dist.get(u)) continue;
        for(ABC& tmp : adj(u)) {
            v = tmp.v;
            dd = tmp.d;
            int nd = d + dd;
            if (dist.get(v) > nd) {
                dist.set(v, nd);
                pq.push(ABC(v, nd));
            }
        }
    }
    return dist.get({R, C});
}

int main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    R = readInt();
    C = readInt();
    rep(i, 1, R + 1) rep(j, 1, C) A[i][j] = readInt();
    rep(i, 1, R) rep(j, 1, C + 1) B[i][j] = readInt();
    cout << dijkstra({1, 1});
}
