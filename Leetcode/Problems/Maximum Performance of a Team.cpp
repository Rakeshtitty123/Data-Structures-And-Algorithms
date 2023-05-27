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
/*You are given two integers n and k and two integer arrays speed and efficiency both of length n. 
There are n engineers numbered from 1 to n. speed[i] and efficiency[i] represent the speed and efficiency of the ith engineer 
respectively.

Choose at most k different engineers out of the n engineers to form a team with the maximum performance.

The performance of a team is the sum of their engineers' speeds multiplied by the minimum efficiency 
among their engineers.

Return the maximum performance of this team. Since the answer can be a huge number,
 return it modulo 109 + 7.*/
int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<vector<ll>> res;
        ll mod=1e9+7;
        priority_queue<ll,vector<ll>,greater<ll>> pq;
        for(int i=0;i<n;i++) res.push_back({efficiency[i],speed[i]});
        sort(begin(res),end(res));
        ll sum=0,maxP=0;
        for(int i=n-1;i>=0;i--){
            pq.push(res[i][1]);
            sum+=res[i][1];
            if(pq.size()>k){
                sum-=pq.top();
                pq.pop();
            }
            maxP=max(maxP,(sum*res[i][0]));
        }
        return maxP%mod;
}
int main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(NULL);
      cout.tie(NULL);
      return 0;
}