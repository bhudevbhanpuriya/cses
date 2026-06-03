#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> vis, parent;
int st = -1, en = -1;

bool dfs(int node, int par) {
    vis[node] = 1;

    for (auto neigh : adj[node]) {
        if (neigh == par) continue;

        if (vis[neigh]) {
            st = neigh;
            en = node;
            return true;
        }

        parent[neigh] = node;

        if (dfs(neigh, node))
            return true;
    }

    return false;
}

int main() {
    int n, m;
    cin >> n >> m;

    adj.resize(n + 1);
    vis.assign(n + 1, 0);
    parent.assign(n + 1, -1);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bool found = false;

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            if (dfs(i, -1)) {
                found = true;
                break;
            }
        }
    }

    if (!found) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    vector<int> cycle;
    cycle.push_back(st);

    for (int v = en; v != st; v = parent[v])
        cycle.push_back(v);

    cycle.push_back(st);

    reverse(cycle.begin(), cycle.end());

    cout << cycle.size() << "\n";
    for (auto x : cycle)
        cout << x << " ";
}