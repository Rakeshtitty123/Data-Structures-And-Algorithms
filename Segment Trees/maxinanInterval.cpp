#include <bits/stdc++.h>
using namespace std;
using namespace chrono;
#define fast        ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define test        ll t;cin>>t;while(t--)
#define fo(i,k,n)   for(ll i=k;i<n;i++)
#define Fo(i,k,n)   for(ll i=k;i>n;i--)
#define endl        "\n"
#define ll          long long
#define ld          long double
#define pb          push_back
#define eb          emplace_back
#define mp          make_pair
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
#define bitcount(n) __builtin_popcountll(n)
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
typedef vector<ll>      vil;
typedef vector<pi>      vpi;
typedef vector<pl>      vpl;
typedef vector<vi>      vvi;
typedef vector<vil>      viil;
typedef vector<bool> vb;
const ll mod = 1e9+7;
const ll inf = 2e18-1;
//--------------------------------------------------------------------------------------------------------------------------------
void google(int t) {cout << "Case #" << t << ": ";}
ll expo(ll x,ll y,ll m){ll r = 1; while(y){if(y % 2) r = (r*x) % m; y /= 2; x = (x*x) % m;} return r;}
void extendgcd(ll a, ll b, ll*v) {if (b == 0) {v[0] = 1; v[1] = 0; v[2] = a; return ;} extendgcd(b, a % b, v); ll x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;} //pass an arry of size1 3
ll mminv(ll a, ll b) {ll arr[3]; extendgcd(a, b, arr); return arr[0];} //for non prime b
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}//for prime b;
void precision(int a) {cout << setprecision(a) << fixed;}
 
void init_code(){     
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        freopen("debug.txt", "w", stderr);
    #endif // ONLINE_JUDGEs
}
void build_Tree(ll ind,ll start,ll end,vil &v,vil &segTree){
      if(start==end){
          segTree[ind] = v[start];
          return;
      }
      ll left = ind * 2, right = ind * 2 + 1, mid = (start+end) / 2;
      build_Tree(left, start, mid,v,segTree);
      build_Tree(right, mid + 1, end,v,segTree);
      segTree[ind] = max(segTree[left], segTree[right]);
      return;
}
/*start and represents the node which contains max value[start,end]
 left and right represents the given query range.*/
ll query(ll node,ll start,ll end,ll left,ll right,vil &segTree){
    /*if cur node range goes out of bouds*/
     if(end<left or right<start)
          return INT_MIN;
    /*if the cur node in the range and it has got only one value.*/
     if(start==end)
          return segTree[node];
    /*if the cur node range value lies within the range of [left,right]*/
    if(left<=start and end<=right)
          return segTree[node];
    /*if all above cases fail and cur node has extra range than required range
     the we go to children and get the value.*/
    ll leftNode = node * 2, rightNode = node * 2 + 1, mid = (start + end) / 2;
    ll leftVal = query(leftNode, start, mid,left,right,segTree);
    ll rightVal = query(rightNode, mid + 1, end, left, right, segTree);
    return max(leftVal, rightVal);
}
// Do a dry run for nodes when they are not in the power of  2
// seg trees work on start and end only so if we dry run algo some nodes
// don;t go till depth and it will be returned in the middle of the node only
// as start==end 
//the star
void update_Query(ll node,ll start, ll end, ll pos, ll val, vil &v,vil &segTree){
    if(start==end){
          v[start] = val;
          segTree[node] = val;
          return;
    }
    ll mid = (start + end) / 2;
    if(start<=pos and pos<=mid)
          update_Query(node * 2, start, mid, pos, val, v, segTree);
    else
          update_Query(node * 2 + 1, mid + 1, end, pos, val, v, segTree);
    segTree[node] = max(segTree[2 * node], segTree[2 * node + 1]);
    return;
} 
void solve(){
    ll n;
    cin >> n;
    vil v(n);
    for (ll i = 0; i < n; i++)
          cin >> v[i];
    vil dp(100005, 0);
    dp[1] = 1;
    dp[100] = 2;
    dp[500] = 3;
    dp[10000] = 4;
    vil segTree(4 * 100005 + 1,0);
    /*Here we have made a size of 4*n beacuse although we need 2*n nodes
    for n if is an exact power of 2
    in other case although we don;t need 4*n nodes but to adjust the
    indexing that we need atleast 4*n nodes. */
    build_Tree(1, 0, n - 1, dp, segTree);
    cout<<query(1,0,)
}
int main(){
    init_code();
    auto start1 = high_resolution_clock::now();
    fast int t;
    //cin >> t;
   t = 1;
    for (int i = 1; i <= t; i++){
         solve();
    }
            auto stop1 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop1 - start1);
    #ifndef ONLINE_JUDGE
        cerr << "Time: " << duration . count() / 1000 << endl;
    #endif
    return 0;
}