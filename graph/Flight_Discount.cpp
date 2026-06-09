#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll INF = 1e18;

vector<ll> dijkstra(int src, vector<vector<pair<int,ll>>> &adj, int n) {
    vector<ll> dist(n + 1, INF);
    priority_queue<
        pair<ll,int>,
        vector<pair<ll,int>>,
        greater<pair<ll,int>>
    > pq;

    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (d != dist[u]) continue;

        for (auto &[v, w] : adj[u]) {
            if (dist[v] > d + w) {
                dist[v] = d + w;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int,ll>>> adj(n + 1), rev(n + 1);

    vector<tuple<int,int,ll>> edges;

    for (int i = 0; i < m; i++) {
        int a, b;
        ll c;
        cin >> a >> b >> c;

        adj[a].push_back({b, c});
        rev[b].push_back({a, c});

        edges.push_back({a, b, c});
    }

    vector<ll> dist1 = dijkstra(1, adj, n);
    vector<ll> distN = dijkstra(n, rev, n);

    ll ans = INF;

    for (auto &[u, v, w] : edges) {
        if (dist1[u] == INF || distN[v] == INF) continue;

        ans = min(ans, dist1[u] + w / 2 + distN[v]);
    }

    cout << ans << '\n';

    return 0;
}