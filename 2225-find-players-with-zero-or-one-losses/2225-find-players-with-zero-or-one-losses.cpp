class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int, int> win;
        map<int, int> lose;
        vector<vector<int>> answer;
        vector<int> ans, ans1;
        
        for(auto m: matches)
        {
            win[m[0]]++;
            lose[m[1]]++;
        }
        
        for(auto it: win)
        {
           if(lose[it.first]==0)
           {
               ans1.push_back(it.first);
           }
        }
        
        for(auto it: lose)
        {
           if(lose[it.first]==1)
           {
               ans.push_back(it.first);
           }
        }

        answer.push_back(ans1);
        answer.push_back(ans);
        
        return answer;
    }
};