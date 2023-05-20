#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef long long int ll;
void manacherLongestPalindromicSustring(string &p){
    string s = "@";
    for (int i = 0; i < p.size();i++){
        s += '#';
        s += p[i];
    }
    s += "#";
    s += "$";
    // cout << s << '\n';
    int n = s.size();
    vector<int> lps(n + 1, 0);
    int c = 0, r = 0;
     int maxLen = 0, maxIdx = 0;
    for (int i = 1; i < (int)s.size() - 1; i++){
        ll mirr = c - (i - c);
        if(i<r)lps[i] = min(lps[mirr], r - i);
        while (i+lps[i]+1<n and i-lps[i]-1>=0 and s[i + lps[i] + 1] == s[i - lps[i] - 1])
            lps[i]++;
        if (i + lps[i] < r){
            c = i;
            r = i + lps[i];
        }
        if(i>1 and i<n-2)
            cout << lps[i] << ' ';
    }
    // int startIdx = maxIdx - maxLen + 1;
    // int actualStartIdx = (startIdx - 2) / 2;
    // cout << maxLen << ' ';
    // cout << startIdx << ' ' << actualStartIdx << '\n';
    // cout << p.substr(actualStartIdx, maxLen) << '\n';
    // for (int i = 2; i < n - 2;i++)
    //     cout << lps[i] << ' ';
    cout << '\n';
}
void solve(){
        string s;
        cin >> s;
        manacherLongestPalindromicSustring(s);
}
int main(){
    int t;
    //cin >> t;
     t = 1;
        for (int i = 1; i <= t; i++){
    //      string s;
        //    cin >> s;
      //    getline(cin, s);
            solve();
        }
   
    return 0;
}