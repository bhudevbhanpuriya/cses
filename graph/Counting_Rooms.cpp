#include <bits/stdc++.h>
using namespace std;

#define ll long long

int dr[] = {0,0,-1,1};
int dc[] = {-1,1,0,0};


void dfs(ll r, ll c , vector<vector<char>>& mat, vector<vector<bool>>& vis, ll n , ll m){
    vis[r][c] = true;

    for(int i=0;i<4;i++){
        ll nr = r + dr[i];
        ll nc = c + dc[i];
        
        if(nr>=0 && nr<n && nc>=0 && nc<m && mat[nr][nc] == '.' && !vis[nr][nc]){
            dfs(nr,nc,mat,vis,n,m);
        }
    }

}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    
    ll n,m;
    cin>>n>>m;

    vector<vector<char>> mat(n,vector<char>(m));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>mat[i][j];
        }
    }

    vector<vector<bool>> vis(n,vector<bool>(m,false));

    ll cnt  =0;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mat[i][j] == '.' && !vis[i][j]){
                cnt++;
                dfs(i,j,mat,vis,n,m);
            }
        }
    }

    cout<<cnt<<endl;


    return 0;
}