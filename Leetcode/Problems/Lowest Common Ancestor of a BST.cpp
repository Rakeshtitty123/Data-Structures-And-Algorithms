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
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL){};
};
/*O(n) approach*/
TreeNode *ans;
void findLCA(TreeNode* root,TreeNode* p,TreeNode* q,bool &pFlag,bool &qFlag){
      if(!root)
          return;
      bool npFlag = false, nqFlag = false;
      findLCA(root->left, p, q, npFlag, nqFlag);
      findLCA(root->right, p, q, npFlag, nqFlag);
      if(root==p)
          npFlag = true;
      if(root==q)
          nqFlag = true;
     if(npFlag and nqFlag and ans==NULL)
         ans = root;
     pFlag |= npFlag, qFlag |= nqFlag;
     return;
}
TreeNode* lowestCommonAncestor(TreeNode* root,TreeNode* p,TreeNode* q){
    bool pFlag = false, qFlag = false;
    findLCA(root, p, q, pFlag, qFlag);
    return ans;
}
/*O(log n)*/
TreeNode* lowestCommonAncestor(TreeNode* root,TreeNode* p,TreeNode* q){
    while((root->val-p->val)*(root->val-q->val)>0){
        root=root->val>p->val?root->left:root->right;
    }
    return root;
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