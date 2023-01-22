//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    	bool isvalid(int row , int col , int n ,int m , vector<vector<int>> &vis ,vector<vector<int>>& grid){
	    if(row>= 0 and row< n and col >=0 and col<m and vis[row][col]==0 and grid[row][col]==1)
	        return true;
	   return false;
	}
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m,0));
        int time= 0;
         queue<pair<pair<int, int> , int >> q;
        for(int i =0 ; i< n ; i++){
            for ( int j =0 ; j< m ; j++){
                if (grid[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j]=2;
                }
                else
                    vis[i][j]=0;
            }
        }
        int delrow[]={ -1, 0, 1, 0};
        int delcol[]={0,1,0,-1};
        
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int tm = q.front().second;
            time = max(time , tm);
            q.pop();
            for(int i = 0; i<4 ; i++){
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];
                if(isvalid(nrow , ncol , n,m , vis , grid)){
                    vis[nrow][ncol]=2;
                    q.push({{nrow , ncol} , time +1});
                }
            }
        }
        for(int i =0 ; i< n ; i++){
            for ( int j =0 ; j< m ; j++){
                if(vis[i][j]!=2 && grid[i][j]==1)
                    return -1;
            }
        }    
        return time;
        
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends