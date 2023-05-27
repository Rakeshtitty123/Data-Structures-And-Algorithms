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
/*You are given a 0-indexed integer array nums. You have to partition the array into one or more contiguous subarrays.

We call a partition of the array valid if each of the obtained subarrays satisfies one of the following conditions:

The subarray consists of exactly 2 equal elements. For example, the subarray [2,2] is good.
The subarray consists of exactly 3 equal elements. For example, the subarray [4,4,4] is good.
The subarray consists of exactly 3 consecutive increasing elements, that is, the difference between adjacent elements is 1.
 For example, the subarray [3,4,5] is good, but the subarray [1,3,5] is not.
Return true if the array has at least one valid partition. Otherwise, return false*/
/*_____________________________________________Approach_________________________________________________*/
/*We store dp[i] as can we partition the array upto that point*/
/*there are 3 possibilities for the index ith element
  Case i.It can be part of two type subarray
   Case ii.It can be part of 3 type subarray
   case iii.It can be an increasing subarray part
*/
bool validPartition(vector<int> &nums){
    int n = nums.size();
    vector<bool> dp(n + 1, false);
    dp[0] = true;
    for (int i = 1; i <= n;i++){
        bool two = false, three = false, inc = false;
        if(i-2>=0)
        //checking two type sequence
            two = dp[i - 2] and (nums[i - 1] == nums[i - 2]);
        if(i-3>=0){
            //checking three type sequence
            three = dp[i - 3] and (nums[i - 1] == nums[i - 2] and nums[i - 2] == nums[i - 3]);
            //checking increasing type sequence
            inc = dp[i - 3] and (nums[i - 1] = 1 + nums[i - 2] and nums[i - 2] == 1 + nums[i - 3]);
        }
        dp[i] = two or three or inc;
    }
    return dp[n];
} 
/*Since we want only 3 elements back at each steps of dp array we can use rolling dp table for constant space complexity*/
bool validPartition(vector<int> &nums){
    int n = nums.size();
    vector<bool> dp = {true, false, nums[0] == nums[1], false};
    for (int i = 2; i < n;i++){
        bool two = nums[i] == nums[i - 1];
        bool three = (two and nums[i] == nums[i - 2]) and (nums[i] == 1 + nums[i - 1] and nums[i] == 2 + nums[i - 2]);
        dp[(i + 1) % 4] = (two and dp[(i - 1) % 4]) or (three and dp[(i - 3) % 4]);
    }
    return dp[n % 4];
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