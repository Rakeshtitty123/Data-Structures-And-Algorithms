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
vector<bool> st;
vector<int> vis;
int cycle_Len = 0;
void dfs(int node,int dist,vector<int> &edges){
    if(vis[node]!=-1){
        if(st[node])
            cycle_Len = dist - vis[node];
        return;
    }
    vis[node] = dist;
    st[node] = true;
    if(edges[node]!=-1)
        dfs(edges[node], dist + 1, edges);
    st[node] = false;
}
/*We can build on the previous problem (2359. Find Closest Node to Given Two Nodes).

We run DFS from a node, memoising the distance to each node we reach.

If we encounter a node with distance, we find a cycle. 
The length of that cycle is the current distance minus the distance to that node.

We also need to track whether we reached the node during the current DFS cycle. 
For that, we track the starting node (i) when we encountered the node for the first time.*/
int longestCycle(vector<int> &edges){
    int n = edges.size();
    vis.resize(n, -1), st.resize(n, -1);
    int res = -1;
    for (int i = 0; i < n;i++){
        if(vis[i]==-1){
            dfs(i, 0, edges);
            res = max(res, cycle_Len);
        }
    }
    return res;
}
int main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(NULL);
      cout.tie(NULL);
      return 0;
}