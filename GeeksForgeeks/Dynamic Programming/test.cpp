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
int maxSumWo3Cons(int n,vector<int> &nums){
    vector<int> dpExcl(n),dpIncl(n);
    dpExcl[0]=0;dpIncl[0]=nums[0];
    dpExcl[1]=nums[0];dpIncl[1]=nums[0]+nums[1];
    for(int i=2;i<n;i++){
        dpExcl[i]=dpIncl[i-1];
        dpIncl[i]=max(dpExcl[i-2]+nums[i-1]+nums[i],dpExcl[i-1]+nums[i]);
        dpExcl[i]=dpIncl[i-1];
    }
    return max(dpExcl[n-1],dpIncl[n-1]);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
     int n;cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    cout<<maxSumWo3Cons(n,v);
    #ifndef ONLINE_JUDGE
    #endif
    return 0;
}