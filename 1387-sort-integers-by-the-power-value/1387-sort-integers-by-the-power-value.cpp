class Solution {
private:
     int power(int i, vector<int> &dp){
        
        if(i == 1) return 0;
         
        int val = 0;
         
        if(dp[i] != -1) return dp[i];
        
        if(i & 1) //odd
        { 
            val = 1+ power(3*i+1, dp);
        }
         else //even
        { 
            val = 1+ power(i/2, dp);
        }
         
        return dp[i] = val;
    }

public:
    int getKth(int lo, int hi, int k)
    {
        vector<int> dp(1000000, -1);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; 
        
        for(int i=lo; i<=hi; i++)
        {
            int p = power(i, dp); 
            pq.push(make_pair(p, i)); 
        }
        
        while(--k)
        {
            pq.pop(); 
        }
        
        return pq.top().second; // returning the kth element
    }
};