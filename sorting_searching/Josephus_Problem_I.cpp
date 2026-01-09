#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    queue<int> q;
    for (int i = 1; i <= n; i++) {
        q.push(i);
    }

    while (!q.empty()) {
        // skip one child
        q.push(q.front());
        q.pop();

        // remove next child
        cout << q.front() << " ";
        q.pop();
    }

    return 0;
}
