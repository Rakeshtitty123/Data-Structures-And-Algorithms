#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int bs(vector<ll> v,int l,ll t){
    int n = v.size();
    int r = n-1;
    ll sub = v[l-1];
    int index = -1;
    while(l<=r){
        int m = (l+r)/2;
        if(v[m]-sub<=t){
            index = m;
            l=m+1;
        }
        else{
            r=m-1;
        }
    }
    return index;
}

int main()
{
    int n;cin>>n;
    ll t;cin>>t;
    vector<ll> v(n,0);
    for(int i=0;i<n;i++) cin>>v[i];
    vector<ll> pre(n+1,0ll);
    for(int i=1;i<=n;i++){
        pre[i] = pre[i-1]+v[i-1];
    }
    int maxi = 0;
    for(int i=1;i<=n;i++){
        int m = bs(pre,i,t);
        if(m!=-1){
        cout<<i<<" "<<(m-i+1)<<endl;
        maxi = max(maxi,(m-i+1));
        }
    }
    cout<<maxi<<endl;
    return 0;
}