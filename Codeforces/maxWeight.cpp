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
typedef pair<ll, pl> ppl;
typedef pair<ll, ppl> pppl;
typedef vector<pppl> vpppl;
typedef vector<pair<ll, pair<ll, ll>>> vppl;
typedef vector<int>     vi;
typedef vector<double>  vd;
typedef vector<ll>      vil;
typedef vector<pi>      vpi;
typedef vector<pl>      vpl;
typedef vector<vpi> vvpi;
typedef vector<vector<pl>> vvpl;
typedef vector<vi>      vvi;
typedef vector<vil>      viil;
typedef vector<viil> viiil;
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
    //
}
ll LCA[200005][35];
ll maxW[200005][35];
unordered_map<ll, unordered_map<ll, ll>> graph;
unordered_map<ll, unordered_map<ll, ll>> minSpan;
vil height;
void dfs(ll node,ll par,viil &curG,ll curh){
        height[node] = curh;
        LCA[node][0]=par;
        if(par!=-1) maxW[node][0] = graph[par][node];
        for(auto &x:curG[node]){
             if(x!=par)
                 dfs(x, node, curG, curh + 1);
        }
}
void init(ll n,viil &curG){
        height.resize(n + 1);
        ll maxn = log2(n);
        for (int i = 0; i <= n; i++)
             for (int j = 0; j <= maxn; j++)
                 LCA[i][j] = -1, maxW[i][j] = -1;
        dfs(1, -1, curG, 0);
       // debug(height);
        for (int j = 1; j <= maxn; j++){
             for (int i = 1; i <= n; i++)
             {
                 if (LCA[i][j - 1] != -1)
                 {
                     int par = LCA[i][j - 1];
                     LCA[i][j] = LCA[par][j - 1];
                 }
            }
        }
        for (ll j = 1; j <= maxn;j++){
            for (ll i = 1; i <= n;i++){
                 ll anc = LCA[i][j - 1];
                 if(LCA[i][j]!=-1) maxW[i][j] = max(maxW[i][j - 1], maxW[anc][j - 1]);
            }
        }
}
ll getMaxWeight(int a,int b,int n)
{
    if(height[a]>height[b]) swap(a,b);
    ll d=height[b]-height[a];
    ll maxn=log2(n);
    ll maxQ = -1;
    while(d){
          ll maxd=log2(d);
           maxQ =max(maxQ, maxW[b][maxd]);
          b=LCA[b][maxd];
          d-=(1<<maxd);
    }
    if(a==b) return maxQ;
    for(int i=maxn;i>=0;i--)
    {
        if(LCA[a][i]!=-1 and (LCA[a][i]!=LCA[b][i]))
                maxQ = max(maxQ, max(maxW[a][i], maxW[b][i])), a = LCA[a][i], b = LCA[b][i];
        
    }
    return max(maxQ,max(maxW[a][0],maxW[b][0]));
}
void minSpanningTree(ll src,ll n,vpl &edges){
        priority_queue<ppl, vppl, greater<ppl>> pq;
        pq.push({0, {src,-1}});
        vpl minEdge;
        ll weight = 0;
        vb vis(n + 1,false);
        vil parent(n + 1, -1);
        while(pq.size()>0){
            auto x = pq.top();
            pq.pop();
            ll w = x.first, node = x.second.first, par = x.second.second;
            if(vis[node])
                continue;
            minEdge.push_back({node, par});
            parent[node] = par;
            weight += w;
            vis[node] = true;
            for(auto &v:graph[node]){
                if(vis[v.first]==false){
                    pq.push({v.second, {v.first, node}});
                }
            }
        }
        //debug(parent);
        viil curG(n+1);
        for (ll i = 1; i <= n;i++){
            if(parent[i]!=-1){
                curG[i].push_back(parent[i]);
                curG[parent[i]].push_back(i);
            }
        }
       // debug(curG);
         init(n, curG);
         for (ll i = 0; i < minEdge.size();i++){
            ll u = minEdge[i].first, v = minEdge[i].second;
            minSpan[u][v] = weight;
            minSpan[v][u] = weight;
         }
         for (ll i = 0; i < edges.size();i++){
            ll u = edges[i].first, v = edges[i].second;
           
            if(minSpan[u][v]==-1){
                 //cout << u<<' ' << v << ' ';
                ll w = getMaxWeight(u, v, n);
             //   cout << w << '\n';
                ll curW = weight - w + graph[u][v];
                minSpan[u][v] = curW;
                minSpan[v][u] = curW;
            }
         }
}
void solve(){
        ll n, m;
        cin >> n >> m;
        vpl edges;
        for (ll i = 1; i <= m;i++){
            ll u, v, w;
            cin >> u >> v >> w;
            graph[u][v] = w;
            graph[v][u] = w;
            minSpan[u][v] = -1;
            minSpan[v][u] = -1;
            edges.push_back({u, v});
        }
        minSpanningTree(1, n,edges);
        for (ll i = 0; i < edges.size();i++){
            ll u = edges[i].first, v = edges[i].second;
            cout << minSpan[u][v] << '\n';
        }
}
int main(){
    init_code();
    auto start1 = high_resolution_clock::now();
    fast int t;
   // cin >> t;
     t = 1;
        for (int i = 1; i <= t; i++){
          // string s;
           //cin >> s;
          // getline(cin, s);
            solve();
        }
    auto stop1 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop1 - start1);
    #ifndef ONLINE_JUDGE
        cerr << "Time: " << duration . count() / 1000 << endl;
    #endif
    return 0;
}