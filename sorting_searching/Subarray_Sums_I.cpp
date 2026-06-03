#include <bits/stdc++.h>
using namespace std;

/*

2 4 1 2 7

r = 4 ,l = 4

sum = 7

cnt = 1 + 2 + 3 + 3 + 1 = 

*/

int sumlessorequal(int x, vector<int>& v){
    int n = v.size();
    int l=0 , r=0;
    int cnt = 0 , sum = 0;

    while(r<n){
        sum += v[r];
        while(sum > x && l<=r){
            sum -= v[l];
            l++;
        }
        cnt += (r-l+1);
        r++;
    }
    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, x;
    cin>>n>>x;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    cout<< sumlessorequal(x,v) - sumlessorequal(x-1,v);

    return 0;
}