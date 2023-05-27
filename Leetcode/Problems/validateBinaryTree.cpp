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
/*You have n binary tree nodes numbered from 0 to n - 1 where node i has two children 
leftChild[i] and rightChild[i], return true if and only if all the given nodes form exactly 
one valid binary tree.

If node i has no left child then leftChild[i] will equal -1, similarly for the right child.

Note that the nodes have no values and that we only use the node numbers in this problem.*/

/*Conditions for validating binary tree
i.Graph should be connected
ii.There should always be one root
iii.A node should only one have one parent*/
bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int> parent(n,-1);
        for(int i=0;i<leftChild.size();i++){
            if(leftChild[i]!=-1){
                int child=leftChild[i];
                if(parent[child]!=-1 and parent[child]!=i) return false;
                else parent[child]=i;
            }
            if(rightChild[i]!=-1){
                int child=rightChild[i];
                if(parent[child]!=-1 and parent[child]!=i) return false;
                else parent[child]=i;
            }
        }
        int root=-1;
        for(int i=0;i<n;i++){
            if(parent[i]==-1){
                if(root==-1) root=i;
                else return false;
            }
        }
        if(root==-1) return false;
        queue<int> q;q.push(root);
        int count=0;
        //checking the connectivity of graph
        vector<bool> vis(n,false);
        while(q.size()>0){
            auto x=q.front();q.pop();
            if(vis[x]) continue;
            count++;vis[x]=true;
            if(leftChild[x]!=-1 and vis[leftChild[x]]==false) q.push(leftChild[x]);
            if(rightChild[x]!=-1 and vis[rightChild[x]]==false) q.push(rightChild[x]);
        }
        return count==n;
}
int main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(NULL);
      cout.tie(NULL);
      return 0;
}