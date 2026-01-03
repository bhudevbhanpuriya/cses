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
 
 
///////////////////////////////////////////////////////////
 
void solve() {
    ll n,m,k;
    cin>>n>>m>>k;
    vll ap(n);
    vll av(m);
    for(int i=0;i<n;i++){
        cin>>ap[i];
    }
    for(int i=0;i<n;i++){
        cin>>av[i];
    }
    sort(ap.begin(),ap.end());
    sort(av.begin(),av.end());
    ll cnt=0;
    int i=0,j=0;
    while(i<n && j<m){
        int low = av[j]-k;
        int high = av[j]+k;
 
        if(ap[i]>high){
            j++;
        }
        else if(ap[i]<low){
            i++;
        }
        else if(low<=ap[i] && ap[i]<=high){
            cnt++;
            i++;
            j++;
        }
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