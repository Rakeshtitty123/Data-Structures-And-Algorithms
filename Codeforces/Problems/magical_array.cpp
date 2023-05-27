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
    /*https://codeforces.com/problemset/problem/1704/D*/
/*As the indices sum always constant try to form equations using indices  i.e,,,i*a[i]+j*a[j]..*/
void solve(){
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> v(n, vector<ll>(m, 0));
    for (ll i = 0; i < n;i++){
        for (ll j = 0; j < m;j++){
            cin >> v[i][j];
        }
    }
    unordered_map<ll, vector<ll>> mp;
    for (ll i = 0; i < n;i++){
        ll sum = 0;
        for (ll j = 0; j < m;j++){
            sum += (v[i][j] * j);
        }
        if(mp[sum].size()<2)
            mp[sum].push_back(i);
    }
    ll valind = 0, val = 0, second = 0;
    for(auto it:mp){
        if(it.second.size()==1){
            valind = it.second[0];
            val = it.first;
        }
        if(it.second.size()>1){
            second = it.first;
        }
    }
    ll sum = 0;
    for (ll j = 0; j < m;j++){
    
    }
    cout << valind+1 << ' ' << (val - second) << '\n';
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
    //sieve();
    for(int i = 1; i <= t; i++){
        // cout << "Case #" << i << ": ";
        solve();
    }
    //end
    return 0;
}