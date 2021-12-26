class Solution {
private:
    int reverse(int n)
    {
        int rem=0, rev=0;
        
        while(n)
        {
            rem=n%10;
            rev=rev*10+rem;
            n=n/10;
        }
        
        return rev;
    }
public:
    bool isSameAfterReversals(int num) {
        int rev1=0, rev2=0;
        
        rev1=reverse(num);
        rev2=reverse(rev1);
        
        return rev2==num;
    }
};