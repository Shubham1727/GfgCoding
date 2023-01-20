//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool dfs(int node , int vis[], int dfsvis[] , vector<int> adj[]){
        vis[node]=1;
        dfsvis[node]=1;
        for(auto it : adj[node]){
            if(vis[it]==0){
                if(dfs(it, vis, dfsvis , adj))
                    return true;
            }
            else if(dfsvis[it]==1)
                return true;
        }
        dfsvis[node]=0;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        int vis[V]={0}; 
        int dfsvis[V] ={0};
         
        for(int i =0 ; i<V ; i++){
            if(vis[i]==0){
                if(dfs(i, vis , dfsvis, adj))
                    return true;
                
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends