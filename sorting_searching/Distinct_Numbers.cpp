#include <bits/stdc++.h>
using namespace std;
 
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define vll vector<ll>
#define vpii vector<pii>
#define all(v) v.begin(), v.end()
const ll MOD = 1e9 + 7;
const ll INF = 1e18;
const ld EPS = 1e-9;
#ifdef DEBUG
#define dbg(x) cerr << #x << " = " << (x) << endl;
#else
#define dbg(x)
#endif
 
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }
ll mod_add(ll a, ll b, ll mod = MOD) { return (a + b) % mod; }
ll mod_sub(ll a, ll b, ll mod = MOD) { return (a - b + mod) % mod; }
ll mod_mul(ll a, ll b, ll mod = MOD) { return (a * b) % mod; }
ll mod_pow(ll a, ll b, ll mod = MOD) {
    ll res = 1;
    while (b > 0) {
        if (b & 1) res = mod_mul(res, a, mod);
        a = mod_mul(a, a, mod);
        b >>= 1;
    }
    return res;
}
ll mod_inv(ll a, ll mod = MOD) { return mod_pow(a, mod - 2, mod); }
 
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define input(v) forn(i,v.size()) cin>>v[i];
 
void solve() {
    int n;
    cin>>n;
    vll v(n);
    map<int,int>mpp;
    ll cnt=0;
    forn(i,n){
        cin>>v[i];
        mpp[v[i]]++;
        if(mpp[v[i]]==1) cnt++;
    }
    cout<<cnt<<endl;
}
 
 
int main() {
    fast_io;
    int t=1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
