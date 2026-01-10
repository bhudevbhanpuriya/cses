#include <bits/stdc++.h>
using namespace std;

struct Fenwick {
    int n;
    vector<int> bit;
    Fenwick(int n) : n(n), bit(n+1, 0) {}

    void update(int i, int v) {
        for (++i; i <= n; i += i & -i)
            bit[i] += v;
    }

    int query(int i) { // sum [0..i]
        int s = 0;
        for (++i; i > 0; i -= i & -i)
            s += bit[i];
        return s;
    }

    // find smallest index such that prefix sum >= k
    int find_kth(int k) {
        int idx = 0;
        for (int p = 1 << 18; p > 0; p >>= 1) {
            if (idx + p <= n && bit[idx + p] < k) {
                k -= bit[idx + p];
                idx += p;
            }
        }
        return idx; // 0-based
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long k;
    cin >> n >> k;

    Fenwick fw(n);
    for (int i = 0; i < n; i++)
        fw.update(i, 1); // all alive

    long long idx = 0;
    int rem = n;

    while (rem) {
        idx = (idx + k) % rem;
        int pos = fw.find_kth(idx + 1);
        cout << pos + 1 << " ";
        fw.update(pos, -1);
        rem--;
    }
}
