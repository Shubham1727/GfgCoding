//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    void dfs(int row, int col, vector<vector<char>> &grid, vector<vector<bool>> &vis)

{

    vis[row][col] = true;

    int n = grid.size();

    int m = grid[0].size();

    for (int i = -1; i <= 1; i++)

    {

        for (int j = -1; j <= 1; j++)

        {

            int nrow = row + i;

            int ncol = col + j;

            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == '1' && !vis[nrow][ncol])

            {

               

               dfs(nrow, ncol, grid, vis);

               

            }

        }

    }

}
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n , vector<bool>(m,0));
        int count = 0;
        for(int row = 0 ; row<n; row++){
            for(int col = 0 ; col<m ; col++){
                if(vis[row][col]==0 && grid[row][col]=='1'){
                    count++;
                    dfs(row, col , grid, vis);
                }
            }
        }
        return count;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends