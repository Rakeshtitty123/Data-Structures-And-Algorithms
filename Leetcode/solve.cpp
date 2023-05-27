#include<bits/stdC++.h>
using namespace std;
#define ll long long int
#define vi vector<int>
#define vil vector<ll>
#define vc vector<char>
#define vf vector<float>
#define vul vector<ull>
#define vb vector<bool>
#define vii vector<vector<int>>
#define vpii vector<pair<int,int>>
#define sti stack<int>
#define stc stack<char>
#define spii stack<pair<int,int>>
#define spic stack<pair<int,char>>
#define spcc stack<pair<char,char>>
#define pairi pair<int,int>
#define fl(i,n) for(int i=0;i<n;i++);
#define pb push_back
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
const ll mod=1e9+7;
const ll size=2*(1e6+1);
const ll limit=1e10+7;
int curMin=INT_MAX;
vector<string> ans;
unordered_map<string,bool> mp;
void solve(int ind,string &s,string &osf,int dlt,int sum){
        if(dlt>curMin or sum<0) return;
        if(ind==s.size()){
           if(dlt==curMin){
               if(sum==0 and mp.find(osf)==mp.end()) {
                   ans.push_back(osf);
                   mp[osf]=1;
               }
           }else if(dlt<curMin){
               if(sum==0){
                   curMin=dlt;
                   ans.clear();
                   mp.clear();
                   ans.push_back(osf);
                   mp[osf]=1;
               }
           }
            return;
        }
        if(s[ind]==')' or s[ind]=='('){
            sum+=(s[ind]=='('?1:-1);
            osf+=s[ind];
            solve(ind+1,s,osf,dlt,sum);
            osf.pop_back();
            sum-=(s[ind]=='('?1:-1);
            solve(ind+1,s,osf,dlt+1,sum);
            
        }else{
            osf+=s[ind];
            solve(ind+1,s,osf,dlt,sum);
            osf.pop_back();
        }
       
    }
vector<string> removeInvalidParentheses(string s) {
        string osf="";
        solve(0,s,osf,0,0);
        for(string s:ans)
            cout << s << '\n';
        return ans;
}
int main()
{
    freopen("Input.txt", "r", stdin); 
    freopen("Output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    cin >> s;
    removeInvalidParentheses(s);
    //cout<<"Hello World!";
    #ifndef ONLINE_JUDGE
    cout << "\nTime Elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " sec\n";
#endif
    return 0;
} 