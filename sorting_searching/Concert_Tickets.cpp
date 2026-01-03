#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define sz(v) (int)v.size()
#define f first
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
template <typename T> void input(vector<T>& v) { for (auto& x : v) cin >> x; }
template <typename T> void display(const vector<T>& v) { for (auto& x : v) cout << x << " "; cout << endl; }
vll divisors(ll n) { vll d; for (ll i = 1; i * i <= n; ++i) if (n % i == 0) d.pb(i), (i != n / i ? d.pb(n / i) : void()); sort(all(d)); return d; }
vll get_primes(ll n) { std::vector<bool> is_prime(n + 1, true); vll primes; for (ll i = 2; i <= n; ++i) if (is_prime[i]) { primes.push_back(i); for (ll j = i * i; j <= n; j += i) is_prime[j] = false; } return primes; }
#define forn(i, n) for (ll i = 0; i < ll(n); i++)

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
multiset<int> tickets;
void solve() {
    ll n,m;
    cin>>n>>m;
    vll ans(m);
    for(int i=0;i<n;i++){
        int h; cin>>h;
        tickets.insert(h);
    }
    for(int i=0;i<m;i++){
        int tt;cin>>tt;
        auto it=tickets.upper_bound(tt);
        if(it==tickets.begin()) ans[i]=-1;
        else {
            it--;
            ans[i]=(*it);
            tickets.erase(it);
        }
    }
    forn(i,m) cout<<ans[i]<<"\n";
}


int main() {
    fastio;
    ll t=1;
    //cin >> t;

    while (t--) {
       solve();
    }
    return 0;
}