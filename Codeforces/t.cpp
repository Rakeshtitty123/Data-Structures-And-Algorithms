  #include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < n; ++i)
#define isodd &1 != 0
#define ll long long
#define int long long
#define ld long double
#define mp make_pair
#define llrp(x, y) ((ll)round(exp(x, y)))
#define all(v) v.begin(), v.end()
#define back(v) v.rbegin(), v.rend()
#define IOS                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)
#define pb push_back

using namespace std;

const int N = 300005;
vector<int> lp(N+1);
vector<int> pr;
map<ll,set<ll>> m;
bool used[N]={false};
bool visited[N];
ll d[N]={-1};
ll p[N];

void sieve(){
for (int i=2; i <= N; ++i) {
    if (lp[i] == 0) {
        lp[i] = i;
        pr.push_back(i);
    }
    for (int j = 0; i * pr[j] <= N; ++j) {
        lp[i * pr[j]] = pr[j];
        if (pr[j] == lp[i]) {
            break;
        }
    }
}}

   void solve(){  
    ll a, b, c, d; cin>>a>>b>>c>>d;
    ll t = a+b+c+d;
    if(a==0){
        cout<<1<<endl;
        return;
    }
    ll ans = a;
    if(b<c)swap(b,c);
    ans += 2*c;
    b -= c;
    c = 0;
    ans += min(a, max(b, d));
    cout << ans << '\n';
}


signed main()
{
    IOS;
    sieve();
    // cout<<fixed<<setprecision(10);
    ll t = 1;
    // cin>>t;
    while (t--)
        solve();
    return 0;
}
