class Solution {
public:
    double calculateTax(vector<vector<int>>& brackets, int income) {

         double tax = 0.0;
        
        for (int index = 0; index < brackets.size() && income > 0; ++index) {
            int diff = (index == 0) ? brackets[0][0] : (brackets[index][0] - brackets[index-1][0]);
            tax += (min(income, diff) * brackets[index][1] * 0.01);
            income -= diff;
        }
        
        return tax;
    }
};