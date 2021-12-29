class Solution {
public:
    int totalMoney(int n) {
        int update=0, sum=0, counter=0;
        
        for(int i=1; i<=n; i++)
        {
            if(i%7==1)
            {
                counter++;
                update = counter;
                sum = sum + update;
            }
            else
            {
                update++;
                sum = sum + update;
            }
        }
        
        return sum;
    }
};