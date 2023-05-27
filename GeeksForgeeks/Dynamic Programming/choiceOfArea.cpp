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
map<pair<int,int>,int> mp;
int maxSurvival(int A,int B,int last,vector<pair<int,int>> &area){
    if(A<=0 or B<=0) return 0;
    pair<int,int> p=make_pair(A,B);
    if(mp.find(p)!=mp.end()) return mp[p];
    int maxSurvive=0;
    for(int i=0;i<3;i++){
        if(i!=last){
            maxSurvive=max(maxSurvive,1+maxSurvival(A+area[i].first,B+area[i].second,i,area));
        }
    }
    return mp[p]=maxSurvive;
}
int getMaxSurvival(int A,int B,vector<pair<int,int>> &area){
    if(A<=0 or B<=0) return 0;
    int res=0;
    for(int i=0;i<3;i++){
        res=max(res,maxSurvival(A+area[i].first,B+area[i].second,i,area));
    }
    return res;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int A,B;cin>>A>>B;
    vector<pair<int,int>> area(3);
    for(int i=0;i<3;i++) cin>>area[i].first>>area[i].second;
    cout<<getMaxSurvival(A,B,area);
    #ifndef ONLINE_JUDGE
    #endif
    return 0;
}