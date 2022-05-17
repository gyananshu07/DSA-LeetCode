class Solution {
public:
    int fib(int n) {
        vector<int> dp(n+1, -1);
        if(n<2)
        {
            return n;
        }
        dp[0]=0;
        dp[1]=1;
        
        for(int i=2; i<=n; i++)
        {
            dp[i] = dp[i-1] + dp[i-2];
        }
        
        return dp[n];
    }
    
//     int fib(int n) {
//         vector<int> dp(n+1, -1);
//         if(n<2)
//         {
//             return n;
//         }
//         int prev2=0;
//         int prev=1;
        
//         for(int i=2; i<=n; i++)
//         {
//             int cur_i = prev + prev2;
//             prev2 = prev;
//             prev = cur_i;
//         }
        
//         return ;
//     }
// };
};