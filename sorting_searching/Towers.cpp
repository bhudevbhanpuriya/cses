#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define sz(v) (int)v.size()
#define fi first
#define s second
#define pb push_back
#define endl '\n'

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

const ll MOD = 1e9 + 7;
const ll INF = 1e18;
const ll EPS = 1e-9;

#ifndef ONLINE_JUDGE
    #define debug(x) cerr << #x << " = "; _print(x); cerr << endl;
    template <typename T> void _print(T t) { cerr << t; }
    template <typename T, typename V> void _print(pair<T, V> p) { cerr << "{" << p.first << ", " << p.second << "}"; }
    template <typename T> void _print(vector<T> v) { cerr << "[ "; for (T i : v) _print(i), cerr << " "; cerr << "]"; }
#else
    #define debug(x)
#endif

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }
ll mod_add(ll a, ll b, ll mod = MOD) { return (a + b) % mod; }
ll mod_sub(ll a, ll b, ll mod = MOD) { return (a - b + mod) % mod; }
ll mod_mul(ll a, ll b, ll mod = MOD) { return (a * b) % mod; }
ll mod_pow(ll a, ll b, ll mod = MOD) { ll res = 1; while (b > 0) { if (b & 1) res = mod_mul(res, a, mod); a = mod_mul(a, a, mod); b >>= 1; } return res; } 
ll mod_exp(ll b, ll e, ll m) { ll r = 1; while (e) { if (e & 1) r = (r * b) % m; b = (b * b) % m; e >>= 1; } return r; }
template <typename T> void vin(vector<T>& v) { for (auto& x : v) cin >> x; }
template <typename T> void vout(const vector<T>& v) { for (auto& x : v) cout << x << " "; cout << endl; }
vll divisors(ll n) { vll d; for (ll i = 1; i * i <= n; ++i) if (n % i == 0) d.pb(i), (i != n / i ? d.pb(n / i) : void()); sort(all(d)); return d; }
vll get_primes(ll n) { std::vector<bool> is_prime(n + 1, true); vll primes; for (ll i = 2; i <= n; ++i) if (is_prime[i]) { primes.push_back(i); for (ll j = i * i; j <= n; j += i) is_prime[j] = false; } return primes; }
ll modInverse(ll a, ll m) {ll m0 = m, t, q; ll x0 = 0, x1 = 1; if (m == 1) return 0; while (a > 1) { q = a / m; t = m; m = a % m; a = t; t = x0; x0 = x1 - q * x0; x1 = t; }if (x1 < 0) x1 += m0; return x1;}

#define forn(i, n) for (ll i = 0; i < ll(n); i++)
#define yes cout << 'Y' << 'E' << 'S' << endl;
#define no cout << 'N' << 'O' << endl;
template <typename T> void print(const T& value) {cout << value << endl;}
#define f(i,s,e) for(long long int i=s;i<e;i++)
#define rf(i,e,s) for(long long int i=e-1;i>=s;i--)
#define ump unordered_map<long long,long long>

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

int upperBound(int num , vll&v){
    int low = 0 , high = v.size()-1;
    int ind = v.size();
    while(low <= high){
        int mid = low + (high - low)/2;
        if(v[mid] <= num){
            low = mid+1;
        }else {
            high = mid-1;
            ind = mid;
        }
    }
    return ind;
}

int lowerBound(int num , vector<int>&v){
    int low = 0 , high = v.size()-1;
    int ind = 0;
    while(low <= high){
        int mid = low + (high - low)/2;
        if(v[mid] < num){
            ind = low;
            low = mid+1;
        }else high = mid-1;
    }
    return ind;
}

void solve() {
    ll n;
    cin>>n;
    vll v(n);
    vin(v);
    vll towers;
    towers.push_back(v[0]);
    for(int i=1;i<n;i++){
        int ind = upperBound(v[i] , towers);
        if(ind == towers.size()) towers.push_back(v[i]);
        else towers[ind] = v[i];
    }
    print(towers.size());
}


int main() {
    fastio;
    ll t=1;
    // cin >> t;
    while (t--) solve();
    return 0;
}
