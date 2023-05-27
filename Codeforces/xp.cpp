#include <bits/stdc++.h>

using namespace std;
long long int mod = 1e9 + 7;
#define ll long long int
//endhuku ra ila...................

struct Mat {
    const static int SZ = 57;

    ll row, col;
    ll v[SZ][SZ];

    Mat(int r=0, int c=0) {
        row = r, col = c;
        memset(v, 0, sizeof v);
    }

    Mat operator * (const Mat &p) const {
        assert(col == p.row);

        Mat ret(row, p.col);
        for(int i=0; i<ret.row; ++i) {
            for(int j=0; j<ret.col; ++j) {
                ll & sum = ret.v[i][j];
                for(int k=0; k<col; ++k) {
                    sum =(sum+ (v[i][k] %mod* p.v[k][j]%mod)%mod)%mod;
                }
            }
        }

        return ret;
    }

    Mat power (int p) {
        assert(row == col);

        Mat base = *this;
        Mat ret(row, col);
        for(int i=0; i<row; ++i) ret.v[i][i] = 1;

        while(p > 0) {
            if(p & 1)
                ret = (ret * base);
            base = base * base;
            p >>= 1;
        }

        return ret;
    }
};

// kmp prefix function
vector<int> prefix_function(string P) {
    vector<int> pi(P.size());
    pi[0] = 0;
    int q = 0;    // number of matched characters

    for(int i=1; i<(int) P.size(); ++i) {
        while(q > 0 and P[q] != P[i]) q = pi[q-1];
        if(P[q] == P[i]) ++q;
        pi[i] = q;
    }
    return pi;
}

int f(int m, char c, const string& s, const vector<int>& pi) {
    while(m > 0 and s[m] != c) m = pi[m - 1];
    if(s[m] == c) ++m;
    return m;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t, tc = 0;
    cin >> t;
   // init_code();
    while(t--) {
        int n;
        cin >> n;

        string alphabet = "abc";

        string s = "aabca";

        auto pi = prefix_function(s);
        int ns = s.size();

        Mat G(ns, ns);
        for(int m=0; m<ns; ++m) {
            for(char c : alphabet) {
                int m_prime = f(m, c, s, pi);
                if(m_prime < ns) G.v[m][m_prime] += 1;
            }
        }
        G = G.power(n);

        Mat base(ns, 1);
        for(int m=0; m<ns; ++m) {
            base.v[m][0] = 1;
        }

        Mat dp_n = G * base;
        unsigned int res = dp_n.v[0][0];
        cout << res %mod<< '\n';
    }

    return 0;
}