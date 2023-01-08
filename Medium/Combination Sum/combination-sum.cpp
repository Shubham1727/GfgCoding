//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
    //Function to return a list of indexes denoting the required 
   
    //combinations whose sum is equal to given number.
    void solve(vector<int> &arr, int B ,vector<vector<int> > &ans , vector<int>  &pair , int i){
        
        if(B==0){
            ans.push_back(pair);
            return;
        }
        if(i>=arr.size())
            return ;
        
        while(i<arr.size()&& B-arr[i]>=0){
                pair.push_back(arr[i]);
                solve(arr ,B-arr[i] , ans , pair , i);
                i++;
                pair.pop_back();
            }
            
    }
    vector<vector<int> > combinationSum(vector<int> &A, int B) {
        // Your code here
          vector<vector<int> > ans;
        vector<int>  pair;
        sort(A.begin(),A.end());
        //int n = arr.size();
        set<int> s(A.begin(), A.end());
        A.assign(s.begin(),s.end());
        solve(A ,B , ans , pair , 0 );
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
        vector<int> A;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            A.push_back(x);
        }   
        int sum;
        cin>>sum;
        Solution ob;
        vector<vector<int>> result = ob.combinationSum(A, sum);
   		if(result.size()==0){
   			cout<<"Empty";
   		}
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}	
// } Driver Code Ends