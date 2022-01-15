class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int X=0, k=capacity, count=0;
        
        for(int i=0; i<plants.size(); i++)
        {
            if(plants[i]<=capacity)
            {
                X++;
                count++;
                capacity=capacity-plants[i];
            }
            else
            {
                for(int j=X; j>0; j--)
                {
                    X--;
                    count++;
                    capacity=k;
                }
                X=X+(i+1);
                count=count+X;
                capacity=capacity-plants[i];
            }
        }
        
        return count;
    }
};