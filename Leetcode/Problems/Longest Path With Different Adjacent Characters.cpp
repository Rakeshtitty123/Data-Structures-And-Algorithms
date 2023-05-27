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
int ans=-1;
/*https://leetcode.com/problems/longest-path-with-different-adjacent-characters/*/
int dfs(int i,string &s,vector<vector<int>> &graph){
        int max1=1,max2=0,cnt=0;
        for(auto &x:graph[i]){
            if(s[i]!=s[x]) {
                int val=1+dfs(x,s,graph);
                if(val>max1){
                   max2=max1;
                    max1=val;
                }else if(val>max2) max2=val;
            
                ++cnt;
            }
            else ans=max(ans,dfs(x,s,graph));
        }
        if(cnt>=0) ans=max(ans,max1+max2-1);
        return max1;
        
    }
int longestPath(vector<int>& parent, string s) {
        int n=s.size();
        vector<vector<int>> graph(n);
        for(int i=1;i<parent.size();i++) graph[parent[i]].push_back(i);
        int val=dfs(0,s,graph);
        return max(ans,val);
}
int main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(NULL);
      cout.tie(NULL);
      return 0;
}