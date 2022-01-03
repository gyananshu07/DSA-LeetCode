class Solution {
public:
    int reinitializePermutation(int n) {
        vector<int> perm(n), arr(n); 
        for (int i = 0; i < n; ++i) perm[i] = arr[i] = i; 
        
        for (int k = 1; ; ++k) {
            vector<int> tmp = arr; 
            bool flag = true; 
            for (int i = 0; i < n; ++i) {
                if (i&1) arr[i] = tmp[n/2 + (i-1)/2]; 
                else arr[i] = tmp[i/2]; 
                if (perm[i] != arr[i]) flag = false; 
            }
            if (flag) return k; 
        }
        return 0; 
    }
};