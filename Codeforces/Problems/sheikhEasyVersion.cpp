#include<bits/stdC++.h>
using namespace std;
#define ll long long int
#define vi vector<int>
#define vil vector<ll>
#define vc vector<char>
#define vb vector<bool>
#define vf vector<float>
#define vul vector<ull>
#define vvi vector<vector<int>>
#define fl(i,n) for(int i=0;i<n;i++);
#define pb push_back
#define vii vector<vector<int>>
#define sti stack<int>
#define stc stack<char>
#define spii stack<pair<int,int>>
#define spic stack<pair<int,char>>
#define spcc stack<pair<char,char>>
#define uint_64t unsigned ll
#define int_64t  ll
#define ull unsigned long long int
#define ld long double
#define P2(n) n, n ^ 1, n ^ 1, n
#define P4(n) P2(n),P2(n^1),P2(n^1),P2
#define P6(n) P4(n),P4(n^1),P4(n^1),P4
#define Look_Up P6(0),P6(1),P6(0),P6(1)
#define phi 1.6180339887498948
#define N 6
#define Maxx 10000
ll mod = 998244353;
/*https://codeforces.com/contest/1732/problem/C1*/
/*f(l,r)<=f(l,r+1)
 if we make sum-xor array it will always be monotonically increasing..
 so we can binary search over it.*/
bool check(int mid,vil &prefSum,vil &xorSum,ll res,ll &left,ll &right){
    int n = prefSum.size();
    for (ll i = 0; i <=n-mid;i++){
        ll rend = i + mid-1;
        ll sum = prefSum[rend] - (i>0? prefSum[i-1] : 0);
        ll xorval = xorSum[rend] ^ (i > 0 ? xorSum[i-1] : 0);
        if(res==(sum-xorval)){
            left = i+1;
            right = rend+1;
            return true;
        }

    }
    return false;
}
void solve(){
    ll n,q;
    cin >> n>>q;
    vil v(n);
    for (int i = 0; i < n;i++)
        cin >> v[i];
    ll L, R;
    cin>> L >> R;
    vil prefSum(n), xorSum(n);
    ll sum = 0, totalxor = 0;
    for (int i = 0; i < n;i++){
        sum += v[i];
        totalxor ^= v[i];
        prefSum[i] = sum;
        xorSum[i] = totalxor;
    }
    ll res = sum - totalxor;
    int low = L, high = R;
    ll left = L, right = R;
    while(low<=high){
        ll mid = (low + high) / 2;
        if(check(mid,prefSum,xorSum,res,left,right)){
            high = mid - 1;
        }else
            low = mid + 1;
    }
    cout << left << " " << right << '\n';
    return;
}
int main()
{
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        int t;
        cin >> t;
        while(t--){
        solve();
        }
        return 0;
 }