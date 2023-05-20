#include <bits/stdc++.h>
#define ll long long

using namespace std;

int manacher[2000006];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    string s; cin >> s;
    string t = "";
    for(char c: s) {
        t.push_back('*');
        t.push_back(c);
    }

    t.push_back('*');
    int maxIdx = 0, maxLen = 0;

    for(int i = 0, l = -1, r = -1; i < (int) t.size(); ++i) {
        if (i <= r) manacher[i] = min(r - i, manacher[2 * l - i]);
        while (i + manacher[i] + 1 < (int) t.size() && i - manacher[i] - 1 >= 0 && t[i + manacher[i] + 1] == t[i - manacher[i] - 1])
            ++manacher[i];
        if (i + manacher[i] > r) {
            l = i;
            r = i + manacher[i];
        }

        // if (i > 0 && i < (int) t.size() - 1) cout << manacher[i] << ' ';
        if(manacher[i]>maxLen){
            maxIdx = i;
            maxLen = manacher[i];
        }
    }
    string ans;
    int j = maxIdx - 1, k = maxLen;
    while(k--){
        if(t[j]!='*')
            ans += t[j];
        j--;
    }
    reverse(begin(ans), end(ans));
    if (t[maxIdx] != '*')
        ans += t[maxIdx];
    j = maxIdx + 1;
    k = maxLen;
    while(k--){
        if(t[j]!='*')
            ans += t[j];
        j++;
    }
    cout << ans << '\n';
    return 0;
}