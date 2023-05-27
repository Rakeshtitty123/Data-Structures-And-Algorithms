#include<bits/stdc++.h>
using namespace std;
class trieNode{
private:
    trieNode* next[101];
    int count = -1;
public:
    void insert(vector<int>& v, int val){
        trieNode* node = this;
        for(auto s:v){
            if(!node->next[s])node->next[s] = new trieNode();
            node = node->next[s];
        }
        node->count = val;
    }
    int search(vector<int>& v){
        trieNode* node = this;
        for(auto s:v){
            if(!node->next[s])return -1;
            node = node->next[s];
        }
        return node->count;
    }
};

class Solution {
public:   

    vector<int> cut(vector<int>& v, int i, int l){
        vector<int> temp;
        for(int j = 0; j < i; j++)temp.push_back(v[j]);
        for(int j = i+l; j < v.size(); j++)temp.push_back(v[j]);
        return temp;
    }
 int helper(vector<int>& v, trieNode* dp){
        int f = dp->search(v);
        if(f!=-1)return f;
        int n = v.size();
        if(n==0)return 0;
        int temp = 0, i = 0;
        while(i<n){
            int l = 0;
            for(int j = i; j < n; j++){
                if(v[j]!=v[i])break;
                l++;
            }
            vector<int> vv = cut(v, i, l);
            i += l;
            // for(auto a:vv)cout<<a<<" ";
            // cout<<endl;
            temp = max(temp, l*l+helper(vv, dp));
        }
        // for(int i = 0; i < n; i++){
        //     cout<<v[i]<<" ";
        // }
        // cout<<" --> "<<temp<<endl;
        dp->insert(v, temp);
        return temp;
    }

    int removeBoxes(vector<int>& boxes) {
        trieNode* dp = new trieNode();
        return helper(boxes, dp);
    }
};