#include<bits/stdc++.h>
using namespace std;
unordered_map<int, unordered_map<int,int>> mp;
void solve(vector<unordered_map<int,int>> &graph,int k){
    int n = graph.size();
    for (int i = 0; i < n;i++){
        if(graph[i].size()>k){
            priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
            for(auto it:graph[i]){
                if(mp[i].find(it.first)!=mp[i].end())
                    continue;
                if(pq.size()<k)
                    pq.push({it.second, it.first});
                else{
                    if(pq.top().first<it.second){
                        auto x = pq.top();
                        pq.pop();
                        pq.push({it.second, it.first});
                        mp[i][x.second] = x.first;
                        mp[x.second][i] = x.first;
                    }else{
                        mp[i][it.first] = it.second;
                        mp[it.first][i] = it.second;
                    }
                }
            }
        }
    }
    int total = 0;
    for (int i = 0; i < n;i++){
       for(auto it:graph[i]){
           if(mp[i].find(it.first)==mp[i].end()){
               total += it.second;
           }
       }
    }
    cout << total/2<< '\n';
}
int main(){
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    int k;
    cin >> k;
    vector<unordered_map<int, int>> graph(n);
    int edges;
    cin >> edges;
    for (int i = 0; i < edges;i++){
        int from, to, cost;
        cin >> from >> to >> cost;
        graph[from][to] = cost;
        graph[to][from] = cost;
    }
    solve(graph, k);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    //pq.push(5);
    //pq.push(1);

    return 0;
}