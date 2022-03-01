class Solution {
private:
    int decToBIN(int n)
    {
        int binaryNum[32];
        int i = 0, sum=0;
        
        while (n > 0)
        {

            binaryNum[i] = n % 2;
            n = n / 2;
            i++;
        }
 
        for (int j = i - 1; j >= 0; j--)
            sum += binaryNum[j];
        
        return sum;
    }
    
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        
        for(int i=0; i<=n; i++)
        {
            ans.push_back(decToBIN(i));
        }
        
        return ans;
    }
};