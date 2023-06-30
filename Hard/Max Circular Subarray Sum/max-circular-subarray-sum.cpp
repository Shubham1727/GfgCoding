//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    // arr: input array
    // num: size of array
    //Function to find maximum circular subarray sum.
    int circularSubarraySum(int arr[], int num){
        
        // your code here
             int totalsum =0;
        int maxending =0;
        int minending =0;
            int maxsum = INT_MIN;
        int minsum = INT_MAX;
        
        
        
       for(int i =0; i<num ; i++){
            totalsum += arr[i];
            
            maxending = max(maxending+arr[i], arr[i]);
            maxsum = max(maxsum, maxending);
            
            minending = min(minending+arr[i], arr[i]);
            minsum = min(minsum, minending);
            
            
            
        }

        
        
        if(maxsum > 0){
return max(maxsum, totalsum - minsum);
        }
        else{
            return maxsum;
        }

    }
};

//{ Driver Code Starts.

int main()
 {
	int T;
	
	//testcases
	cin>> T;
	
	while (T--)
	{
	    int num;
	    
	    //size of array
	    cin>>num;
	    int arr[num];
	    
	    //inserting elements
	    for(int i = 0; i<num; i++)
	        cin>>arr[i];
	        
	    Solution ob;
	    //calling function
	    cout << ob.circularSubarraySum(arr, num) << endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends