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
/*Given an integer array nums, return the length of the longest strictly increasing subsequence.

A subsequence is a sequence that can be derived from an array by deleting some or no elements without changing
 the order of the remaining elements. For example, [3,6,2,7] is a subsequence of the array [0,3,1,6,2,2,7].*/
/*dp[i] stores the length of longest increasing subsequnce including the element*/
int longestIncreasingSubsequence(vector<int> &nums){
    int n=nums.size();
    vector<int> dp(n,1);
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(nums[i]>nums[j] and dp[i]<1+dp[j])
               dp[i]=1+dp[j];
        }
    }
    return *max_element(begin(dp),end(dp));
}
/*Solution 2: Greedy with Binary Search

Let's construct the idea from following example.
Consider the example nums = [2, 6, 8, 3, 4, 5, 1], let's try to build the increasing subsequences starting with an empty 
one: sub1 = [].
Let pick the first element, sub1 = [2].
6 is greater than previous number, sub1 = [2, 6]
8 is greater than previous number, sub1 = [2, 6, 8]
3 is less than previous number, we can't extend the subsequence sub1, but we must keep 3 because in the future 
there may have the longest subsequence start with [2, 3], sub1 = [2, 6, 8], sub2 = [2, 3].
With 4, we can't extend sub1, but we can extend sub2, so sub1 = [2, 6, 8], sub2 = [2, 3, 4].
With 5, we can't extend sub1, but we can extend sub2, so sub1 = [2, 6, 8], sub2 = [2, 3, 4, 5].
With 1, we can't extend neighter sub1 nor sub2, but we need to keep 1, so sub1 = [2, 6, 8], sub2 = [2, 3, 4, 5], sub3 = [1].
Finally, length of longest increase subsequence = len(sub2) = 4.
In the above steps, we need to keep different sub arrays (sub1, sub2..., subk) which causes poor performance.
 But we notice that we can just keep one sub array, when new number x is not greater than the last element of the subsequence sub,
  we do binary search to find the smallest element >= x in sub, and replace with number x.
Let's run that example nums = [2, 6, 8, 3, 4, 5, 1] again:
Let pick the first element, sub = [2].
6 is greater than previous number, sub = [2, 6]
8 is greater than previous number, sub = [2, 6, 8]
3 is less than previous number, so we can't extend the subsequence sub. We need to find the smallest number >= 3 in sub, it's 6.
 Then we overwrite it, now sub = [2, 3, 8].
4 is less than previous number, so we can't extend the subsequence sub. We overwrite 8 by 4, so sub = [2, 3, 4].
5 is greater than previous number, sub = [2, 3, 4, 5].
1 is less than previous number, so we can't extend the subsequence sub. We overwrite 2 by 1, so sub = [1, 3, 4, 5].
Finally, length of longest increase subsequence = len(sub) = 4.
image*/
int longestIncreasingSubsequence(vector<int> &nums){
    vector<int> sub;
    int n=nums.size();
    for(int i=0;i<n;i++){
       if(sub.empty() or sub.back()<nums[i]) sub.push_back(nums[i]);
       else{
          auto it=lower_bound(sub.begin(),sub.end(),nums[i]);
          *it=nums[i];
       }
    }
    return sub.size();
}
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int LCSof3 (string A, string B, string C, int n1, int n2, int n3);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n1, n2, n3; cin >> n1 >> n2 >> n3;
        string A, B, C; cin >> A >> B >> C;
        cout << LCSof3 (A, B, C, n1, n2, n3) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends

int solve(string &A,string &B,string &C,int i,int j,int k,vector<vector<vector<int>>> &dp){
    if(i==A.size() or j==B.size() or k==C.size()) return 0;
    if(dp[i][j][k]!=-1) return dp[i][j][k];
    if(A[i-1]==B[j-1] and B[j-1]==C[k-1])
     return dp[i][j][k]=1+solve(A,B,C,i+1,j+1,k+1,dp);
    else{
        int ch1=solve(A,B,C,i+1,j,k,dp);
        int ch2=solve(A,B,C,i,j+1,k,dp);
        int ch3=solve(A,B,C,i,j,k+1,dp);
        return dp[i][j][k]=max(ch1,max(ch2,ch3));
    }
}
int LCSof3 (string A, string B, string C, int n1, int n2, int n3)
{
   vector<vector<vector<int>>> dp(n1, vector<vector<int>>(n2, vector<int>(n3, -1)));
    return solve(A,B,C,0,0,0,dp);
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