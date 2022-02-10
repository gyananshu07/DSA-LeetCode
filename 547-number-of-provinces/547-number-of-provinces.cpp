class Solution {
public:
    vector<int> friends;
    
    int find_friend(int i) {
        if(friends[i] == i)
            return i;
        return friends[i] = find_friend(friends[i]);
    }
    
    void union_friends(int i, int j) {
        i = find_friend(i);
        j = find_friend(j);
        
        if(i!=j)
            friends[j] = i;
    }
    
    int findCircleNum(vector<vector<int>>& M) {
        int n = M.size();
        int groups=0;
        friends.resize(n);

        for(int i=0;i<n;i++)
            friends[i] = i;
        
        //Since each friend is initially friend to himself (M[i][i]),
        //We will traverse only in the top right half of grid
        //Since the bottom left half is the copy of it.
        
        for(int i=0;i<n;i++) {
            for(int j=i+1;j<n;j++) {
                if(M[i][j] == 1)
                    union_friends(i,j);
            }
        }
        
        for(int i=0;i<n;i++) {
            if(friends[i] == i)
                groups++;
        }
        
        return groups;
    }
};