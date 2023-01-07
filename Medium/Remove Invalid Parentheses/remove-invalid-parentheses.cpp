//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            cin >> A[i];
        }
    }
 
    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            if(i!=A.size()-1) cout << A[i]<< " ";
            else cout << A[i];
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {
  public:
    void solve(string s , vector<string> &ans , unordered_map<string, bool>& mp , int rem){
        if(mp[s])
            return;
        mp[s]=true;

        if(rem==0){
            int neededrem = removal(s);
                if(neededrem ==0)
                    ans.push_back(s);
            return ;
        }

        for(int i = 0 ; i<s.length() ; i++){
            string leftpart = s.substr(0,i);
            string rightpart = s.substr(i+1);
            string join = leftpart + rightpart;
            solve(join , ans, mp , rem-1);
        }
        return ;
    }
    int removal(string s){
        stack<char>st;

        for(int i =0 ; i< s.size() ; i++){
            if(s[i]=='(')
                st.push(s[i]);
            else if(s[i]==')'){
                if(!st.empty() && st.top() == '(')
                    st.pop();
                else
                    st.push(s[i]);
            }
        }
        return st.size();
    }
    vector<string> removeInvalidParentheses(string s) {
        unordered_map<string, bool> mp;
        int minremoval = removal(s);
        vector<string> ans;
        solve(s, ans, mp , minremoval);
        sort(ans.begin() , ans.end() );
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        
        string s; 
        cin>>s;
        
        Solution obj;
        vector<string> res = obj.removeInvalidParentheses(s);
        
        Array::print(res);
        
    }
}

// } Driver Code Ends