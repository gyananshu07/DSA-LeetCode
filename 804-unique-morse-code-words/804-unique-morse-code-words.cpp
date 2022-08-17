class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<char> arr(26);
        int n=words.size();
        vector<string> newArr(n);
        vector<string> code = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        for(int i=0; i<26; i++)
        {
           arr[i] = 'a' + i; 
        }
        
        unordered_map<char, string> mp;
        
        for(int i=0; i<26; i++)
        {
            mp[arr[i]] = code[i];
        }
      
        for(int i=0; i<words.size(); i++){
            string newString = "";
            
            for(int j=0; j<words[i].size(); j++)
            {
                 newString += mp[words[i][j]];
            }
            newArr.push_back(newString);
        }
        
        unordered_set<string> s(newArr.begin(), newArr.end());
        
        return s.size()-1;
    }
};