#include <cstdio>
#include <algorithm>
#include <map>
#include <string>
#include <stack>
using namespace std;
map<string, int> res;
map<int, string> cvt;
int m, n, c;
int main() {
    scanf("%d%d", &m, &n);
    cvt[0] = "zero ";
    cvt[1] = "one ";
    cvt[2] = "two ";
    cvt[3] = "three ";
    cvt[4] = "four ";
    cvt[5] = "five ";
    cvt[6] = "six ";
    cvt[7] = "seven ";
    cvt[8] = "eight ";
    cvt[9] = "nine ";
    for (int i = m; i <= n; i++) {
        string x = "";
        int t = i;
        stack<int> st;
        while (t) {
            st.push(t % 10);
            t /= 10;
        }
        while (st.size()) {
            x += cvt[st.top()];
            st.pop();
        }
        res[x] = i;
    }
    for (auto it : res) {
        c++;
        printf("%d ", it.second);
        if (!(c % 10))puts("");
    }
    return 0;
}




//

