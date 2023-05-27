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
    ll n, m;
    cin >> n;
    vil a(n + 1), b(n + 1);
    for (ll i = 0; i < n;i++)
        cin >> a[i + 1];
    unordered_map<ll, ll> mp;
    unordered_map<ll, vector<ll>> ind;
    set<ll> s, bad,good;
    for (ll i = 0; i < n;i++){
        cin >> b[i + 1];
         ind[b[i + 1]].push_back(i + 1);
         s.insert(b[i + 1]);
    }
    cin >> m;
    vil c(m + 1);
    for (ll i = 1; i <=m;i++){
        cin >> c[i];
        mp[c[i]]++;
    }
    bool same = false, flag = false;
    for (ll i = 1; i <= n;i++){
        same &= (a[i] == b[i]);
        flag |= (a[i] < b[i]);
        bad.insert(i);
    }
    if(same) {
        cout << "YES" << '\n';
        return;
    }else if(flag){
        cout << "NO" << '\n';
        return;
    }
    bool ans = true;
    for (auto it = s.begin(); it != s.end(); it++)
    {
        ll x = *it, cnt = 0;
        bool t = true;
        for (int j = 0; j < ind[x].size(); j++)
        {
            t &= (a[ind[x][j]] == b[ind[x][j]]);
            bad.erase(ind[x][j]);
        }
        if(t)
            continue;
        for (int j = 1; j < ind[x].size(); j++)
        {
            if (bad.size() > 0)
            {
                auto p = bad.lower_bound(ind[x][j - 1]);
                if (p!=bad.end() and *p < ind[x][j] and b[*p]>x)
                    cnt++;
            }
        }
        if (bad.size() > 0)
            cnt++;
        if (mp[x] < cnt) {
            ans = false;
            break;
         }
     }
    if(ans)
        cout << "YES" << '\n';
    else
        cout << "NO" << '\n';
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
    for(int i = 1; i <= t; i++){
        // cout << "Case #" << i << ": ";
        solve();
    }
    //end
    return 0;
}