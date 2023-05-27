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
#define P4(n) P2(n),P2(n^1),P2(n^1),P2
#define P6(n) P4(n),P4(n^1),P4(n^1),P4
#define Look_Up P6(0),P6(1),P6(0),P6(1)
#define phi 1.6180339887498948
#define N 6
#define Maxx 10000
bool isvalid(string &s1,string &s2){
	return s1 < s2;
}
ll res = 0;
vector<unordered_map<string, ll>> dp;
ll solve(ll ind,ll n,vil &v,string &s,string &prev){
	if(ind>=n)
		return 0;
	if(dp[ind].find(prev)!=dp[ind].end())
		return dp[ind][prev];
	string cur = "";
	string temp = "";
	ll ans = -1;
	for (int i = ind; i < n;i++){
		cur += s[ind];
		if(isvalid(prev,cur)){
			ans = max(ans, v[cur.size()] + solve(i + 1, n,v,s,cur));
		}
		ans = max(ans, solve(i + 1,n,v, s,prev));
		//res = max(res, v[cur.size()] + solve(i + 1, cur));
		//res = max(res, solve(i + 1, temp));
	}
	res = max(res, ans);
	return dp[ind][prev]=ans;
   
}
int main()
{
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);

    cin.tie(NULL);
    cout.tie(NULL);

			string s;
			ll n = 0;
			vil v;
			for (int i = 0; i < 26;i++){
				for (int j = 0; j < 26;j++){
					s += ('a' + j);
					v.push_back(j + 1);
					n++;
				}
			}
			//cout << s << '\n';

			// v.resize(n + 1);
			dp.resize(n + 1);
			string temp = "";
			res = max(res, solve(0, n, v, s, temp));
			cout << res << '\n';
			// n = 0;
			// s = "";
			// v.clear();
			res = 0;
			dp.clear();
		

	// string s;c
	return 0;
}