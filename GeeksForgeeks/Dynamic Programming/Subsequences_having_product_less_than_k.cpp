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
int SubseqLessThanProdK(vector<int> &arr,int k){
    int n=arr.size();
    vector<vector<int>> dp(k+1,vector<int>(n+1,0));
    for(int i=1;i<=k;i++){
        for(int j=1;j<=n;j++){
            dp[i][j]=dp[i][j-1];
            if(arr[j-1]<=i){
                dp[i][j]+=(dp[i/arr[j-1]][j-1]);
                /*We are adding 1 here because we can simply select the current element
                as it is less than k*/
                dp[i][j]+=1;
            }
        }
    }
    return dp[k][n];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,k;cin>>n>>k;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    cout<<SubseqLessThanProdK(v,k);
    #ifndef ONLINE_JUDGE
    #endif
    return 0;
}