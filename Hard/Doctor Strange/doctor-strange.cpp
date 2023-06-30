//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    vector<int> I;
vector<vector<int>> G;
int id = 0, C = 0;
int dfs(int v, int p) {
    int low = I[v] = ++id, flag = 0;
    for (auto& u: G[v]) {
        if (u == p) continue;
        int l = I[u];
        if (!l)
            l = dfs(u, v),
            flag = flag || l > I[v];
        low = min(low, l);
    }
    if (p>=0 && flag) C++;
    return low;
}
int doctorStrange(int N, int M, vector<vector<int>> & graph) {
    G.resize(N); I.resize(N);
    for (int i = 0; i < M; i++) {
        auto& e = graph[i];
        G[e[0]-1].push_back(e[1]-1),
        G[e[1]-1].push_back(e[0]-1);
    }
    dfs(0, -1);
    return C;
}
};


//{ Driver Code Starts.

int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n,m,i;
        cin>>n>>m;
        vector<vector<int>> g(n+1);
        for(i=0;i<m;i++)
        {
            int a,b;cin>>a>>b;
            g[i].push_back(a);
            g[i].push_back(b);
        }
        Solution ob;
        int ans = ob.doctorStrange(n, m, g);
        cout<<ans<<endl;
    }
	return 0;
}
// } Driver Code Ends