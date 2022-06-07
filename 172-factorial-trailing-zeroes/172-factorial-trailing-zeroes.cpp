class Solution {
public:
    int trailingZeroes(int n) {
        int count = 0;
        for (int i = 1; i <= n; i++) {
            if (i % 5 == 0) {
                // Check for power of 5
                int pow5 = i;
                while ((pow5 % 5) == 0) {
                    pow5 /= 5;
                    count++;
                }
            }
        }
        return count;
    }
};