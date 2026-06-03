#include <bits/stdc++.h>
using namespace std;

#define ll long long

int dr[] = {0, 0, -1, 1};
int dc[] = {-1, 1, 0, 0};
char dir[] = {'L', 'R', 'U', 'D'};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m;
    cin >> n >> m;

    vector<vector<char>> mat(n, vector<char>(m));

    int st_r, st_c, end_r, end_c;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mat[i][j];

            if (mat[i][j] == 'A') {
                st_r = i;
                st_c = j;
            }
            else if (mat[i][j] == 'B') {
                end_r = i;
                end_c = j;
            }
        }
    }

    vector<vector<bool>> vis(n, vector<bool>(m, false));

    vector<vector<pair<pair<int, int>, char>>> par(
        n,
        vector<pair<pair<int, int>, char>>(m, {{-1, -1}, '_'})
    );

    queue<pair<int, int>> q;

    q.push({st_r, st_c});
    vis[st_r][st_c] = true;

    bool found = false;

    while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop();

        if (r == end_r && c == end_c) {
            found = true;
            break;
        }

        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr >= 0 && nr < n &&
                nc >= 0 && nc < m &&
                !vis[nr][nc] &&
                mat[nr][nc] != '#') {

                vis[nr][nc] = true;
                par[nr][nc] = {{r, c}, dir[i]};
                q.push({nr, nc});
            }
        }
    }

    if (!found) {
        cout << "NO\n";
        return 0;
    }

    string path;

    int r = end_r;
    int c = end_c;

    while (!(r == st_r && c == st_c)) {
        path += par[r][c].second;

        int pr = par[r][c].first.first;
        int pc = par[r][c].first.second;

        r = pr;
        c = pc;
    }

    reverse(path.begin(), path.end());

    cout << "YES\n";
    cout << path.size() << '\n';
    cout << path << '\n';

    return 0;
}