//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
 bool check_palindrome(int i, int j, string s){
        while(i<=j){
            if(s[i]!=s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
  void partition1(string s, int i, vector<string>&temp, vector<vector<string>>&answer){
        if(i==s.length()){
            answer.push_back(temp);
            return;
        }
        for(int j=i;j<s.length();j++){
            if(check_palindrome(i, j, s)){
                temp.push_back(s.substr(i, j-i+1));
                partition1(s, j+1, temp, answer);
                temp.pop_back();
            }
        }
    }
 vector<vector<string>> allPalindromicPerms(string s) {
        // code here
        vector<vector<string>>answer;
        vector<string>temp;
        partition1(s, 0, temp, answer);
        return answer;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        
        cin>>S;

        Solution ob;
        vector<vector<string>> ptr = ob.allPalindromicPerms(S);
        
        for(int i=0; i<ptr.size(); i++)
        {
            for(int j=0; j<ptr[i].size(); j++)
            {
                cout<<ptr[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends