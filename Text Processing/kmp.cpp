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
vector<int> zFunction(string &s){
      int n = s.size();
      vector<int> zFunc(n, 0);
      for (int i = 1; i < n;i++){
            while(s[zFunc[i]]==s[i+zFunc[i]])
                  zFunc[i]++;
      }
      for(int i:zFunc)
            cout << i << ' ';
      return zFunc;
}
bool solve(){
      char prev = '*';
      string s;
      for (int i = 0; i < s.size();i++){
           if(s[i]=='?')
                 s[i] = '?';
            else{
                  prev = s[i];
            }
      }
      for (int i = 0; i < s.size();i++){
            if(s[i]=='M' and s[i+1]=='U')
                  return false;
      }
      return true;
}
int main()
{

      ios_base::sync_with_stdio(false);
      cin.tie(NULL);
      cout.tie(NULL);
      string s;
      cin >> s;
      zFunction(s);
      return 0;
} 