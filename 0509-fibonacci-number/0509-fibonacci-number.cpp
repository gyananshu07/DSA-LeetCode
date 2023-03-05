class Solution {
public:
    int fib(int n) {
        int prev = 1;
        int bef_prev = 0;
        int cur = 0;
        
        if(n == 0 || n == 1) 
            return n;
        
        for(int i=2; i<=n; i++)
        {
            cur  = prev + bef_prev;
            bef_prev = prev;
            prev = cur;
        }
        return prev;
    }
};