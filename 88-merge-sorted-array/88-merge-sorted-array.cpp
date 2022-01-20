class Solution {
public:
   void merge(vector<int>& A, int m, vector<int>& B, int n) {
        int i=m-1, j=m+n-1, k=n-1;
        
        while(i >= 0 && k >= 0)
        {
            if(A[i] <= B[k])
                A[j--] = B[k--];
            else
                A[j--] = A[i--];
        }
        
        while(k >= 0)
            A[j--] = B[k--];
    }
};