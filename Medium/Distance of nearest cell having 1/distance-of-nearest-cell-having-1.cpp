//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	bool isvalid(int row , int col , int n ,int m , vector<vector<int>> &vis){
	    if(row>= 0 and row< n and col >=0 and col<m and vis[row][col]==0)
	        return true;
	   return false;
	}
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    // Code here
	    int n = grid.size();

     int m =grid[0].size();

     vector<vector<int>> vis(n, vector<int>(m,0));

        vector<vector<int>> dis(n, vector<int>(m,0));

        queue<pair<pair<int,int>,int>> q;

        for(int i = 0; i<n; i++)

        {

            for(int j = 0; j<m; j++)

            {

            if(grid[i][j] == 1)

            {

            q.push({{i,j}, 0});

            vis[i][j] =1;

            }

        

        

  else

  {

      vis[i][j]=0;

  }

     }

     }

  int delrow[] = {-1,0,+1,0};

  int delcol[] = {0,+1,0,-1};

  while(!q.empty())

  {

      int row = q.front().first.first;

      int col = q.front().first.second;

      int steps = q.front().second;

      q.pop();

      dis[row][col]=steps;

      for(int i = 0;i<4; i++)

      {

          int nrow = row+ delrow[i];

          int ncol = col + delcol[i];

          if(	isvalid(nrow , ncol , n,m , vis))

          {

              vis[nrow][ncol]=1;

              q.push({{nrow,ncol},steps+1});

          }

      }

      

  }

     return dis;

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
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends