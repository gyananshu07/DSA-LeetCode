class Solution {
public:
//     void reverse(int i, int n, vector<char>& s)
//     {
//         if(i>=n/2)
//             return;
        
//         reverse(i+1, n, s);
//         swap(s[i], s[n-i-1]);
//     }
    
//     void reverseString(vector<char>& s) {
//         int n = s.size();
//         reverse(0, n, s);
//     }
    
    
     void reverseString(vector<char>& s) {
        int n = s.size();
        int lo=0, hi=n-1;
         
         while(lo<=hi)
         {
             swap(s[lo], s[hi]);
             lo++, hi--;
         }
    }
};