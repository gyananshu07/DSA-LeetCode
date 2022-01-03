class Solution {
public:
    int reinitializePermutation(int n) {
        vector<int> perm, arr(n,0), orig(n,0);
        int count=0, x=0;
        
        for(int i=0; i<n; i++)
        {
            orig[i]=i;
        }
        perm = orig;
        
        while(arr!=orig)
        {
            for(int i=0; i<n; i++)
            {    
                if(i%2==0)
                {
                    arr[i] = perm[i/2];
                }

                else if(i%2==1)
                {
                    x = n/2 + (i-1)/2;
                    arr[i] = perm[x];
                }
            }
            
            perm = arr;
            count++;
        }
        
        
        return count;
    }
};