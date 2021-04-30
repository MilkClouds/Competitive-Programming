#include <cstdio>

#include <cstring>

#include <cmath>

#include <algorithm>

#include <vector>

using namespace std;

int N, M, L, K;

int arr[301][301];

vector<vector<int>> ans;

struct Segment {

    vector<int> tree;

    int size;

    Segment() {}

    Segment(int N) :size(N + 1) { tree.resize(4 * (N + 1), 0); }

    int update(int idx, int val, int node, int nl, int nr) {

        if (idx < nl || idx > nr) return tree[node];

        if (nl == nr) return tree[node] += val;

        int mid = (nl + nr) >> 1;

        return tree[node] = update(idx, val, node * 2, nl, mid) + update(idx, val, node * 2 + 1, mid + 1, nr);

    }

    void update(int idx, int val) {

        update(idx, val, 1, 0, size - 1);

    }

    int query(int val, int node, int nl, int nr) {

        if (nl == nr) return nl;

        int mid = (nl + nr) >> 1;

        if (tree[node * 2] >= val) return query(val, node * 2, nl, mid);

        else return query(val - tree[node * 2], node * 2 + 1, mid + 1, nr);

    }

    int query(int val) {

        return query(val, 1, 0, size - 1);

    }

};

int main() {

    scanf("%d%d%d%d", &N, &M, &L, &K);

    Segment seg(L);

    for (int n = 0;n < N;n++) for (int m = 0;m < M;m++) scanf("%d", &arr[n][m]);


    for (int n = 0;n < K;n++) for (int m = 0;m < K;m++)seg.update(arr[n][m], 1);

    for (int n = 0;n < N - K + 1;n++) {

        if (!(n & 1)) {        // ->

            vector<int> tmp;

            if (n != 0)

                for (int m = 0;m < K;m++) seg.update(arr[n - 1][m], -1), seg.update(arr[n + K - 1][m], 1);

            for (int m = 0;m < M - K + 1;m++) {

                if (m == 0) {}

                else {

                    for (int y = n;y < n + K;y++) seg.update(arr[y][m - 1], -1);

                    for (int y = n;y < n + K;y++) seg.update(arr[y][m + K - 1], 1);

                }

                tmp.push_back(seg.query((K*K + 1) / 2));

            }

            ans.push_back(tmp);

        }

        else {            // <-

            vector<int> tmp;

            for (int m = M - K;m < M;m++) seg.update(arr[n - 1][m], -1), seg.update(arr[n + K - 1][m], 1);

            for (int m = M - K;m >= 0;m--) {

                if (m == M - K) {}

                else {

                    for (int y = n;y < n + K;y++) seg.update(arr[y][m + K], -1);

                    for (int y = n;y < n + K;y++) seg.update(arr[y][m], 1);

                }

                tmp.push_back(seg.query((K*K + 1) / 2));

            }

            reverse(tmp.begin(), tmp.end());

            ans.push_back(tmp);

        }

    }


    for (auto &n : ans) {

        for (auto &m : n) printf("%d ", m);

        printf("\n");

    }

    return 0;

}