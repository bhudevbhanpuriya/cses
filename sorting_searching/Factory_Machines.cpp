#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(0); cin.tie(0)
#define all(v) v.begin(), v.end()
#define endl '\n'

typedef long long ll;
typedef vector<ll> vll;

bool canMake(ll mid, ll t, vll &v) {
    ll cnt = 0;
    for (ll x : v) {
        cnt += mid / x;
        if (cnt >= t) return true; 
    }
    return false;
}

int main() {
    fastio;
    ll n, t;
    cin >> n >> t;
    vll v(n);
    for (ll &x : v) cin >> x;
    ll low = 1;
    ll high = (*min_element(all(v))) * t;
    ll ans = high;
    while (low <= high) {
        ll mid = low + (high - low) / 2;
        if(canMake(mid, t, v)) {
            ans = mid;
            high = mid - 1;
        }else {
            low = mid + 1;
        }
    }
    cout<<ans<<endl;
    // print(ans);
    return 0;
}
