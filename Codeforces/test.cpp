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
typedef vector<vector<int>> vvi;
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
unordered_map<int, unordered_map<int, int>> edgeMap;
set<string> paths;
string buildDist(int src,vi &dist,vvpi &parent,vpi &edges,vvi &graph){
        queue<ppl> q;
        q.push({0,{src,-1}});
        while(q.size()>0){
            auto x = q.front();
            q.pop();
            ll d= x.first, node = x.second.first,par=x.second.second;
            if(dist[node]>0)
                continue;
            dist[node] = d;
            parent[node] .push_back({par,edgeMap[par][node]});
            if(par!=-1){
                edgeMap[node][par] *= -1;
                edgeMap[par][node] *= -1;
            }
            for(auto &v:graph[node]){
                if(dist[v]<0){
                    q.push({d + 1, {v, node}});
                }
            }
        }
      //  debug(dist);
        //debug(parent);
        string s;
        for (int i = 0; i < edges.size();i++){
            int u = edges[i].first, v = edges[i].second;
            if(edgeMap[u][v]<0)
                s += '1';
            else
                 s +='0';
        }
        debug(s);
        return s;
}
void addWays(ll i,ll j,ll maxsz){
        ll sz = paths.size();
        for (auto s:paths){
           //  cout << s[i] << ' ' << s[j] << '\n';
            if(s[i]=='1' and s[j]=='0'){
                 s[i] = '0';
                 s[j] = '1';
                 paths.insert(s);
                 s[i] = '1';
                 s[j] = '0';
            }
            if(s[i]=='0' and s[j]=='1'){
                s[i] = '1';
                 s[j] = '0';
                 paths.insert(s);
                 s[i] = '0';
                 s[j] = '1';
            }
        }
}
void solve(){
        int n, m, k;
        cin >> n >> m >> k;
        vvi graph(n + 1);
        vpi edges;
        for (ll i = 1; i <= m;i++){
            ll u, v;
            cin >> u >> v;
            edges.push_back({u, v});
            edgeMap[u][v] = i ;
            edgeMap[v][u] = i;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
       // cout << k;
        vi dist(n + 1, -1), parent(n + 1, -1);
        vvpi newPar(n + 1);
        debug(newPar);
        paths.insert(buildDist(1, dist, newPar, edges, graph));
        
        for (ll i = 0; i < m;i++){
            ll u = edges[i].first, v=edges[i].second;
            if(paths.size()==k)
                break;
            if(edgeMap[u][v]>0){
                
                if(dist[u]+1==dist[v]){
                  //  cout << u << ' ' << v << '\n';
                    for (ll p = 0; p < newPar[v].size(); p++){
                      ll i = newPar[v][p].second;
                       ll j = abs(edgeMap[u][v]);
                       //cout << i << ' ' << j << '\n';
                       if(i-1!=-1 and j-1!=-1) addWays(i-1, j-1, k);
        
                      if(paths.size()==k)
                        break;
                    }
                    if(paths.size()==k)
                      break;
                    newPar[v].push_back({u,newPar[v][0].second});
                    // for(auto &x:graph[v]){
                    //     ll i = abs(edgeMap[parent[x]][x]);
                    //     ll j = abs(edgeMap[u][v]);
                    //     addWays(i - 1, j - 1, k);
                    //     if(paths.size()==k)
                    //         break;
                    // }
                   
                }
                 if(dist[v]+1==dist[u]){
                    //cout << u << ' ' << v << '\n';
                    for (ll p= 0; p< newPar[u].size();p++){
                      ll i = newPar[u][p].second;
                      ll j = abs(edgeMap[u][v]);
                      if (i - 1 != -1 and j - 1 != -1)
                        addWays(i - 1, j - 1, k);
                      if(paths.size()==k)
                        break;
                    }
                    newPar[u].push_back({v,newPar[u][0].second});
                    // for(auto &x:graph[u]){
                    //     if(dist[x])
                    //     ll i = abs(edgeMap[parent[x]][x]);
                    //     ll j = abs(edgeMap[u][v]);
                    //     addWays(i - 1, j - 1, k);
                    //     if(paths.size()==k)
                    //         break;
                    // }
                    if(paths.size()==k)
                      break;
                }
                //cout << paths.size() << '\n';
            }
        }
       cout << paths.size() << '\n';
        for (auto s:paths)
            cout <<s << '\n';
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
