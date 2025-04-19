/*************************************************************************
 * @File Name: topo_sort.cpp
 * @Description: 
 * @Author: ppq~
 * @Created Time: Sat Apr 19 12:23:23 2025
 ************************************************************************/
#include <iostream>
#include <string>
#include <algorithm>
#include <list>
#include <vector>
#include <set>
#include <map>
#include <memory>
#include <functional>
#include <stack> 
#include <queue>
using namespace std;

bool dfs(int u, vector<vector<int>>& adj, vector<int>& vis, stack<int>& st) {
    if(vis[u] == 1) return false;
    if(vis[u] == 2) return true;
    vis[u] = 1;
    for(int v: adj[u]) {
        if(!dfs(v, adj, vis, st)) {
            return false;
        }
    }
    vis[u] = 2;
    st.push(u);
    return true;
}


vector<int> toposort_dfs(int n, vector<vector<int>>& edges) {
    vector<vector<int>> adj(n);
    vector<int> res;
    for(auto& edge: edges) {
        adj[edge[0]].push_back(edge[1]);
    }

    stack<int> st;
    vector<int> vis(n,0);
    for(int i = 0; i < n; i++) {
        if(vis[i]==0) {
            if(!dfs(i, adj, vis, st)) {
                cout << "图中有环"<< endl;
                return res;
            }
        }
    }
    while(!st.empty()){
        res.push_back(st.top());
        st.pop();
    }
    return res;
}

vector<int> toposort_kahn(int n, vector<vector<int>>& edges){
    vector<vector<int>> adj(n);
    vector<int> res;
    vector<int> indegree(n, 0);
    for(auto &edge: edges) {
        adj[edge[0]].push_back(edge[1]);
        indegree[edge[1]]++;
    }
    queue<int> q;
    for(int i=0;i<n;i++) {
        if(indegree[i] == 0) q.push(i); 
    }
    int vis = 0; 
    while(!q.empty()){
        int u = q.front();
        q.pop();
        vis++;
        res.push_back(u);
        for(auto v:adj[u]) {
            indegree[v] --;
            if(indegree[v] == 0) {
                q.push(v);
            }
        }
    }
    if(vis != n) {
        cout << "图中有环 size = "<< vis << endl;
        return res;
    } else {
        return res;
    }

}



int main()
{
    int n = 4;
    vector<vector<int>> edges = {{0,1}, {0,2}, {1,3}, {2,3}, {3,2}};

    vector<int> topo_res = toposort_kahn(n, edges);
    
    for(auto &it: topo_res) {
        cout << it << endl;
    } 
    return 0;
}

