//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    // void addsolution(vector<vector<int>> &ans , vector<vector<int>> &board , int n){
        
    //     vector<int> temp;
    //      for(int i =0 ; i<n ; i++){
    //         for(int j =0 ; j<n ; j++){
    //             temp.push_back(j);
    //         }
    //      }
    //      ans.push_back(temp);
    // }
    bool issafe(int row , int col , vector<vector<int>> &board , int n){
        int x = row;
        int y = col;
        
        while(y>=0){
            if(board[x][y]==1)
                return false;
            y--;
        }
         x = row;
         y = col;
        
        while(x>=0&&y>=0){
            if(board[x][y]==1)
                return false;
            y--;
            x--;
        }
         x = row;
         y = col;
        
        while(x<n && y>=0){
            if(board[x][y]==1)
                return false;
            y--;
            x++;
        }
        return true;
    }
public:
    void solve(int col , vector<vector<int>> &ans , vector<vector<int>> & board , int n ,vector<int> s){
        if(col==n){
            ans.push_back(s);
            return;
        }
        for(int row = 0 ; row<n ; row++){
            if(issafe(row,col,board,n)){
                board[row][col]=1;
                s.push_back(row+1);
                solve(col+1 , ans , board,n , s);
                board[row][col]=0;
                s.pop_back();
            }
        }
    }
    vector<vector<int>> nQueen(int n) {
        // code here+++++++++++
        vector<vector<int>> board(n,(vector<int>(n,0)));
        vector<vector<int>> ans;
        vector<int> s;
        solve(0 , ans , board , n , s);
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends