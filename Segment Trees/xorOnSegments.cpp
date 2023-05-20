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
class Pair{
    public:
        ll sum;
        vi count1;
        Pair(){
            sum = 0;
            count1 = vector<int>(20, 0);
     }
        Pair(ll sum){
            this->sum = sum;
            count1 = vector<int>(20, 0);
            for (int i = 0; i < maxBits;i++){
                int mask = (1 << i);
                if(mask&sum)
                    count1[i]++;
        }
     }
    Pair(Pair l,Pair r){
        this->sum = l.sum + r.sum;
        for (int i = 0; i < maxBits;i++){
            this->count1[i] = l.count1[i] + r.count1[i];
        }
   }
};
vector<Pair> segTree;
int maxBits = 20;
void build(ll node,ll start,ll end,vi &arr){
    if(end<start)
            return;
    else if(start==end){
        ll val = arr[start];
        Pair dummy =Pair(val);
        segTree[node] = dummy;
        return;
    }
    ll mid = (start + end) / 2;
    build(node * 2, start, mid, arr);
    build(node * 2 + 1, mid + 1, end, arr);
    segTree[node] = Pair(segTree[node * 2], segTree[node * 2 + 1]);
    return;
}
void propagate(ll node,ll start,ll end){
    
}
ll query(ll node,ll start,ll end,ll left,ll right){
    if(end<left or right<start)
        return 0;
    if(start==end)
        return segTree[node].sum;
    else if(left<=start and end<=right)
        return segTree[node].sum;
    else{
        ll mid = (start + end) / 2;
        ll lValue = query(node * 2, start, mid, left, right);
        ll rValue = query(node * 2 + 1, mid + 1, end, left, right);
        return lValue + rValue;
    }
}
void solve(){
    ll n, q;
    cin >> n >> q;
    vi arr(n, 0);
    for (int i = 0; i < n;i++)
        cin >> arr[i];
    while(q--){
        int qtype, left, right;
        cin >> qtype >> left >> right;
    }
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