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
set<string> res;
bool isValid(string &s){
    stack<char> st;
    for(char ch:s){
        if(ch=='(') st.push(ch);
        else{
            if(st.size()==0) return false;
            else st.pop();
        } 
    }
    return st.size() == 0;
}
void removeInvalid(int minChars,string &s){
     if(minChars==0){
        if(isValid(s)) res.insert(s);
         return;
     }
     for (int i = 0; i < s.size();i++){
         string temp = s.substr(0, i) + s.substr(i + 1);
         removeInvalid(minChars - 1, temp);
     }
}
vector<string> removeInvalidParantheses(string s){
    stack<char> st;
    for (int i = 0; i < s.size();i++){
        if(s[i]=='(')
            st.push(s[i]);
        else{
            if(st.size()==0) st.push(s[i]);
            else if(st.top()=='(') st.pop();
            else st.pop();
        }
    }
    int minChars = st.size();
    removeInvalid(minChars, s);
    vector<string> ans;
    for(auto it:res)
        ans.push_back(it);
    return ans;
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