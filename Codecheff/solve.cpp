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
void solve(){
    int n;
    cin >> n;
    vi a(n), b(n + 2);
    for (int i = 0; i < n;i++)
        cin >> a[i];
    if(n==1)
        cout << "YES" << '\n';
    else{
        b[0] = a[0];
        b[n + 1] = a[n - 1];
        for (int i = 0; i < n-1;i++)
            b[i + 1] = (a[i] * a[i + 1]) / __gcd(a[i], a[i + 1]);
    }
    bool flag = true;
    for (int i = 0; i < b.size()-1;i++){
        if(__gcd(b[i],b[i+1])!=a[i]){
            flag = false;
            break;
        }
    }
   if(flag)
       cout << "YES" << '\n';
   else
       cout << "NO" << '\n';
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
    #ifndef ONLINE_JUDGE
    #endif
    return 0;
}