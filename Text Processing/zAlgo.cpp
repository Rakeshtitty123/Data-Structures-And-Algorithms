#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#define gcj "Case #"
#define adj_list vector<vi>
#define endl "\n"
#define spc " "
#define INF_INT 2e9
#define INF_LL 2e18
#define matmax 25
#define mod 1000000007
#define mp make_pair
#define pb push_back
#define pi pair<int, int>
#define pip pair<int,pi>
#define pl pair<ll,ll>
#define plp pair<ll,pl>
#define vi vector<int>
#define vl vector<ll>
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(x) x.begin(), x.end()
#define ins insert
#define lb lower_bound  // First element NOT LESS than val
#define ub upper_bound  // First element GREATER than val
#define sz(q) (int)(q.size())
using namespace std;
using namespace __gnu_pbds;
typedef long long int ll;
typedef long int li;
#define ook order_of_key  // Number of elements STRICTLY smaller than X
#define fbo find_by_order  //  *ITERATOR* pointing to the kth element (0 order)
#define fo(a,b) for(auto i=a;i<b;++i)
#define nfo(a,b) for(auto i=a;i>=b;--i)
#define jfo(a,b) for(auto j=a;j<b;++j)
#define njfo(a,b) for(auto j=a;j>=b;--j)
#define tt ll t; cin>>t; while(t--)
template<typename T>
ostream& operator<<(ostream& os, vector<T>& intermediate_array) { for (auto& a : intermediate_array) cout << a << ' '; return os; }
template<typename T>
istream& operator>>(istream& is, vector<T>& intermediate_array) { for (auto& a : intermediate_array) cin >> a; return is; }
template<typename T>
void print(T a) { cout << a << endl; }
template<typename T, typename... Args>
void print(T a, Args... b) { cout << a << " "; print(b...); } 
template<typename T>
void _debug(T a) {
    if (typeid(a) == typeid(char)) cout << '\'';
    if (typeid(a) == typeid(string)) cout << '\"';
    cout << a;
    if (typeid(a) == typeid(char)) cout << '\'';
    if (typeid(a) == typeid(string)) cout << '\"';
    cout << "]" << endl;
}
template<typename T, typename... Args>
void _debug(T a, Args... b) {
    if (typeid(a) == typeid(char)) cout << '\'';
    if (typeid(a) == typeid(string)) cout << '\"';
    cout << a;
    if (typeid(a) == typeid(char)) cout << '\'';
    if (typeid(a) == typeid(string)) cout << '\"';
    cout << ",\t";
    _debug(b...);
}
template<typename... Args>
void debug(Args... b) { cout << '['; _debug(b...); }
/*______________________________________________________________________________________________________________________________________*/
/*
z function of an Algorithm:
zFunc(i)=longest substring starting at that index which is also a proper prefix.
Note:
1.Overlapping is allowed...
2.not defined for zero index
*/
vector<int> zFuncBrute(string &s){
    vector<int> z(s.size(), 0);
    for (int i = 1; i < s.size();i++){
        while(s[z[i]]==s[i+z[i]])
            ++z[i];
    }
    debug(z);
    return z;
}
/*
   s=  c1 c2 c3 c4 c5 c6 c7 c8 c9 c10 ...............,

   Let z[5]=4 which means c1c2c3c4=c5c6c7c8
   Now we can avoid the loop for caluclating z[6] as we have already computed upto 8th index
   c1c2c3c4==c5c6c7c8 which means c2c3c4==c6c7c8
   since they are equal we can directly write c6=z[2] as both arre equal
   Let z[2]=2 c1c2=c3c4 we also know that c2c3c4=c6c7c8 so we can atleast say that c1c2=c6c7 
   and then we start the zfunction bruteforce from there
   but we can't directly write c6=z[2] as may case arise that the rightmost index which c[5] can be low
   suppose c2[5] but c[5]=4 c[6] can be max equal to c[3] i.e, the part we can directly compare is 3
   we should take min among them 
   z[6]=min(c[2],r-i+1);
*/
vector<int> zFunc(string &s){
    vector<int> z(s.size(), 0);
    int left = 0, right = 0;
    for (int i = 1; i < s.size();i++){
        //if it is below the range then only we can compare
        if(i<=right)
            z[i] = min(right - i + 1, z[i - left]);
        //after jumoing we brute force
        while(i+z[i]<s.size() and  s[z[i]]==s[i+z[i]])
            ++z[i];
            //we update the range if we get more info
        if(i+z[i]-1>right){
            left = i;
            right = i + z[i] - 1;
        }
    }
    debug(z);
    return z;
}
void findPattern(string &p,string &t){
    string s = p + '@' + t;
    vector<int> z(s.size(), 0);
    int l = 0, r = 0;
    for (int i = 1; i < s.size();i++){
        if(i<=r)
            z[i] = min(z[i - l], r - i + 1);
        while(i+z[i]<s.size() and (s[z[i]])==s[i+z[i]])
            ++z[i];
        if(i+z[i]-1>r){
            l = i;
            r = i + z[i] - 1;
        }
    }
    for (int i = p.size() + 1; i < s.size();i++){
        if(z[i]==p.size())
            cout << i-(p.size()+1) << ' ';
    }
}
int main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(NULL);
      cout.tie(NULL);
      string p;
      cin >> p;
      string t;
      cin >> t;
      //zFuncBrute(s);
      //zFunc(s);
      findPattern(p, t);
      return 0;
}