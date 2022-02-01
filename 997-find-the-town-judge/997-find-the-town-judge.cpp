class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> arr(n+1, 0);
        
        for(auto t: trust)
        {
            //[[1,3],[2,3]]
            //[1,2,3]->arr
            //1->-1  2->-1  3->1 + 1=3-1 == 2   
            arr[t[0]]--; 
            arr[t[1]]++;
        }
        
        for(int i=1; i<=n; i++)
        {
            if(arr[i]==n-1) //if indegree-outdegree i.e. arr[i]==n-1
                return i;
        }
        
        return -1;
    }
};