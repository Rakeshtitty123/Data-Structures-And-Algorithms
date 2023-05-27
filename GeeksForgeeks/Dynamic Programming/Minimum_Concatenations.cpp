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
/*Given string a and string b. a is conctaned infinte times ..We neeed to find the minim of i such that after concateing a 
a[0.........i] should contain the string b as subsequence of it.

Let us suppose string a="abc" and b="cbab"
Then index i upto which b can be a subsequence string 

a="abc",b="cbab"  

          abcabcabcbabcabcabc.....................
            c b ab
                 8===index at which the string b will be a subsequence(b)
                     
  We try to proceess the string b try to observe the string b  try to find the approach

         c             b               a                  b


        3,0            2,1             1,2               2,2(here the previous index is sammler than current index so it can be found in the original string order)
                   (see that the previous index has greater index than cur index in b .so a must be repeated
                    we keep a counter variable which keeps tracks of how may times string must be repeated)
    
So the string abc is repeated 2 times and last index at 2 pos(1-based indexing)
3*2+2=9

In the case of duplicates we can mainatin a setof  integers and we find upper bound the previous index in the current index map
if it set.end() then we need to repeat and increment ans++ otherwise we need to put cur at b[i]

                */
int solve(string &a,string &b){
      map<char,set<int>> mp;
      for(int i=0;i<a.size();i++) mp[a[i]].insert(i);
      for(char ch:b) if(mp.find(ch)==mp.end()) return -1;
      int cur=*mp[b[0]].begin(),ans=0,res=cur;
      for(int i=1;i<b.size();i++){
        auto pos=upper_bound(mp[b[i]].begin(),mp[b[i]].end(),cur);
        if(pos==mp[b[i]].end()){
            ans++;
            /*if the index has not found we make the current index at the begining of cur*/
            cur=*mp[b[i]].begin();
        }else{
            cur=*pos;
            res=*pos;
        }
      }
      return (ans*(a.size()))+res+1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string a,b;
    cin>>a>>b;
    cout<<solve(a,b);
    #ifndef ONLINE_JUDGE
    #endif
    return 0;
}