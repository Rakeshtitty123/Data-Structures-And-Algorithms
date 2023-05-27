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
/*Given a fence with n posts and k colors, find out the number of ways of painting the fence so that not more than two
 consecutive fences have the same colors. Since the answer can be large return it modulo 10^9 + 7.*/
 /*
 Let us try to build the dp table for the test case n=4 k=4

            0          1         2           3
            
       1    1          1         1           1

       2    4          4         4           4

       3    15         15         15         15

       4   57         57          57         57


Let us analyse how we build the dp table 
dp[i][j]=states that no.of valid ways of fencing i length fence with atlast color j
Here above 0 1 2 3 represent different types of k colors...................
Base case if(n==1) dp[i][0]=1...dp[0][3]=1

Base case if(n==2) dp[1][0]=k==4.............dp[1][3]==k==4

For n=3 dp[3][0]=
 We know that we have to color last fence as 0...so we can take all the ways where the n-1 is not fenced 0
==> dp[i]+=(dp[i-1][1]+dp[i-2][2]..........dp[i-1][j])
Since we are allowed to color at most two same colors on same side......
Therfore cur i-2 must be nonzero color such that we can now color with 0
Therfore we want all colors such that dp[i-2][j] where j!=0...it it the sum of all rows without zero
dp[i-2][1]=1,dp[i-2][2]=1,dp[i-2][3]=1,
total dp[3][0]======(dp[i-1][1]+dp[i-2][2]..........dp[i-1][j])+(dp[i-2][j]..............such that j!=0)
If we try to simplify in terms of i and j

dp[i][j]=(dp[i-1][p]+dp[i-2][p+1]..............dp[i-2][k]...such that p!=j)+(dp[i-2][q]..............dp[i-2][k] such that q!=j);


Space optimisation:
Note that for ech row same value is getting filled as based on color it doesn't depend...

If we try to simpily'
 dp[i]=k*((k-1)*(dp[i-1]/k)+(k-1)*(dp[i-2]/k))
 dp[i]=(k-1)*(dp[i-1]+dp[i-2])';

 */
 long long countWays(int n, int k){
        vector<long long> dp(n+1,0);
        long long mod=1e9+7;
        dp[1]=k;dp[2]=k*k;
        for(int i=3;i<=n;i++){
            dp[i]=((k-1)*((dp[i-1]+dp[i-2])%mod))%mod;
        }
        return dp[n];
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