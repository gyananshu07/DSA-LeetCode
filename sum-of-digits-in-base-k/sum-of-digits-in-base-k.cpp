class Solution {
public:
    int sumBase(int n, int k) {
        int sum=0, rem=0;
        
        while(n)
        {
            rem = n%k;
            sum = sum+rem;
            n=n/k;
        }
        
        return sum;
    }
};