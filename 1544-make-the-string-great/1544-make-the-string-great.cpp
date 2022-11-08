class Solution {
public:
    string makeGood(string s) {
        stack<int> s1;
        
        int i=0;
         for (int i = 0;i<s.size();i++){
            if(!s1.empty() && abs(s1.top()-s[i]) == 32) 
            {
                s1.pop();                
            }
            else 
            s1.push(s[i]);
        }
        
        string ans="";
        
        while(!s1.empty())
        {
            ans += s1.top();
            s1.pop();
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};