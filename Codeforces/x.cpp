#include <bits/stdc++.h>
using namespace std;
using namespace chrono;
#define fast        ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define test        int t;cin>>t;while(t--)
#define fo(i,k,n)   for(int i=k;i<n;i++)
#define Fo(i,k,n)   for(int i=k;i>n;i--)
#define endl        "\n"
#define ll          long long
#define ld          long double
#define pb          push_back
#define eb          emplace_back
#define F           first
#define S           second
#define all(x)      x.begin(), x.end()
#define allr(x)     x.rbegin(), x.rend()
#define clr(x)      memset(x, 0, sizeof(x))
#define sortall(x)  sort(all(x))
#define Sortall(x)  sort(allr(x))
#define tr(it, a)   for(auto it = a.begin(); it != a.end(); it++)
#define low(v,n)    lower_bound(all(v), n);
#define upp(v,n)    upper_bound(all(v), n);
#define gcd(a,b)    __gcd(a,b)
#define bitcount(n) __builtin_popcountll
#define sz(x)       ((ll)(x).size())
#define PI          3.1415926535897932384626
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif
void _print(ll t) {cerr << t;}
void _print(ld t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(double t) {cerr << t;}
 
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.F); cerr << ","; _print(p.S); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
typedef pair<int, int>  pi;
typedef pair<ll, ll>    pl;
typedef vector<int>     vi;
typedef vector<double>  vd;
typedef vector<ll>      vl;
typedef vector<pi>      vpi;
typedef vector<pl>      vpl;
typedef vector<vi>      vvi;
typedef vector<vl>      vvl;
const ll mod = 998244353;
const ll inf = 1e18;
//--------------------------------------------------------------------------------------------------------------------------------
void google(int t) {cout << "Case #" << t << ": ";}
ll expo(ll x,ll y,ll m){ll r = 1; while(y){if(y % 2) r = (r*x) % m; y /= 2; x = (x*x) % m;} return r;}
void extendgcd(ll a, ll b, ll*v) {if (b == 0) {v[0] = 1; v[1] = 0; v[2] = a; return ;} extendgcd(b, a % b, v); ll x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;} //pass an arry of size1 3
ll mminv(ll a, ll b) {ll arr[3]; extendgcd(a, b, arr); return arr[0];} //for non prime b
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}//for prime b;
void precision(int a) {cout << setprecision(a) << fixed;}
 
void init_code(){ 
    fast
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        freopen("debug.txt", "w", stderr);
    #endif // ONLINE_JUDGEs
}
//------------------------------------------------------------------------------------------------------------------------------
ll n, m;
vvl ad(200005);
unordered_map<ll,ll> A, B;
ll ans = 0, lenA = 0, lenB = 0, len = 0;
void dfs(ll node, ll par){
    if(A[node]){
        ans += len-lenA;        
        lenA = len;
        if(lenA-lenB>m){
            ans += lenA-m-lenB;
            lenB = lenA-m;
        }
    }
    if(B[node]){
        ans += len-lenB;
        lenB = len;
        if(lenB-lenA>m){
            ans += lenB-m-lenA;
            lenA = lenB-m;
        }
    }
    for(auto child:ad[node]){
        if(child!=par){
            len++;
            dfs(child, node);
            len--;      
            if(lenA>len){
                ans += lenA - len;
                lenA = len;
            }
            if(lenB>len){
                ans += lenB - len;
                lenB = len;
            }      
        }
    }
}
 
void solve(){  
    cin>>n>>m;
    fo(i,0,n-1){
        ll x, y; cin>>x>>y;
        ad[x].pb(y);
        ad[y].pb(x);
    }   
    ll x; cin>>x;
    fo(i,0,x){ll t; cin>>t; A[t]++;}
    ll y; cin>>y;
    fo(i,0,y){ll t; cin>>t; B[t]++;}
    dfs(1,-1);
    cout<<ans<<endl;
}
 

int main(){  
    init_code();
    auto start1 = high_resolution_clock::now();
    // test{
        solve();
    // }
    auto stop1 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop1 - start1);
    #ifndef ONLINE_JUDGE
        cerr << "Time: " << duration . count() / 1000 << endl;
    #endif
    
    return 0;
}