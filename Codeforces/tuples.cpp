#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define pyes cout << "YES" << "\n";
#define pno cout << "NO" << "\n";
#define br cout << "\n";
#define ff first
#define ss second
#define pb push_back
#define mod 1000000007
#define MOD 998244353
#define inf 9223372036854775807
#define all(x) (x).begin(),(x).end() 
typedef long long ll;
#define vil vector<ll>
#define vb vector<bool>
#define viil vector<vector<ll>>
typedef unsigned long long ull;
typedef long double lld;
#ifndef ONLINE_JUDGE
#define debug(x) cout << #x << " -> "; _print(x); cout << endl;
#else
#define debug(x)
#endif
void _print(ll t) {cout << t;}
void _print(int t) {cout << t;}
void _print(string t) {cout << t;}
void _print(char t) {cout << t;}
void _print(lld t) {cout << t;}
void _print(double t) {cout << t;}
void _print(ull t) {cout << t;}
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cout << "{"; _print(p.ff); cout << ","; _print(p.ss); cout << "}";}
template <class T> void _print(vector <T> v) {cout << "[ "; for (T i : v) {_print(i); cout << " ";} cout << "]";}
template <class T> void _print(set <T> v) {cout << "[ "; for (T i : v) {_print(i); cout << " ";} cout << "]";}
template <class T> void _print(multiset <T> v) {cout << "[ "; for (T i : v) {_print(i); cout << " ";} cout << "]";}
template <class T, class V> void _print(map <T, V> v) {cout << "[ "; for (auto i : v) {_print(i); cout << " ";} cout << "]";} 
ll ceil_div(ll a, ll b) {return a % b == 0 ? a / b : a / b + 1;}
ll gcd(ll a, ll b){ if (a == 0ll) { return b;} return gcd(b % a, a);}
void solve(){
    ll n;
    cin >> n;
    vil a(n), b(n);
    for (ll i = 0; i < n;i++){
        cin >> a[i];
    }
    for (ll i = 0; i < n;i++){
        cin >> b[i];
    }
    vector<vector<vector<ll>>> dp(n, vector<vector<ll>>(n+1,vector<ll>(n,0)));
    for (int i = 0; i < n;i++){
        dp[1][i][i] = 1;
    }
    unordered_map<ll, ll> mp, count, vis;
    for (int i = 0; i < n;i++){
        for (int j = n - 1; j >= 0;j--){
            if(a[i]==b[j])
                mp[i] = j;
        }
        count[a[i]]++;
    }
    for (int i = 0; i < n;i++){
        count[a[i]]--;
        if(count[a[i]]==0)
            count.erase(a[i]);
        if(vis.find(a[i])!=vis.end())
            continue;
        ll cnt = 0;
        for (ll j = mp[i]; j < n;j++){
            if(count.find(b[j])!=count.end()){
                dp[2][i][j] = j;
            }
        }
        vis[a[i]] = 1;
    }
    for (ll i = 3; i <= n;i++){

        for (ll j = 0; j < n;j++){
            for (ll k = 0; k < n;k++){
                  
            }
           
        }
    }
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("Error.txt", "w", stderr);
#endif // ONLINE_JUDGE
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
 
    //code here
    int t;
    cin >> t;
    string x, y;
    //sieve();
    for(int i = 1; i <= t; i++){
        // cout << "Case #" << i << ": ";
        if(i!=1){
            cin >> x;
        }
        solve();
    }
    //end
    return 0;
}