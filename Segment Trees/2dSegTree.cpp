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
// size of 2d seg matrix will be 16*n*m(4n*4m) where n=no.of rows and m=no.of cols;
//considered 1 based indexing(not necessary)
viil segTree;
void buildy(ll nodex,ll nodey,ll startx,ll endx,ll starty,ll endy,viil &grid){
     if(starty==endy){
         if(startx==endx) segTree[nodex][nodey] = grid[startx][starty];//when we are dealing with leaf nodes
         else
             segTree[nodex][nodey] = segTree[nodex * 2][nodey] + segTree[nodex * 2 + 1][nodey];//case for updating non leaf nodes i.e,when two arrays
                                                                                                //are getting merged.
     }else{
         ll midy = (starty + endy) / 2;
         buildy(nodex, nodey * 2, startx,endx,starty, midy,grid);
         buildy(nodex, nodey*2+1, startx,endx,midy + 1, endy,grid);
         if(startx==endx)segTree[nodex][nodey] = segTree[nodex][nodey * 2] + segTree[nodex][nodey * 2 + 1];
         else segTree[nodex][nodey] = segTree[nodex*2][nodey] + segTree[nodex*2+1][nodey];
         
     }
}
void buildx(ll nodex,ll startx,ll endx,viil &grid){
     if(startx==endx){
         buildy(nodex, 1, startx, endx, 1, grid[0].size()-1, grid);
     }else{
         ll midx = (startx + endx) / 2;
         buildx(nodex * 2, startx, midx,grid);
         buildx(nodex * 2 + 1, midx + 1, endx,grid);
         buildy(nodex, 1, startx, endx, 1, grid[0].size()-1, grid);
     }
}
void updatey(ll nodex,ll startx,ll endx,ll nodey,ll starty,ll endy,ll row,ll col,ll val,viil &grid){
      if(starty==endy){
          if(startx==endx)
             segTree[nodex][nodey] = val;
          else
             segTree[nodex][nodey] = segTree[nodex * 2][nodey] + segTree[nodex * 2 + 1][nodey];
      }else{
          ll midy = (starty + endy) / 2;
           if(col>=starty and col<=midy){
             updatey(nodex, startx, endx, nodey * 2, starty, midy, row, col, val, grid);
           }else{
               updatey(nodex, startx, endx, nodey * 2+1, starty, midy, row, col, val, grid);
           }
           if(startx==endx)segTree[nodex][nodey] = segTree[nodex][nodey * 2] + segTree[nodex][nodey * 2 + 1];
           else segTree[nodex][nodey] = segTree[nodex*2][nodey ] + segTree[nodex*2+1][nodey];
      }
}
void updatex(ll nodex,ll startx,ll endx,ll row,ll col,ll value,viil &grid){
        if(startx==endx){
           updatey(nodex, startx, endx,1, 1,grid[0].size()-1, row, col, value, grid);
        }else{
             ll midx = (startx + endx) / 2;
             if(row>=startx and row<=midx)
               updatex(nodex * 2, startx, midx, row, col, value, grid);
             else
               updatex(nodex * 2 + 1, midx + 1, endx, row, col, value, grid);
             updatey(nodex, startx, endx, 1, 1, grid[0].size() - 1, row, col,value, grid);
        }
}
ll queryCol(ll nodex,ll startx,ll endx,ll row1,ll col1,ll row2,ll col2,ll nodey,ll starty,ll endy,viil &grid){
    if(endy<col1 or col2<starty)
             return 0;
    else if(starty==endy)
             return segTree[nodex][nodey];
    else if(col1<=starty and endy<=col2)
             return segTree[nodex][nodey];
    else{
             ll midy = (starty + endy) / 2;
             ll lValue = queryCol(nodex, startx, endx, row1, col1, row2, col2, nodey * 2, starty, midy,grid);
             ll rValue = queryCol(nodex, startx, endx, row1, col1, row2, col2, nodey * 2 + 1, midy + 1, endy, grid);
             return lValue + rValue;
    }
}
ll queryRow(ll nodex,ll startx,ll endx,ll row1,ll col1,ll row2,ll col2,viil &grid){
    if(row2<startx or endx<row1)
             return 0;
    if(startx==endx){
             return queryCol(nodex, startx, endx, row1, col1, row2, col2, 1, 1, grid[0].size()-1, grid);
    }else if(row1<=startx and row2<=endx){
             return queryCol(nodex, startx, endx, row1, col1, row2, col2,1,1,grid[0].size()-1,grid);
    }else{
             ll midx = (startx + endx) / 2;
             ll lValue = queryRow(nodex * 2, startx, midx, row1, col1, row2, col2, grid);
             ll rValue = queryRow(nodex * 2 + 1, midx + 1, endx, row1, col1, row2, col2, grid);
             return lValue + rValue;
    }
}
void solve(){
     ll n, m;
     cin >> n >> m;
     viil grid(n + 1, vil(m + 1, 0));
     for (ll i = 1; i <= n;i++){
         for (ll j = 1; j <= m;j++){
             cin >> grid[i][j];
         }
     }
     segTree.resize(4 * (n + 1), vil(4 * (m + 1)));
     buildx(1, 1, grid.size() - 1, grid);
     debug(grid);
     debug(segTree);
     cout<<queryRow(1, 1, grid.size() - 1, 2, 2, grid.size() - 1, grid[0].size() - 1, grid)<<'\n';
     updatex(1, 1, grid.size() - 1, 2, 2, 10, grid);
     cout<<queryRow(1, 1, grid.size() - 1, 2, 2, grid.size() - 1, grid[0].size() - 1, grid)<<'\n';
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