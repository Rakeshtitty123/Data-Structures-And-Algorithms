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
/*nCr caluclation*/
/*nCr recursive formula (n-1)C(r-1)+(n-1)Cr*/
/* C(n, k) = C(n-1, k-1) + C(n-1, k)
   C(n, 0) = C(n, n) = 1*/
int nCr(int n,int r){
    long long mod=1e9+7;
    vector<vector<long long>> dp(n+1,vector<long long>(r+1,0));
    for(int i=1;i<=n;i++){
        for(int j=0;j<=r;j++){
            if(j>i) dp[i][j]=0;
            else if(j==0 or i==j) dp[i][j]=1;
            else dp[i][j]=(dp[i-1][j]%mod+dp[i-1][j-1]%mod)%mod;
        }
    }
    return dp[n][r];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    #endif
    return 0;
}