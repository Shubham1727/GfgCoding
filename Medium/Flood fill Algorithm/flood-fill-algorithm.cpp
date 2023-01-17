//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    void dfs(int sr , int sc ,vector<vector<int>>& ans , vector<vector<int>>& image , 
                int newColor , int intcolor , int nrow[] , int ncol[]){
        ans[sr][sc]=newColor;
        int n =image.size();
        int m = image[0].size();
        for(int i =0 ; i<4 ; i++){
            int row = sr +nrow[i];
            int col = sc + ncol[i];
            
            if(row<n && row>=0 && col<m && col>=0 && image[row][col]==intcolor 
                    && ans[row][col]!=newColor)
                 dfs(row , col,ans, image ,newColor , intcolor , nrow , ncol);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here
        int intcolor = image[sr][sc];
        vector<vector<int>>ans = image;
        int nrow[] = {-1 , 0, +1 ,0};
        int ncol[] = {0 ,+1,0 , -1};
        dfs(sr,sc ,ans, image ,newColor , intcolor , nrow , ncol);
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends