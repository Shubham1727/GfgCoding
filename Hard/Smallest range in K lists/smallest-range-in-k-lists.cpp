//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define N 1000


// } Driver Code Ends
// you are required to complete this function 
// function should print the required range
class Solution{
    public:
   pair<int,int> findSmallestRange(int arr[][N], int n, int k)
    {
          //code here
          priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
          int maxi = INT_MIN;
          for(int i=0;i<k;i++){
              maxi = max(maxi,arr[i][0]);
              pq.push({arr[i][0],{i,0}});
          }
          int start = INT_MIN, end = INT_MAX, range = INT_MAX;
          while(!pq.empty()){
            int mini = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();
            if(range> maxi - mini +1){
                range = maxi-mini +1;
                start = mini;
                end = maxi;
            }
            if(col == n-1){
                break;
            }
            pq.push({arr[row][col+1],{row, col+1}});
            maxi = max(maxi, arr[row][col+1]);
          }
          return {start, end};
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, k;
        cin>>n>>k;
        int arr[N][N];
        pair<int,int> rangee;
        for(int i=0; i<k; i++)
            for(int j=0; j<n; j++)
                cin>>arr[i][j];
        Solution obj;
	    rangee = obj.findSmallestRange(arr, n, k);
	    cout<<rangee.first<<" "<<rangee.second<<"\n";
    }   
	return 0;
}


// } Driver Code Ends