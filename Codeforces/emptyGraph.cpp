#include<bits/stdC++.h>
using namespace std;
#define ll long long int
#define vi vector<int>
#define vil vector<ll>
#define vc vector<char>
#define vf vector<float>
#define vul vector<ull>
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
#define P4(n) P2(n),P2(n^1),P2(n^1),P2(n)
#define P6(n) P4(n),P4(n^1),P4(n^1),P4(n)
#define Look_Up P6(0),P6(1),P6(0),P6(1)
#define phi 1.6180339887498948
#define N 6
#define Maxx 10000
/*An array of n positive integers a1,a2,…,an fell down on you from the skies,
 along with a positive integer k≤n.

You can apply the following operation at most k times:

Choose an index 1≤i≤n and an integer 1≤x≤109. Then do ai:=x (assign x to ai).
Then build a complete undirected weighted graph with n vertices numbered with integers
 from 1 to n, where edge (l,r) (1≤l<r≤n) has weight min(al,al+1,…,ar).

You have to find the maximum possible diameter of the resulting graph after performing
 at most k operations.

The diameter of a graph is equal to max1≤u<v≤nd(u,v), where d(u,v) is the length of 
the shortest path between vertex u and vertex v.*/
bool validate(vil v,ll k,ll mid){
    for (ll i = 0; i < v.size();i++){
        if(v[i]*2<mid){
            if(k>0)
                k--;
            else
                return false;
            v[i] = 1e9;
        }
    }
    if(k==0){
        for (ll i = 1; i < v.size();i++){
            if(min(v[i],v[i-1])>=mid)
                return true;
        }
        return false;
    }else if(k==1)
        return *max_element(begin(v), end(v)) >= mid;
    return true;
}
void solve(){
    ll n, k;
    cin >> n >> k;
    vil v(n);
    for (ll i = 0; i < n;i++)
        cin >> v[i];
    ll low = 1, high = 1e9, ans = 0;
    while(low<=high){
        ll mid = (low+high) / 2;
        if(validate(v,k,mid)){
            ans = mid;
            low = mid + 1;
        }else
            high = mid - 1;
    }
    cout << ans << '\n';
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