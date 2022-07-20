class Solution {
public:
    void setZeroes(vector<vector<int>>& m) {
        unordered_set<int>row,column;
        for(int i=0; i<m.size(); i++){
            for(int j=0; j<m[0].size(); j++){
                if(m[i][j]==0){
                    row.insert(i);
                    column.insert(j);
                }
            }
        }
         for(int i=0; i<m.size(); i++){
             if(row.find(i)!=row.end()){
                 for(int j=0; j<m[0].size(); j++){
                     m[i][j]=0;
            }
             }
            else{
                for(int j=0; j<m[0].size(); j++){
                    if(column.find(j)!=column.end()){
                     m[i][j]=0;
                 }
                }
            }
             }
    }
};