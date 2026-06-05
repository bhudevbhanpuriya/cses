#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

int dr[] = {0, 0, -1, 1};
int dc[] = {-1, 1, 0, 0};
char dir[] = {'L', 'R', 'U', 'D'};

int main() {
    fastio;

    int n, m;
    cin >> n >> m;

    vector<string> grid(n);

    pair<int,int> start;
    queue<pair<int,int>> q;

    vector<vector<int>> monster(n, vector<int>(m, INT_MAX));

    for(int i = 0; i < n; i++) {
        cin >> grid[i];

        for(int j = 0; j < m; j++) {
            if(grid[i][j] == 'A') {
                start = {i, j};
            }
            else if(grid[i][j] == 'M') {
                q.push({i, j});
                monster[i][j] = 0;
            }
        }
    }

    // Multi-source BFS from monsters
    while(!q.empty()) {
        auto [r, c] = q.front();
        q.pop();

        for(int k = 0; k < 4; k++) {
            int nr = r + dr[k];
            int nc = c + dc[k];

            if(nr < 0 || nr >= n || nc < 0 || nc >= m)
                continue;

            if(grid[nr][nc] == '#')
                continue;

            if(monster[nr][nc] > monster[r][c] + 1) {
                monster[nr][nc] = monster[r][c] + 1;
                q.push({nr, nc});
            }
        }
    }

    vector<vector<int>> dist(n, vector<int>(m, -1));
    vector<vector<char>> parent(n, vector<char>(m));

    q.push(start);
    dist[start.first][start.second] = 0;

    pair<int,int> exitCell = {-1, -1};

    while(!q.empty()) {
        auto [r, c] = q.front();
        q.pop();

        if(r == 0 || r == n - 1 || c == 0 || c == m - 1) {
            exitCell = {r, c};
            break;
        }

        for(int k = 0; k < 4; k++) {
            int nr = r + dr[k];
            int nc = c + dc[k];

            if(nr < 0 || nr >= n || nc < 0 || nc >= m)
                continue;

            if(grid[nr][nc] == '#')
                continue;

            if(dist[nr][nc] != -1)
                continue;

            int nextTime = dist[r][c] + 1;

            if(nextTime >= monster[nr][nc])
                continue;

            dist[nr][nc] = nextTime;
            parent[nr][nc] = dir[k];

            q.push({nr, nc});
        }
    }

    if(exitCell.first == -1) {
        cout << "NO\n";
        return 0;
    }

    string path;

    int r = exitCell.first;
    int c = exitCell.second;

    while(make_pair(r, c) != start) {
        char d = parent[r][c];
        path += d;

        if(d == 'L') c++;
        else if(d == 'R') c--;
        else if(d == 'U') r++;
        else if(d == 'D') r--;
    }

    reverse(path.begin(), path.end());

    cout << "YES\n";
    cout << path.size() << "\n";
    cout << path << "\n";

    return 0;
}